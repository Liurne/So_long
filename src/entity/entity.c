/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:35:48 by jcoquard          #+#    #+#             */
/*   Updated: 2024/03/27 00:46:52 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	entity_collision(t_entity *e1, t_entity *e2)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = e1->pos.x + e1->tpos.x;
	y1 = e1->pos.y + e1->tpos.y;
	x2 = e2->pos.x + e1->tpos.x;
	y2 = e2->pos.y + e1->tpos.y;
	if ((x1 >= x2 && x1 < x2 + e2->h && y1 >= y2 && y1 < y2 + e2->h)
		|| (x1 >= x2 && x1 < x2 + e2->h && y1 >= y2 && y1 < y2 + e2->h)
		|| (x1 + e1->w >= x2 && x1 + e1->w < x2 + e2->w && y1 >= y2 && y1
			< y2 + e2->h) || (x1 + e1->w >= x2 && x1 + e1->w < x2 + e2->w && y1
			+ e1->h >= y2 && y1 + e1->h < y2 + e2->h))
		return (1);
	if ((x2 >= x1 && x2 < x1 + e1->h && y2 >= y1 && y2 < y1 + e1->h)
		|| (x2 >= x1 && x2 < x1 + e1->h && y2 >= y1 && y2 < y1 + e1->h)
		|| (x2 + e2->w >= x1 && x2 + e2->w < x1 + e1->w && y2 >= y1 && y2
			< y1 + e1->h) || (x2 + e2->w >= x1 && x2 + e2->w < x1 + e1->w && y2
			+ e2->h >= y1 && y2 + e2->h < y1 + e1->h))
		return (1);
	return (0);
}

static int	collision_action(t_data *sl, t_entity *e, int x, int y)
{
	char tile;

	tile = get_tile(sl, x, y);
	if (e->type == PLAYER)
	{
		if (tile == 'F')
		{
			ft_putstr_fd("You Won !!\n", 1);
			close_window(sl);
		}
	}
	if (tile == '1' || tile == '2' || tile == 'E')
		return (1);
	return (0);
}

int	map_collision(t_data *sl, t_entity *e, int x, int y)
{
	int	next_x;
	int	next_y;
	int	collision;

	collision = 0;
	next_x = e->pos.x + x + e->tpos.x;
	next_y = e->pos.y + y + e->tpos.y;
	if (get_tile(sl, next_x / 128, next_y / 128) != '0')
		collision += collision_action(sl, e, next_x / 128, next_y / 128);
	if (get_tile(sl, next_x / 128, (next_y + e->h) / 128) != '0')
		collision += collision_action(sl, e, next_x / 128, (next_y + e->h)
				/ 128);
	if (get_tile(sl, (next_x + e->w) / 128, next_y / 128) != '0')
		collision += collision_action(sl, e, (next_x + e->w) / 128, next_y
				/ 128);
	if (get_tile(sl, (next_x + e->w) / 128, (next_y + e->h) / 128) != '0')
		collision += collision_action(sl, e, (next_x + e->w) / 128,
				(next_y + e->h) / 128);
	return (collision);
}
