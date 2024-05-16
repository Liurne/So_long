/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:33:10 by liurne            #+#    #+#             */
/*   Updated: 2024/04/26 22:16:31 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dog_alloc(t_data *sl)
{
	int	x;
	int	y;

	x = -1;
	while (++x < sl->map.w)
	{
		y = -1;
		while (++y < sl->map.h)
			if (get_tile(&sl->map, x, y) == 'C')
				sl->nb_entities++;
	}
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
	x = 1;
	while (++x < sl->nb_entities)
		sl->entities[x] = &sl->cats[x - 2];
}

int	is_still(char *map)
{
	while (*map)
	{
		if (*map == 'E' || *map == 'C')
			return (1);
		map++;
	}
	return (0);
}
