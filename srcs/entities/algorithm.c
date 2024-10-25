/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <coquard.jules@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:54:14 by liurne            #+#    #+#             */
/*   Updated: 2024/10/15 18:44:48 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	roaming_alg(t_data *sl, t_entity *e)
{
	static unsigned int	r;

	if (!(e->delay % 100))
	{
		r += ((e->pos.x / 74 * e->pos.y / 30) / e->id);
		if (!(r % 3))
			e->inmove = 0;
		else
			e->inmove = 1;
		e->dir = (r % 4);
	}
	if (!move_entity(sl, e))
	{
		r++;
		if (!(r % 3))
			e->inmove = 0;
		else
			e->dir = (e->dir + 1) % 4;
	}
	return (0);
}

static void	jump_alg(t_data *sl, t_entity *e, unsigned int *delay)
{
	static unsigned int	jump_delay;
	static t_vec		landing;

	if (jump_delay > 80)
		jump_delay = 0;
	else
	{
		if (jump_delay == 50)
			ft_setvec(&landing, sl->pl.pos.x, sl->pl.pos.y);
		if (jump_delay == 80)
		{
			ft_setvec(&e->pos, landing.x, landing.y);
			*delay = 0;
		}
	}
	jump_delay++;
}

void	hunter_alg(t_data *sl, t_entity *e)
{
	static unsigned int	colision_delay;

	if (colision_delay < 100)
	{
		if (e->pos.y < sl->pl.pos.y)
			e->dir = 0;
		else if (e->pos.y > sl->pl.pos.y + sl->pl.hitbox.h * 0.5)
			e->dir = 1;
		if (e->dir < 2)
			colision_delay += !move_entity(sl, e);
		if (e->pos.x < sl->pl.pos.x)
			e->dir = 2;
		if (e->pos.x > sl->pl.pos.x + sl->pl.hitbox.w * 0.5)
			e->dir = 3;
		if (e->dir > 1)
			colision_delay += !move_entity(sl, e);
	}
	else
		jump_alg(sl, e, &colision_delay);
}
