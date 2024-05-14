/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_border.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:40:40 by liurne            #+#    #+#             */
/*   Updated: 2024/04/26 21:58:33 by liurne           ###   ########.fr       */
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