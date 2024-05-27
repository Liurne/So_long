/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_entities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:15:17 by jcoquard          #+#    #+#             */
/*   Updated: 2024/04/28 17:59:33 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_hitbox(t_data *sl, t_entity *e)
{
	int	x;
	int	y;

	x = e->hitbox.pos.x - 1;
	while (x++ < e->hitbox.w + e->hitbox.pos.x)
	{
		y = e->hitbox.pos.y - 1;
		while (y++ < e->hitbox.h + e->hitbox.pos.y)
		{
			if (e->pos.x + x + sl->map.pos.x > 0 && e->pos.x + x
				+ sl->map.pos.x < sl->win.w && e->pos.y + y + sl->map.pos.y
				> 0 && e->pos.y + y + sl->map.pos.y < sl->win.h && (x
					== e->hitbox.pos.x || y == e->hitbox.pos.y || x == e->hitbox.w + e->hitbox.pos.x - 1
					|| y == e->hitbox.h + e->hitbox.pos.y - 1))
				put_pixel(&(sl->win.renderer), e->pos.x + x + sl->map.pos.x,
					e->pos.y + y + sl->map.pos.y, 0xFFFF0000);
		}
	}
	x = e->walkbox.pos.x - 1;
	while (x++ < e->walkbox.w + e->walkbox.pos.x)
	{
		y = e->walkbox.pos.y - 1;
		while (y++ < e->walkbox.h + e->walkbox.pos.y)
		{
			if (e->pos.x + x + sl->map.pos.x > 0 && e->pos.x + x
				+ sl->map.pos.x < sl->win.w && e->pos.y + y + sl->map.pos.y
				> 0 && e->pos.y + y + sl->map.pos.y < sl->win.h && (x
					== e->walkbox.pos.x || y == e->walkbox.pos.y || x == e->walkbox.w + e->walkbox.pos.x - 1
					|| y == e->walkbox.h + e->walkbox.pos.y - 1))
				put_pixel(&(sl->win.renderer), e->pos.x + x + sl->map.pos.x,
					e->pos.y + y + sl->map.pos.y, 0xFFFFFF00);
		}
	}
	
}

t_img	*wich_texture(t_data *sl, t_entity *e)
{
	if (e->type == PLAYER)
		return (&(sl->tex_pl[e->dir][e->frame]));
	if (e->type == CAT)
		return (&(sl->tex_cat[e->dir][e->frame]));
	else
		return (&(sl->tex_wolf[e->dir][e->frame]));
}

void	draw_entity(t_data *sl, t_entity *e)
{
	int	x;
	int	y;
	int	x_e;
	int	y_e;

	x_e = e->pos.x + sl->map.pos.x;
	x = -1;
	while (x++ < wich_texture(sl, e)->img_w -1)
	{
		y = -1;
		y_e = e->pos.y + sl->map.pos.y;
		while (x_e > 0 && x_e < sl->win.w
			&& y++ < wich_texture(sl, e)->img_h - 1)
		{
			if (get_pixel(wich_texture(sl, e), x, y) >> 24 == 0
				&& x_e > 0 && x_e < sl->win.w && y_e > 0 && y_e < sl->win.h)
				put_pixel(&(sl->win.renderer), x_e, y_e,
					transparence(get_pixel(wich_texture(sl, e), x, y),
						sl->col_sky, sl->night));
			y_e++;
		}
		x_e++;
	}
	if (sl->keys.show_hitbox)
		display_hitbox(sl, e);
}

int	find_index(t_entity **entities, int start, int end, int min)
{
	if (start > end)
		return (min);
	if (entities[start]->pos.y + entities[start]->hitbox.pos.y + entities[start]->hitbox.h
		< entities[min]->pos.y + entities[min]->hitbox.pos.y + entities[min]->hitbox.h)
		return (find_index(entities, start + 1, end, start));
	else
		return (find_index(entities, start + 1, end, min));
}

void	display_entity(t_data *sl, t_entity **mobs)
{
	t_entity	*tmp;
	int			i;
	int			j;

	i = 0;
	while (i < sl->nb_entities)
	{
		tmp = mobs[i];
		j = i;
		while (j < sl->nb_entities - 1 && tmp->pos.y + tmp->hitbox.pos.y + tmp->hitbox.h
			> mobs[j + 1]->pos.y + mobs[j + 1]->hitbox.pos.y + mobs[j + 1]->hitbox.h)
		{
			mobs[j] = mobs[j + 1];
			mobs[j + 1] = tmp;
			j++;
		}
		i++;
	}
	i = -1;
	while (i++ < sl->nb_entities - 1)
		if (mobs[i]->type != BAD || sl->is_night)
			draw_entity(sl, mobs[i]);
}
