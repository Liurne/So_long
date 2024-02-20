/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:23:48 by jcoquard          #+#    #+#             */
/*   Updated: 2024/02/20 17:31:25 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	complete_border(t_data *sl, int x, int y)
{
	if(x < 0 || y < 0 || x > sl->map.w - 1 || y > sl->map.h - 1)
		return;
	if (get_tile(sl, x, y) == '1')
	{
		set_tile(sl, x, y, '2');
		complete_border(sl, x + 1, y);
		complete_border(sl, x - 1, y);
		complete_border(sl, x, y + 1);
		complete_border(sl, x, y - 1);
	}
	
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