/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:43:59 by jcoquard          #+#    #+#             */
/*   Updated: 2024/03/27 18:22:37 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	get_tile(t_map *map, int x, int y)
{
	if (x < map->w && y < map->h && x >= 0 && y >= 0)
		return (map->map[(y * (map->w + 1)) + x]);
	return ('2');
}

int	set_tile(t_map *map, int x, int y, char c)
{
	if (x < map->w && y < map->h)
	{
		map->map[(y * (map->w + 1)) + x] = c;
		return (1);
	}
	else
		return (0);
}

void	put_pixelmap(t_map *m, int x, int y, int img)
{
	put_pixel(&(m->img), x, y, get_pixel(&(m->tex[img]), x % 128, y % 128));
}
