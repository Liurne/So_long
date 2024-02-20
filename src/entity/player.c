/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:38:04 by liurne            #+#    #+#             */
/*   Updated: 2024/02/20 17:30:28 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_player(t_data *sl, int x, int y, int dir)
{
	sl->pl.dir = dir;
	sl->pl.inmove = 1;
	if (!map_collision(sl, &(sl->pl), x, y))
	{
		sl->pl.d += 10;
		if (sl->pl.d >= 128)
		{
			ft_putmove_fd(sl->pl.nb_mv++, 1);
			sl->pl.d = 0;
		}
		sl->pl.pos.x += x;
		sl->pl.pos.y += y;
		if (x != 0 && sl->pl.pos.x >= sl->win.w / 2 && ((sl->map.w * 128)
				- sl->pl.pos.x) > sl->win.w / 2)
			if (sl->map.pos.x - x <= 0 && sl->map.pos.x - x - sl->win.w
				>= sl->map.w * -128)
				sl->map.pos.x = -sl->pl.pos.x + sl->win.w / 2;
		if (y != 0 && sl->pl.pos.y >= sl->win.h / 2 && ((sl->map.h * 128)
				- sl->pl.pos.y) > sl->win.h / 2)
			if (sl->map.pos.y - y <= 0 && sl->map.pos.y - y - sl->win.h
				>= sl->map.h * -128)
				sl->map.pos.y = -sl->pl.pos.y + sl->win.h / 2;
	}
	return (0);
}

void	player_manager(t_data *sl)
{
	if (sl->need_pet > 110)
	{
		if (sl->keys.up)
			move_player(sl, 0, -11, 1);
		if (sl->keys.down)
			move_player(sl, 0, 11, 0);
		if (sl->keys.left)
			move_player(sl, -11, 0, 3);
		if (sl->keys.right)
			move_player(sl, 11, 0, 2);
	}
}