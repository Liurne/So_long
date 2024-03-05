/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:43:59 by jcoquard          #+#    #+#             */
/*   Updated: 2024/03/05 21:47:05 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	get_tile(t_data *sl, int x, int y)
{
	if (x < sl->map.w && y < sl->map.h && x >= 0 && y >= 0)
		return (sl->map.map[(y * (sl->map.w + 1)) + x]);
	return ('2');
}

int	set_tile(t_data *sl, int x, int y, char c)
{
	if (x < sl->map.w && y < sl->map.h)
	{
		sl->map.map[(y * (sl->map.w + 1)) + x] = c;
		return (1);
	}
	else
		return (0);
}

void	put_pixelmap(t_map *m, int x, int y, int img)
{
	put_pixel(&(m->img), x, y, get_pixel(&(m->tex[img]), x % 128, y % 128));
}
