/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:53:34 by liurne            #+#    #+#             */
/*   Updated: 2024/10/15 18:54:56 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_cat(t_data *sl, t_entity *e, int x, int y)
{
	if (!map_collision(sl, e, x, y))
	{
		e->pos.x += x;
		e->pos.y += y;
	}
	else
	{
		e->dir++;
		if (e->dir > 3)
			e->dir = 0;
	}
	return (0);
}

static void	cat_pet_animation(t_entity *pl, t_entity *cat)
{
	static int	delay;
	static int	animation;

	if (delay > 8 || delay < 0)
	{
		delay = 0;
		if (!pl->inmove)
		{
			if (pl->pos.y + pl->hitbox.pos.y + pl->hitbox.h
				> cat->pos.y + cat->hitbox.pos.y + cat->hitbox.h)
				pl->dir = 1;
			else
				pl->dir = 0;
			pl->frame = (4 + (1 - (pl->frame - 4))) % 8;
		}
		if (cat->frame == 1 || !cat->frame)
			animation = 1;
		if (cat->frame >= 3)
			animation = -1;
		cat->frame += animation;
		if (cat->frame < 1 || cat->frame > 3)
			cat->frame = 1;
	}
	delay++;
}

static void	cat_pet(t_data *sl, t_entity *pl, t_entity *e)
{
	if (e->active)
	{
		ft_putstr_fd("NEED...TO...PEEEEEEEET!!\n", 1);
		sl->nb_cats_active--;
		e->active = 0;
		e->inmove = 0;
		e->dir = 4;
		e->frame = 0;
		if (!sl->is_night)
			reset_move(sl);
		pl->dir = 1;
		pl->frame = 4;
		//ft_setvec(&e->pos, (e->pos.x + pl->pos.x) * 0.5, \(e->pos.y + pl->pos.y) * 0.5);
		//ft_setvec(&pl->pos, e->pos.x + 1, e->pos.y + 1);
		if (!sl->nb_cats_active && get_tile(&sl->map, sl->map.end.x, \
			sl->map.end.y) != 'F')
		{
			set_tile(&sl->map, sl->map.end.x, sl->map.end.y, 'F');
			reload_tile_img(&sl->map, sl->map.end.x, sl->map.end.y);
			ft_putstr_fd("The house is open!!\n", 1);
		}
	}
	e->delay_pet = pl->nb_mv + sl->nb_tile;
	cat_pet_animation(pl, e);
}

static void	cat_action(t_data *sl, t_entity *e, int time)
{
	if (e->inmove && !(time % 3))
	{
		if (e->dir == 0)
			move_cat(sl, e, 0, e->speed);
		if (e->dir == 1)
			move_cat(sl, e, 0, -e->speed);
		if (e->dir == 2)
			move_cat(sl, e, e->speed, 0);
		if (e->dir == 3)
			move_cat(sl, e, -e->speed, 0);
	}
	if (entity_collision(&(sl->pl), e))
		cat_pet(sl, &sl->pl, e);
}

void	cat_manager(t_data *sl, t_entity *e)
{
	static int	r;

	if (e->active)
	{
		if (e->delay > 100)
		{
			e->delay = 0;
			r += (sl->pl.pos.x / 128 + sl->pl.pos.y / 128 + e->pos.x
					/ 128 + e->pos.y / 128 + e->id);
			if (!(r % 3))
			{
				e->inmove = 0;
				e->frame = 0;
			}
			else
				e->inmove = 1;
			e->dir = (r % 4);
		}
		cat_action(sl, e, e->delay);
	}
	else if (entity_collision(&(sl->pl), e))
		cat_pet(sl, &sl->pl, e);
	else
	{
		e->frame = 0;
		if (e->delay_pet < sl->pl.nb_mv)
			e->active = 1;
	}
	e->delay++;
}
