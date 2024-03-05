/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:58:03 by jcoquard          #+#    #+#             */
/*   Updated: 2024/03/05 18:31:25 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	is_still_dog(t_data *sl)
{
	int	i;

	i = 0;
	while (i < sl->nb_dogs)
	{
		if (sl->dogs[i].active)
			return (1);
		i++;
	}
	return (0);
}

int	move_dog(t_data *sl, t_entity *e, int x, int y)
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

void	dog_pet(t_data *sl, t_entity *pl, t_entity *e)
{
	if (e->active)
	{
		ft_putstr_fd("NEED...TO...PEEEEEEEET!!\n", 1);
		e->active = 0;
		e->inmove = 0;
		e->dir = 4;
		e->animation = 0;
		ft_setvec(&e->pos, (e->pos.x + pl->pos.x) * 0.5, \
			(e->pos.y + pl->pos.y) * 0.5);
		ft_setvec(&pl->pos, e->pos.x + 1, e->pos.y + 1);
		if (!sl->is_night)
			reset_move(sl);
		if (!is_still_dog(sl) && get_tile(sl, sl->map.end.x, sl->map.end.y) \
			!= 'F')
		{
			set_tile(sl, sl->map.end.x, sl->map.end.y, 'F');
			reload_tile_img(sl, sl->map.end.x * 128, sl->map.end.y * 128);
		}
	}
	pl->dir = 4;
	pl->animation = 0;
	pl->inmove = 0;
}

void	dog_action(t_data *sl, t_entity *e, int time)
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

void	dog_manager(t_data *sl, t_entity *e)
{
	static int	r;

	if (e->active)
	{
		if (e->delay > 100)
		{
			e->delay = 0;
			r += (sl->pl.pos.x + sl->pl.pos.y + sl->pl.dist + sl->time + e->id);
			if (!(r % 3))
				e->inmove = 0;
			else
				e->inmove = 1;
			e->dir = (r % 4);
		}
		dog_action(sl, e, e->delay);
	}
	else if (entity_collision(&(sl->pl), e))
		dog_pet(sl, &sl->pl, e);
	e->delay++;
}
