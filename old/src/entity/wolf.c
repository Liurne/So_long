/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:33:33 by jcoquard          #+#    #+#             */
/*   Updated: 2024/02/20 18:08:33 by jcoquard         ###   ########.fr       */
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
	if (e->inmove && sl->entities[0].alive)
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
	if (entity_collision(&(sl->entities[0]), e) && sl->entities[0].alive)
	{
		sl->entities[0].alive = 0;
		e->inmove = 0;
		e->dir = 4;
		e->animation = 1;
		sl->entities[0].dir = 4;
		sl->entities[0].pos.x = e->pos.x;
		sl->entities[0].pos.y = e->pos.y;
		sl->entities[0].animation = 1;
		sl->time = 0;
		ft_putstr_fd("NIOM NIOM NIOM!!!\n You lost...\n", 1);
	}
}

void	wolf_manager(t_data *sl, t_entity *e)
{
	static int	time;

	if (time > 100)
		time = 0;
	if (!(time % 2) && sl->entities[0].alive)
	{
		e->dir = 5;
		if (e->pos.y < sl->entities[0].pos.y)
			e->dir = 0;
		if (e->pos.y > sl->entities[0].pos.y + sl->entities[0].h / 2)
			e->dir = 1;
		if (e->dir != 5)
			wolf_action(sl, e);
		if (!sl->entities[0].alive)
			return;
		if (e->pos.x < sl->entities[0].pos.x)
			e->dir = 2;
		if (e->pos.x > sl->entities[0].pos.x + sl->entities[0].w / 2)
			e->dir = 3;
		if (e->dir != 0 && e->dir !=1)
			wolf_action(sl, e);
	}
	time++;
}
