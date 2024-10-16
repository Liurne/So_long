/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:49:13 by liurne            #+#    #+#             */
/*   Updated: 2024/04/26 23:12:37 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	entity_collision(t_entity *e1, t_entity *e2)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = e1->pos.x + e1->hitbox.pos.x;
	y1 = e1->pos.y + e1->hitbox.pos.y;
	x2 = e2->pos.x + e2->hitbox.pos.x;
	y2 = e2->pos.y + e2->hitbox.pos.y;

	if (x1 > x2 + e2->hitbox.w || x1 + e1->hitbox.w < x2 || y1 > y2 + e2->hitbox.h || y1 + e1->hitbox.h < y2)
		return (0);
	return (1);
}

static int	collision_action(t_data *sl, t_entity *e, int x, int y)
{
	char	tile;

	tile = get_tile(&sl->map, x, y);
	if (e->type == PLAYER)
	{
		if (tile == 'F')
		{
			ft_putstr_fd("You Won !!\n", 1);
			close_window(sl);
		}
	}
	if (tile == '1' || tile == '2' || (tile == 'E'
			&& (e->type == PLAYER || e->type == CAT)))
		return (1);
	return (0);
}

int	move_entity(t_data *sl, t_entity *e)
{
	t_vec	dir;

	if (e->inmove && !(e->delay % 3))
	{
		if (e->dir == 0)
			ft_setvec(&dir, 0, e->speed);
		if (e->dir == 1)
			ft_setvec(&dir, 0, -e->speed);
		if (e->dir == 2)
			ft_setvec(&dir, e->speed, 0);
		if (e->dir == 3)
			ft_setvec(&dir, -e->speed, 0);
		if (!map_collision(sl, e, dir.x, dir.y))
		{
			e->pos.x += dir.x;
			e->pos.y += dir.y;
		}
		else
			return (0);
	}
	return (1);
}

int	map_collision(t_data *sl, t_entity *e, int x, int y)
{
	int	next_x;
	int	next_y;
	int	collision;

	collision = 0;
	next_x = e->pos.x + x + e->walkbox.pos.x;
	next_y = e->pos.y + y + e->walkbox.pos.y;
	if (get_tile(&sl->map, next_x / 128, next_y / 128) != '0')
		collision += collision_action(sl, e, next_x / 128, next_y / 128);
	if (get_tile(&sl->map, next_x / 128, (next_y + e->walkbox.h) / 128) != '0')
		collision += collision_action(sl, e, next_x / 128, (next_y + e->walkbox.h)
				/ 128);
	if (get_tile(&sl->map, (next_x + e->walkbox.w) / 128, next_y / 128) != '0')
		collision += collision_action(sl, e, (next_x + e->walkbox.w) / 128, next_y
				/ 128);
	if (get_tile(&sl->map, (next_x + e->walkbox.w) / 128, (next_y + e->walkbox.h) / 128) != '0')
		collision += collision_action(sl, e, (next_x + e->walkbox.w) / 128,
				(next_y + e->walkbox.h) / 128);
	return (collision);
}

