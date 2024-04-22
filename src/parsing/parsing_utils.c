/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:23:48 by jcoquard          #+#    #+#             */
/*   Updated: 2024/04/17 18:15:13 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	complete_border(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x > map->w - 1 || y > map->h - 1)
		return ;
	if (get_tile(map, x, y) == '1')
	{
		set_tile(map, x, y, '2');
		complete_border(map, x + 1, y);
		complete_border(map, x - 1, y);
		complete_border(map, x, y + 1);
		complete_border(map, x, y - 1);
	}
}

void	complete_lake(t_map *map, char *tmp_map, int x, int y)
{
	if (x < 0 || y < 0 || x > map->w - 1 || y > map->h - 1)
		return ;
	if (tmp_map[(y * (map->w + 1)) + x] == '1' || tmp_map[(y * (map->w + 1)) + x] == '0')
	{
		tmp_map[(y * (map->w + 1)) + x] = '.';
		set_tile(map, x, y, '2');
		complete_lake(map, tmp_map, x + 1, y);
		complete_lake(map, tmp_map, x - 1, y);
		complete_lake(map, tmp_map, x, y + 1);
		complete_lake(map, tmp_map, x, y - 1);
	}
	return ;
}

void	pars_lake(t_map *map, char *tmp_map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->w)
	{
		y = 0;
		while (y < map->h)
		{
			if (tmp_map[y * (map->w + 1) + x] == '0')
				complete_lake(map, tmp_map, x, y);
			y++;
		}
		x++;
	}
	return ;
}

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
	sl->nb_dogs_active =sl->nb_entities;
	sl->dogs = ft_calloc(sl->nb_entities, sizeof(t_entity));
	if (!sl->dogs)
		error(sl, ERR_MAL);
	sl->nb_entities += 2;
	sl->entities = ft_calloc(sl->nb_entities, sizeof(t_entity *));
	if (!sl->entities)
		error(sl, ERR_MAL);
	sl->entities[0] = &sl->pl;
	sl->entities[1] = &sl->bad;
	x = 1;
	while (++x < sl->nb_entities)
		sl->entities[x] = &sl->dogs[x - 2];
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
