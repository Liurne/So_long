/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:33:33 by jcoquard          #+#    #+#             */
/*   Updated: 2024/02/20 17:30:34 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	wolf_in_wall(t_data *sl, t_entity *e, int x, int y)
{
	int	next_x;
	int	next_y;
	int	collision;

	collision = 0;
	next_x = e->pos.x + x + e->tpos.x;
	next_y = e->pos.y + y + e->tpos.y;
	if (get_tile(sl, next_x / 128, next_y / 128) != '0')
		collision = 1;
	if (get_tile(sl, next_x / 128, (next_y + e->h) / 128) != '0')
		collision = 1;
	if (get_tile(sl, (next_x + e->w) / 128, next_y / 128) != '0')
		collision = 1;
	if (get_tile(sl, (next_x + e->w) / 128, (next_y + e->h) / 128) != '0')
		collision = 1;
	return (collision);
}
static int	move_wolf(t_data *sl, t_entity *e, int x, int y)
{
	static unsigned int delay_col;

	if (!map_collision(sl, e, x, y) || delay_col > 50)
	{
		e->pos.x += x;
		e->pos.y += y;
		if (!wolf_in_wall(sl, e, x, y))
			delay_col = 0;
	}
	else
		delay_col++;
	return (0);
}

static void	wolf_action(t_data *sl, t_entity *e)
{
	if (e->inmove && sl->pl.alive)
	{
		if (e->dir == 0)
			move_wolf(sl, e, 0, 14);
		if (e->dir == 1)
			move_wolf(sl, e, 0, -14);
		if (e->dir == 2)
			move_wolf(sl, e, 14, 0);
		if (e->dir == 3)
			move_wolf(sl, e, -14, 0);
	}
	if (entity_collision(&(sl->pl), e) && sl->pl.alive)
	{
		sl->pl.alive = 0;
		e->inmove = 0;
		e->dir = 4;
		e->animation = 1;
		sl->pl.dir = 4;
		sl->pl.pos.x = e->pos.x;
		sl->pl.pos.y = e->pos.y;
		sl->pl.animation = 1;
		sl->time = 0;
		ft_putstr_fd("NIOM NIOM NIOM!!!\n You lost...\n", 1);
	}
}

void	wolf_manager(t_data *sl, t_entity *e)
{
	static int	time;

	if (time > 100)
		time = 0;
	if (!(time % 2) && sl->pl.alive)
	{
		e->dir = 5;
		if (e->pos.y < sl->pl.pos.y)
			e->dir = 0;
		if (e->pos.y > sl->pl.pos.y + sl->pl.h / 2)
			e->dir = 1;
		if (e->dir != 5)
			wolf_action(sl, e);
		if (!sl->pl.alive)
			return;
		if (e->pos.x < sl->pl.pos.x)
			e->dir = 2;
		if (e->pos.x > sl->pl.pos.x + sl->pl.w / 2)
			e->dir = 3;
		if (e->dir != 0 && e->dir !=1)
			wolf_action(sl, e);
	}
	time++;
}
