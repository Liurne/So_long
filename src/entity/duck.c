/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duck.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:36:26 by liurne            #+#    #+#             */
/*   Updated: 2024/03/25 16:39:35 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	duck_collision(t_data *sl, t_entity *e, int x, int y)
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

static int	duck_move(t_data *sl, t_entity *e, int x, int y)
{
	if (!duck_collision(sl, e, x, y))
	{
		e->pos.x += x;
		e->pos.y += y;
	}
	else
	{
		e->dir++;
		if (e->dir > 3)
			e->dir = 0;
	}
	return (0);
}

static void	duck_action(t_data *sl, t_entity *e, int time)
{
	if (e->inmove && !(time % 3))
	{
		if (e->dir == 0)
			move_dog(sl, e, 0, 10);
		if (e->dir == 1)
			move_dog(sl, e, 0, -10);
		if (e->dir == 2)
			move_dog(sl, e, 10, 0);
		if (e->dir == 3)
			move_dog(sl, e, -10, 0);
	}
	if (entity_collision(&(sl->pl), e))
		dog_pet(sl, &sl->pl, e);
}

void	duck_manager(t_data *sl, t_entity *e)
{
	static int	r;

	if (e->active)
	{
		if (e->delay > 100)
		{
			e->delay = 0;
			r += (sl->pl.pos.x / 128 + sl->pl.pos.y / 128 + e->pos.x / 128 + e->pos.y / 128 + e->id);
			if (!(r % 3))
				e->inmove = 0;
			else
				e->inmove = 1;
			e->dir = (r % 4);
		}
		dog_action(sl, e, e->delay);
	}
	e->delay++;
}