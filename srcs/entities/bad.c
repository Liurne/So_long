/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:54:14 by liurne            #+#    #+#             */
/*   Updated: 2024/10/15 18:44:48 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static int	bad_in_wall(t_data *sl, t_entity *e, int x, int y)
// {
// 	int	next_x;
// 	int	next_y;
// 	int	collision;

// 	collision = 0;
// 	next_x = e->pos.x + x + e->walkbox.pos.x;
// 	next_y = e->pos.y + y + e->walkbox.pos.y;
// 	if (get_tile(&sl->map, next_x / 128, next_y / 128) != '0')
// 		collision = 1;
// 	if (get_tile(&sl->map, next_x / 128, (next_y + e->walkbox.h) / 128) != '0')
// 		collision = 1;
// 	if (get_tile(&sl->map, (next_x + e->walkbox.w) / 128, next_y / 128) != '0')
// 		collision = 1;
// 	if (get_tile(&sl->map, (next_x + e->walkbox.w) / 128,
// 			(next_y + e->walkbox.h) / 128) != '0')
// 		collision = 1;
// 	return (collision);
// }

// static int	move_bad(t_data *sl, t_entity *e, int x, int y)
// {
// 	static unsigned int	delay_col;

// 	if (!map_collision(sl, e, x, y) || delay_col > 50)
// 	{
// 		e->pos.x += x;
// 		e->pos.y += y;
// 		if (!bad_in_wall(sl, e, x, y))
// 			delay_col = 0;
// 	}
// 	else
// 		delay_col++;
// 	return (0);
// }

// static void	bad_action(t_data *sl, t_entity *e)
// {
// 	if (e->inmove && sl->pl.active)
// 	{
// 		if (e->dir == 0)
// 			move_bad(sl, e, 0, e->speed);
// 		if (e->dir == 1)
// 			move_bad(sl, e, 0, -e->speed);
// 		if (e->dir == 2)
// 			move_bad(sl, e, e->speed, 0);
// 		if (e->dir == 3)
// 			move_bad(sl, e, -e->speed, 0);
// 	}
// 	if (entity_collision(&sl->pl, e) && sl->pl.active)
// 	{
// 		sl->pl.active = 0;
// 		sl->pl.dir = 4;
// 		sl->pl.inmove = 0;
// 		sl->pl.frame = 2;
// 		e->dir = 4;
// 		e->frame = 1;
// 		ft_setvec(&sl->pl.pos, (e->pos.x + sl->pl.pos.x) * 0.5, 
// 		(e->pos.y + sl->pl.pos.y) * 0.5);
// 		ft_setvec(&e->pos, sl->pl.pos.x + 1, sl->pl.pos.y + 1);
// 		sl->time = 0;
// 		ft_putstr_fd("NIOM NIOM NIOM!!!\n You lost...\n", 1);
// 	}
// }

// void	bad_manager(t_data *sl, t_entity *e)
// {
// 	static int	time;

// 	if (time > 100 || time < 0)
// 		time = 0;
// 	if (!(time % 2) && sl->pl.active)
// 	{
// 		e->dir = 5;
// 		if (e->pos.y < sl->pl.pos.y)
// 			e->dir = 0;
// 		if (e->pos.y > sl->pl.pos.y + sl->pl.hitbox.h * 0.5)
// 			e->dir = 1;
// 		if (e->dir != 5)
// 			bad_action(sl, e);
// 		if (!sl->pl.active)
// 			return ;
// 		if (e->pos.x < sl->pl.pos.x)
// 			e->dir = 2;
// 		if (e->pos.x > sl->pl.pos.x + sl->pl.hitbox.w * 0.5)
// 			e->dir = 3;
// 		if (e->dir != 0 && e->dir != 1)
// 			bad_action(sl, e);
// 	}
// 	time++;
// }

void	bad_manager(t_data *sl, t_entity *bad)
{
	if (!bad->active)
		return ;
	hunter_alg(sl, bad);
	if (entity_collision(&sl->pl, bad) && sl->pl.active)
	{
		sl->pl.active = 0;
		sl->pl.dir = 4;
		sl->pl.inmove = 0;
		sl->pl.frame = 2;
		bad->dir = 4;
		bad->frame = 1;
		ft_setvec(&sl->pl.pos, (bad->pos.x + sl->pl.pos.x) * 0.5, \
		(bad->pos.y + sl->pl.pos.y) * 0.5);
		ft_setvec(&bad->pos, sl->pl.pos.x + 1, sl->pl.pos.y + 1);
		sl->time = 0;
		ft_putstr_fd("NIOM NIOM NIOM!!!\n You lost...\n", 1);
	}
}
