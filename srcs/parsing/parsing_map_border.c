/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_border.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:03:33 by liurne            #+#    #+#             */
/*   Updated: 2024/04/28 18:46:34 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	protect_ground(t_map *map, char *tmp_map, int x, int y)
{
	if (x < 0 || y < 0 || x > map->w - 1 || y > map->h - 1)
		return ;
	if (tmp_map[(y * (map->w + 1)) + x] == '0')
	{
		tmp_map[(y * (map->w + 1)) + x] = '.';
		protect_ground(map, tmp_map, x + 1, y);
		protect_ground(map, tmp_map, x - 1, y);
		protect_ground(map, tmp_map, x, y + 1);
		protect_ground(map, tmp_map, x, y - 1);
	}
}
void	complete_border(t_map *map, char *tmp_map, int x, int y)
{
	if (x < 0 || y < 0 || x > map->w - 1 || y > map->h - 1)
		return ;
	if (tmp_map[(y * (map->w + 1)) + x] == '0')
		protect_ground(map, tmp_map, x, y);
	if (get_tile(map, x, y) == '1')
	{
		set_tile(map, x, y, '2');
		complete_border(map, tmp_map, x + 1, y);
		complete_border(map, tmp_map, x - 1, y);
		complete_border(map, tmp_map, x, y + 1);
		complete_border(map, tmp_map, x, y - 1);
	}
}

static void	complete_lake(t_map *map, char *tmp_map, int x, int y)
{
	if (x < 0 || y < 0 || x > map->w - 1 || y > map->h - 1)
		return ;
	if (tmp_map[(y * (map->w + 1)) + x] == '1'
		|| tmp_map[(y * (map->w + 1)) + x] == '0')
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