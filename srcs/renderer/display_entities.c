/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_entities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:15:17 by jcoquard          #+#    #+#             */
/*   Updated: 2024/10/15 18:39:27 by jcoquard         ###   ########.fr       */
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
	t_vec	inc;
	t_vec	pos;
	t_img	*sprite;
	int		pixel;

	sprite = wich_texture(sl, e);
	pos.x = e->pos.x + sl->map.pos.x;
	inc.x = -1;
	while (inc.x++ < sprite->img_w -1)
	{
		inc.y = -1;
		pos.y = e->pos.y + sl->map.pos.y;
		while (pos.x > 0 && pos.x < sl->win.w && inc.y++ < sprite->img_h - 1)
		{
			pixel = get_pixel(sprite, inc.x, inc.y);
			if (pixel >> 24 == 0 && pos.x > 0 && pos.x < sl->win.w
				&& pos.y > 0 && pos.y < sl->win.h)
				put_pixel(&(sl->win.renderer), pos.x, pos.y,
					transparence(pixel, sl->col_sky, sl->night));
			pos.y++;
		}
		pos.x++;
	}
	if (sl->keys.show_hitbox)
		display_hitbox(sl, e);
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
