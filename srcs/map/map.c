/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:40:10 by liurne            #+#    #+#             */
/*   Updated: 2024/04/26 21:58:27 by liurne           ###   ########.fr       */
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

void	refresh_end(t_data *sl)
{
	if (!sl->nb_cats_active && get_tile(&sl->map, sl->map.end.x, \
			sl->map.end.y) != 'F')
	{
		set_tile(&sl->map, sl->map.end.x, sl->map.end.y, 'F');
		reload_tile_img(&sl->map, sl->map.end.x, sl->map.end.y);
		ft_putstr_fd("The house is open!!\n", 1);
	}
}
