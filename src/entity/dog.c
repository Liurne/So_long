/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:58:03 by jcoquard          #+#    #+#             */
/*   Updated: 2024/04/24 00:31:23 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_dog(t_data *sl, t_entity *e, int x, int y)
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

static void	dog_pet_animation(t_entity *pl, t_entity *dog)
{
	static int	delay;
	static int	animation;

	if (delay > 8 || delay < 0)
	{
		delay = 0;
		if (!pl->inmove)
		{
			if (dog->pos.y + dog->tpos.y + dog->h < pl->pos.y + pl->tpos.y + pl->h)
				pl->dir = 1;
			else
				pl->dir = 0;
			if (pl->animation < 4)
				pl->animation = 4;
			pl->animation = 4 + (1 - (pl->animation - 4));
		}
		if (dog->animation == 1 || !dog->animation)
			animation = 1;
		if (dog->animation >= 3)
			animation = -1;
		dog->animation += animation;
		if (dog->animation < 1 || dog->animation > 3)
			dog->animation = 1;
	}
	delay++;
}

static void	dog_pet(t_data *sl, t_entity *pl, t_entity *e)
{
	if (e->active)
	{
		ft_putstr_fd("NEED...TO...PEEEEEEEET!!\n", 1);
		sl->nb_dogs_active--;
		e->active = 0;
		e->inmove = 0;
		e->dir = 4;
		e->animation = 0;
		if (!sl->is_night)
			reset_move(sl);
		pl->dir = 1;
		pl->animation = 4;
		ft_setvec(&e->pos, (e->pos.x + pl->pos.x) * 0.5, \
			(e->pos.y + pl->pos.y) * 0.5);
		ft_setvec(&pl->pos, e->pos.x + 1, e->pos.y + 1);
		if (!sl->nb_dogs_active && get_tile(&sl->map, sl->map.end.x, \
			sl->map.end.y) != 'F')
		{
			set_tile(&sl->map, sl->map.end.x, sl->map.end.y, 'F');
			reload_tile_img(&sl->map, sl->map.end.x, sl->map.end.y);
			ft_putstr_fd("The house is open!!\n", 1);
		}
	}
	dog_pet_animation(pl, e);
}

static void	dog_action(t_data *sl, t_entity *e, int time)
{
	if (e->inmove && !(time % 3))
	{
		if (e->dir == 0)
			move_dog(sl, e, 0, 10);
		if (e->dir == 1)
			move_dog(sl, e, 0, -10);
		if (e->dir == 2)
			move_dog(sl, e, 10, 0);
		if (e->dir == 3)
			move_dog(sl, e, -10, 0);
	}
	if (entity_collision(&(sl->pl), e))
		dog_pet(sl, &sl->pl, e);
}

void	dog_manager(t_data *sl, t_entity *e)
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
				e->animation = 0;
			}
			else
				e->inmove = 1;
			e->dir = (r % 4);
		}
		dog_action(sl, e, e->delay);
	}
	else if (entity_collision(&(sl->pl), e))
		dog_pet(sl, &sl->pl, e);
	else
		e->animation = 0;
	e->delay++;
}
