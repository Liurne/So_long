/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_border_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:26:12 by jcoquard          #+#    #+#             */
/*   Updated: 2024/03/27 18:26:37 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	how_many_border(t_map *map, int x, int y)
{
	int	tmp;

	tmp = 0;
	if (get_tile(map, x + 1, y) == '2')
		tmp++;
	if (get_tile(map, x - 1, y) == '2')
		tmp++;
	if (get_tile(map, x, y + 1) == '2')
		tmp++;
	if (get_tile(map, x, y - 1) == '2')
		tmp++;
	if (get_tile(map, x + 1, y + 1) == '2')
		tmp++;
	if (get_tile(map, x + 1, y - 1) == '2')
		tmp++;
	if (get_tile(map, x - 1, y + 1) == '2')
		tmp++;
	if (get_tile(map, x - 1, y - 1) == '2')
		tmp++;
	return (tmp);
}

int	how_many_fborder(t_map *map, int x, int y)
{
	int	tmp;

	tmp = 0;
	if (get_tile(map, x + 1, y) == '2')
		tmp++;
	if (get_tile(map, x - 1, y) == '2')
		tmp++;
	if (get_tile(map, x, y + 1) == '2')
		tmp++;
	if (get_tile(map, x, y - 1) == '2')
		tmp++;
	return (tmp);
}