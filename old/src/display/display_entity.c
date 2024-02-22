/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_entity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:15:17 by jcoquard          #+#    #+#             */
/*   Updated: 2024/02/20 18:08:09 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_hitbox(t_data *sl, t_entity *e)
{
	int	x;
	int	y;

	x = e->tpos.x - 1;
	while (x++ < e->w + e->tpos.x)
	{
		y = e->tpos.y - 1;
		while (y++ < e->h + e->tpos.y)
		{
			if (e->pos.x + x + sl->map.pos.x > 0 && e->pos.x + x
				+ sl->map.pos.x < sl->win.w && e->pos.y + y + sl->map.pos.y
				> 0 && e->pos.y + y + sl->map.pos.y < sl->win.h && (x
					== e->tpos.x || y == e->tpos.y || x == e->w + e->tpos.x - 1
					|| y == e->h + e->tpos.y - 1))
				put_pixel(&(sl->win.renderer), e->pos.x + x + sl->map.pos.x,
					e->pos.y + y + sl->map.pos.y, 0xFFFF0000);
		}
	}
}

static t_img	*wich_texture(t_data *sl, t_entity *e)
{
	if (e->type == PLAYER)
		return (&(sl->tex_pl[e->dir][e->animation]));
	if (e->type == DOG)
		return (&(sl->tex_dog[e->dir][e->animation]));
	else
		return (&(sl->tex_wolf[e->dir][e->animation]));
}

void	display_entity(t_data *sl, t_entity *e)
{
	int	x;
	int	y;

	x = -1;
	while (x++ < wich_texture(sl, e)->img_w -1)
	{
		y = -1;
		while (y++ < wich_texture(sl, e)->img_h - 1)
		{
			if (get_pixel(wich_texture(sl, e), x, y) >> 24 == 0
				&& e->pos.x + x + sl->map.pos.x > 0 && e->pos.x + x
				+ sl->map.pos.x < sl->win.w && e->pos.y + y + sl->map.pos.y
				> 0 && e->pos.y + y + sl->map.pos.y < sl->win.h)
				put_pixel(&(sl->win.renderer), e->pos.x + x + sl->map.pos.x,
					e->pos.y + y + sl->map.pos.y, transparence(get_pixel(
							wich_texture(sl, e), x, y),
						C_NIGHT, sl->trans));
		}
	}
	if (sl->show_hitbox)
		display_hitbox(sl, e);
}

void	animation(t_data *sl)
{
	int	i;

	i = -1;
	while(++i < NB_DOG + 2)
	{
		if (!sl->entities[i].inmove)
			sl->entities[i].animation = 0;
		if (sl->entities[i].inmove && sl->time >= 7)
			sl->entities[i].animation = (sl->entities[i].animation + 1) % 4;
	}
	if (sl->time >= 7)
		sl->time = 0;
	++sl->time;
}
