/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_entities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:42:34 by liurne            #+#    #+#             */
/*   Updated: 2024/04/26 23:24:54 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pars_entity(t_data *sl, char tile, int x, int y)
{
	if (tile == 'P')
	{
		ft_setvec(&sl->map.start, x, y);
		init_pl(&sl->pl, x, y);
		update_cam(&sl->win, &sl->pl, &sl->map);
		set_tile(&sl->map, x, y, '0');
	}
	if (tile == 'E')
	{
		ft_setvec(&sl->map.end, x, y);
		init_bad(&sl->bad, x, y);
	}
	if (tile == 'C')
	{
		sl->nb_cats++;
		init_cat(&sl->cats[sl->nb_cats - 1], x, y, sl->nb_cats);
	}
}

void	entities_alloc(t_data *sl, int nb_entities)
{
	int	i;

	sl->nb_entities = nb_entities;
	sl->nb_cats_active = sl->nb_entities;
	sl->cats = ft_calloc(sl->nb_entities, sizeof(t_entity));
	if (!sl->cats)
		error(sl, ERR_MAL);
	sl->nb_entities += 2;
	sl->entities = ft_calloc(sl->nb_entities, sizeof(t_entity *));
	if (!sl->entities)
		error(sl, ERR_MAL);
	sl->entities[0] = &sl->pl;
	sl->entities[1] = &sl->bad;
	i = 1;
	while (++i < sl->nb_entities)
		sl->entities[i] = &sl->cats[i - 2];
}
