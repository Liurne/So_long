/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:58:03 by jcoquard          #+#    #+#             */
/*   Updated: 2024/02/23 23:39:18 by liurne           ###   ########.fr       */
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

static void	dog_pet(t_data *sl, t_entity *pl, t_entity *e)
{
	ft_putstr_fd("NEED...TO...PEEEEEEEET!!\n", 1);
	ft_putstr_fd("Time is passing...\n", 1);
	e->delay = 0;
	e->inmove = 0;
	e->dir = 4;
	e->animation = 0;
	ft_setvec(&e->pos, (e->pos.x + pl->pos.x) * 0.5, \
		(e->pos.y + pl->pos.y) * 0.5);
	ft_setvec(&pl->pos, e->pos.x, e->pos.y);
	reset_move(sl);
	pl->nb_mv += (int)(sl->nb_tile * (0.1));
	pl->dir = 4;
	pl->animation = 0;
	pl->inmove = 0;
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
	if (entity_collision(&(sl->pl), e) && e->delay >= 175)
		dog_pet(sl, &sl->pl, e);
}

void	dog_manager(t_data *sl, t_entity *e)
{
	static int	time;
	static int	r;

	if (sl->pl.delay > 150 && e->alive)
	{
		if (time > 100)
		{
			time = 0;
			r += (sl->pl.pos.x + sl->pl.pos.y + sl->pl.dist + sl->time + e->id);
			if (!(r % 3))
				e->inmove = 0;
			else
				e->inmove = 1;
			e->dir = (r % 4);
		}
		if (sl->pl.delay < 175 && e->id == 1 && time % 8)
			sl->pl.delay++;
		dog_action(sl, e, time);
	}
	else if (e->id == 0)
		sl->pl.delay++;
	time++;
}
