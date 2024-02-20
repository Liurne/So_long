/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:38:04 by liurne            #+#    #+#             */
/*   Updated: 2024/02/20 18:08:30 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_player(t_data *sl, int x, int y, int dir)
{
	sl->entities[0].dir = dir;
	sl->entities[0].inmove = 1;
	if (!map_collision(sl, &(sl->entities[0]), x, y))
	{
		sl->entities[0].dist += 10;
		if (sl->entities[0].dist >= 128)
		{
			ft_putmove_fd(sl->entities[0].nb_mv++, 1);
			sl->entities[0].dist = 0;
		}
		sl->entities[0].pos.x += x;
		sl->entities[0].pos.y += y;
		if (x != 0 && sl->entities[0].pos.x >= sl->win.w / 2 && ((sl->map.w * 128)
				- sl->entities[0].pos.x) > sl->win.w / 2)
			if (sl->map.pos.x - x <= 0 && sl->map.pos.x - x - sl->win.w
				>= sl->map.w * -128)
				sl->map.pos.x = -sl->entities[0].pos.x + sl->win.w / 2;
		if (y != 0 && sl->entities[0].pos.y >= sl->win.h / 2 && ((sl->map.h * 128)
				- sl->entities[0].pos.y) > sl->win.h / 2)
			if (sl->map.pos.y - y <= 0 && sl->map.pos.y - y - sl->win.h
				>= sl->map.h * -128)
				sl->map.pos.y = -sl->entities[0].pos.y + sl->win.h / 2;
	}
	return (0);
}

void	player_manager(t_data *sl)
{
	if (sl->entities[0].delay > 110)
	{
		if (sl->keys.up)
			move_player(sl, 0, -11, 1);
		if (sl->keys.down)
			move_player(sl, 0, 11, 0);
		if (sl->keys.left)
			move_player(sl, -11, 0, 3);
		if (sl->keys.right)
			move_player(sl, 11, 0, 2);
		if (!sl->keys.up && !sl->keys.down && !sl->keys.left
				&& !sl->keys.right)
			sl->entities[0].inmove = 0;
	}
}