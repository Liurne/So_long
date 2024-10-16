/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:53:34 by liurne            #+#    #+#             */
/*   Updated: 2024/10/15 18:54:56 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	cat_pet(t_data *sl, t_entity *pl, t_entity *cat)
{
	static unsigned int	delay;

	if (cat->active)
	{
		ft_putstr_fd("NEED...TO...PEEEEEEEET!!\n", 1);
		sl->nb_cats_active--;
		cat->active = 0;
		cat->inmove = 0;
		cat->dir = 4;
		cat->frame = 0;
		if (!sl->is_night)
			reset_move(sl);
		refresh_end(sl);
	}
	cat->delay_pet = pl->nb_mv + sl->nb_tile;
	pl->collision_entity = cat->id;
	if (!(delay % 8))
		cat->frame = (cat->frame % 3) + 1;
	delay++;
}

void	cat_manager(t_data *sl, t_entity *cat)
{
	if (cat->active)
	{
		roaming_alg(sl, cat);
		if (!cat->inmove)
			cat->frame = 0;
	}
	if (entity_collision(&(sl->pl), cat))
		cat_pet(sl, &sl->pl, cat);
	else
	{
		cat->frame = 0;
		if (!cat->active && cat->delay_pet < sl->pl.nb_mv)
		{
			cat->active = 1;
			sl->nb_cats_active++;
		}
	}
	cat->delay++;
}
