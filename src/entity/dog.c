/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:58:03 by jcoquard          #+#    #+#             */
/*   Updated: 2024/02/20 18:08:20 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_dog(t_data *sl, t_entity *e, int x, int y)
{
	if (!map_collision(sl, e, x, y))
	{
		e->pos.x += x;
		e->pos.y += y;
	}
	else
	{
		e->dir += 2;
		if (e->dir > 3)
			e->dir -= 4;
	}
	return (0);
}

static void	dog_pet(t_data *sl, t_entity *e)
{
	ft_putstr_fd("NEED...TO...PEEEEEEEET!!\n", 1);
	ft_putstr_fd("Time is passing...\n", 1);
	sl->entities[0].delay = 0;
	e->inmove = 0;
	e->dir = 4;
	e->animation = 0;
	e->pos.x = sl->entities[0].pos.x;
	e->pos.y = sl->entities[0].pos.y;
	sl->entities[0].nb_mv += (int)(sl->nb_case * (0.1));
	sl->entities[0].dir = 4;
	sl->entities[0].animation = 0;
	sl->entities[0].inmove = 0;
}

static void	dog_action(t_data *sl, t_entity *e, int time)
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
	if (entity_collision(&(sl->entities[0]), e) && sl->entities[0].delay >= 175)
		dog_pet(sl, e);
}

void	dog_manager(t_data *sl, t_entity *e)
{
	static int	time;
	static int	r;

	if (sl->entities[0].delay > 150 && e->alive)
	{
		if (time > 100)
		{
			time = 0;
			r += (sl->entities[0].pos.x + sl->entities[0].pos.y + sl->entities[0].dist + sl->time + e->id);
			if (!(r % 3))
				e->inmove = 0;
			else
				e->inmove = 1;
			e->dir = (r % 4);
		}
		if (sl->entities[0].delay < 175 && e->id == 1 && time % 8)
			sl->entities[0].delay++;
		dog_action(sl, e, time);
	}
	else if (e->id == 0)
		sl->entities[0].delay++;
	time++;
}
