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
