/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_img_border1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 03:32:30 by liurne            #+#    #+#             */
/*   Updated: 2024/03/27 18:45:19 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*fborder1(t_map *map, int x, int y)
{
	if (get_tile(map, x + 1, y) == '2')
		return (&map->tex[32]);
	else if (get_tile(map, x - 1, y) == '2')
		return (&map->tex[31]);
	else if (get_tile(map, x, y + 1) == '2')
		return (&map->tex[30]);
	else if (get_tile(map, x, y - 1) == '2')
		return (&map->tex[33]);
	return (&map->tex[18]);
}

t_img	*fborder2(t_map *map, int x, int y)
{
	if (get_tile(map, x + 1, y) == '2' && get_tile(map, x - 1, y) == '2')
		return (&map->tex[17]);
	else if (get_tile(map, x, y + 1) == '2' && get_tile(map, x, y - 1) == '2')
		return (&map->tex[18]);
	else if (get_tile(map, x + 1, y) == '2' && get_tile(map, x, y - 1) == '2'
		&& get_tile(map, x + 1, y - 1) == '2')
		return (&map->tex[22]);
	else if (get_tile(map, x + 1, y) == '2' && get_tile(map, x, y + 1) == '2'
		&& get_tile(map, x + 1, y + 1) == '2')
		return (&map->tex[21]);
	else if (get_tile(map, x - 1, y) == '2' && get_tile(map, x, y + 1) == '2'
		&& get_tile(map, x - 1, y + 1) == '2')
		return (&map->tex[19]);
	else if (get_tile(map, x - 1, y) == '2' && get_tile(map, x, y - 1) == '2'
		&& get_tile(map, x - 1, y - 1) == '2')
		return (&map->tex[20]);
	else if (get_tile(map, x + 1, y) == '2' && get_tile(map, x, y + 1) == '2')
		return (&map->tex[41]);
	else if (get_tile(map, x + 1, y) == '2' && get_tile(map, x, y - 1) == '2')
		return (&map->tex[39]);
	else if (get_tile(map, x - 1, y) == '2' && get_tile(map, x, y + 1) == '2')
		return (&map->tex[40]);
	else if (get_tile(map, x - 1, y) == '2' && get_tile(map, x, y - 1) == '2')
		return (&map->tex[38]);
	return (&map->tex[0]);
}

t_img	*fborder3(t_map *map, int x, int y)
{
	if (get_tile(map, x + 1, y) == '2' && get_tile(map, x - 1, y) == '2' && get_tile(map, x, y + 1) == '2')
	{
		if (get_tile(map, x + 1, y + 1) != '2' && get_tile(map, x - 1, y + 1) != '2')
			return (&map->tex[42]);
		else if (get_tile(map, x + 1, y + 1) != '2')
			return (&map->tex[46]);
		else if (get_tile(map, x - 1, y + 1) != '2')
			return (&map->tex[47]);
		else
			return (&map->tex[9]);
	}
	else if (get_tile(map, x + 1, y) == '2' && get_tile(map, x - 1, y) == '2' && get_tile(map, x, y - 1) == '2')
	{
		if (get_tile(map, x + 1, y - 1) != '2' && get_tile(map, x - 1, y - 1) != '2')
			return (&map->tex[43]);
		else if (get_tile(map, x + 1, y - 1) != '2')
			return (&map->tex[48]);
		else if (get_tile(map, x - 1, y - 1) != '2')
			return (&map->tex[53]);
		else
			return (&map->tex[10]);
	}
	else if (get_tile(map, x, y + 1) == '2' && get_tile(map, x, y - 1) == '2' && get_tile(map, x + 1, y) == '2')
	{
		if (get_tile(map, x + 1, y + 1) != '2' && get_tile(map, x + 1, y - 1) != '2')
			return (&map->tex[45]);
		else if (get_tile(map, x + 1, y + 1) != '2')
			return (&map->tex[50]);
		else if (get_tile(map, x + 1, y - 1) != '2')
			return (&map->tex[51]);
		else
			return (&map->tex[12]);
	}
	else if (get_tile(map, x, y + 1) == '2' && get_tile(map, x, y - 1) == '2' && get_tile(map, x - 1, y) == '2')
	{
		if (get_tile(map, x - 1, y + 1) != '2' && get_tile(map, x - 1, y - 1) != '2')
			return (&map->tex[44]);
		else if (get_tile(map, x - 1, y + 1) != '2')
			return (&map->tex[48]);
		else if (get_tile(map, x - 1, y - 1) != '2')
			return (&map->tex[49]);
		else
			return (&map->tex[11]);
	}
	return (&map->tex[0]);
}

t_img	*fborder4(t_map *map, int x, int y)
{
	int	wall;

	wall = how_many_border(map, x, y);
	if (wall == 7)
	{
		if (get_tile(map, x + 1, y+ 1) != '2')
			return (&map->tex[15]);
		else if (get_tile(map, x - 1, y - 1) != '2')
			return (&map->tex[13]);
		else if (get_tile(map, x -1, y + 1) != '2')
			return (&map->tex[16]);
		else if (get_tile(map, x + 1, y - 1) != '2')
			return (&map->tex[14]);
	}
	else if (wall == 6)
	{
		if (get_tile(map, x + 1, y + 1) == '2' && get_tile(map, x - 1, y - 1) == '2')
			return (&map->tex[24]);
		else if (get_tile(map, x + 1, y - 1) == '2' && get_tile(map, x - 1, y + 1) == '2')
			return (&map->tex[25]);
		else if (get_tile(map, x + 1, y - 1) == '2' && get_tile(map, x - 1, y - 1) == '2')
			return (&map->tex[37]);
		else if (get_tile(map, x + 1, y + 1) == '2' && get_tile(map, x - 1, y + 1) == '2')
			return (&map->tex[34]);
		else if (get_tile(map, x + 1, y + 1) == '2' && get_tile(map, x + 1, y - 1) == '2')
			return (&map->tex[36]);
		else if (get_tile(map, x - 1, y + 1) == '2' && get_tile(map, x - 1, y - 1) == '2')
			return (&map->tex[35]);
	}
	else if (wall == 5)
	{
		if (get_tile(map, x + 1, y + 1) == '2')
			return (&map->tex[29]);
		else if (get_tile(map, x + 1, y - 1) == '2')
			return (&map->tex[27]);
		else if (get_tile(map, x - 1, y + 1) == '2')
			return (&map->tex[28]);
		else if (get_tile(map, x - 1, y - 1) == '2')
			return (&map->tex[26]);
	}
	return (&map->tex[0]);
}

t_img	*which_border(t_map *map, int x, int y)
{
	int	fwall;
	int	wall;

	fwall = how_many_fborder(map, x, y);
	wall = how_many_border(map, x, y);
	if (fwall == 1)
		return(fborder1(map, x, y));
	else if	(fwall == 2)
		return(fborder2(map, x, y));
	else if	(fwall == 3)
		return(fborder3(map, x, y));
	else if (fwall == 4 && wall == 4)
		return (&map->tex[54]);
	else if (wall == 8)
		return (&map->tex[0]);
	else
		return(fborder4(map, x, y));
}
