/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 03:08:41 by jcoquard          #+#    #+#             */
/*   Updated: 2024/02/20 17:43:19 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	wich_tile(t_data *sl, int x, int y)
{
	if (get_tile(sl, x / 128, y / 128) == '0' || get_tile(sl,
			x / 128, y / 128) == 'P')
	{
		if (((x / 128) + (y / 128)) % 5 == 4)
			put_pixelmap(&(sl->map), x, y, 1);
		else if (((x / 128) + (y / 128)) % 5 == 1)
			put_pixelmap(&(sl->map), x, y, 2);
		else
			put_pixelmap(&(sl->map), x, y, 0);
	}	
	if (get_tile(sl, x / 128, y / 128) == '2')
		which_border(sl, &(sl->map), x, y);
	else if (get_tile(sl, x / 128, y / 128) == '1')
	{
		if (((x / 128) + (y / 128)) % 2)
			put_pixelmap(&(sl->map), x, y, 3);
		else
			put_pixelmap(&(sl->map), x, y, 4);
	}
	else if (get_tile(sl, x / 128, y / 128) == 'E')
		put_pixelmap(&(sl->map), x, y, 52);
	else if (get_tile(sl, x / 128, y / 128) == 'C')
		put_pixelmap(&(sl->map), x, y, 56);
	else if (get_tile(sl, x / 128, y / 128) == 'I')
		put_pixelmap(&(sl->map), x, y, 53);
	else if (get_tile(sl, x / 128, y / 128) == 'S')
		put_pixelmap(&(sl->map), x, y, 54);
	else if (get_tile(sl, x / 128, y / 128) == 'c')
		put_pixelmap(&(sl->map), x, y, 55);
		
}

void	reload_tile_img(t_data *sl, int x, int y)
{
	int	tmp1;
	int	tmp2;

	tmp1 = x;
	tmp2 = y;
	while (x < tmp1 + 128)
	{
		y = tmp2;
		while (y < tmp2 + 128)
		{
			wich_tile (sl, x, y);
			y++;
		}
		x++;
	}
}

int	map_to_img(t_data *sl)
{
	int	x;
	int	y;

	new_img(sl, &(sl->map.img), sl->map.w * 128, sl->map.h * 128);
	x = 0;
	while (x < sl->map.w * 128)
	{
		y = 0;
		while (y < sl->map.h * 128)
		{
			wich_tile (sl, x, y);
			y++;
		}
		x++;
	}
	return (0);
}