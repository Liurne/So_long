/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 03:32:30 by liurne            #+#    #+#             */
/*   Updated: 2024/02/20 17:43:14 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	how_many_border(t_data *sl, int x, int y)
{
	int	tmp;

	tmp = 0;
	if (get_tile(sl, x + 1, y) == '2')
		tmp++;
	if (get_tile(sl, x - 1, y) == '2')
		tmp++;
	if (get_tile(sl, x, y + 1) == '2')
		tmp++;
	if (get_tile(sl, x, y - 1) == '2')
		tmp++;
	if (get_tile(sl, x + 1, y + 1) == '2')
		tmp++;
	if (get_tile(sl, x + 1, y - 1) == '2')
		tmp++;
	if (get_tile(sl, x - 1, y + 1) == '2')
		tmp++;
	if (get_tile(sl, x - 1, y - 1) == '2')
		tmp++;
	return (tmp);
}

static int	how_many_fborder(t_data *sl, int x, int y)
{
	int	tmp;

	tmp = 0;
	if (get_tile(sl, x + 1, y) == '2')
		tmp++;
	if (get_tile(sl, x - 1, y) == '2')
		tmp++;
	if (get_tile(sl, x, y + 1) == '2')
		tmp++;
	if (get_tile(sl, x, y - 1) == '2')
		tmp++;
	return (tmp);
}

void	fborder1(t_data *sl, t_map *map, int x, int y)
{
	int	cx;
	int	cy;

	cx = x / 128;
	cy = y / 128;
	if (get_tile(sl, cx + 1, cy) == '2')
		put_pixelmap(map, x, y, 28);
	else if (get_tile(sl, cx - 1, cy) == '2')
		put_pixelmap(map, x, y, 27);
	else if (get_tile(sl, cx, cy + 1) == '2')
		put_pixelmap(map, x, y, 26);
	else if (get_tile(sl, cx, cy - 1) == '2')
		put_pixelmap(map, x, y, 29);
}

void	fborder2(t_data *sl, t_map *map, int x, int y)
{
	int	cx;
	int	cy;

	cx = x / 128;
	cy = y / 128;
	if (get_tile(sl, cx + 1, cy) == '2' && get_tile(sl, cx - 1, cy) == '2')
		put_pixelmap(map, x, y, 13);
	else if (get_tile(sl, cx, cy + 1) == '2' && get_tile(sl, cx, cy - 1) == '2')
		put_pixelmap(map, x, y, 14);
	else if (get_tile(sl, cx + 1, cy) == '2' && get_tile(sl, cx, cy - 1) == '2' && get_tile(sl, cx + 1, cy - 1) == '2')
		put_pixelmap(map, x, y, 18);
	else if (get_tile(sl, cx + 1, cy) == '2' && get_tile(sl, cx, cy + 1) == '2' && get_tile(sl, cx + 1, cy + 1) == '2')
		put_pixelmap(map, x, y, 17);
	else if (get_tile(sl, cx - 1, cy) == '2' && get_tile(sl, cx, cy + 1) == '2' && get_tile(sl, cx - 1, cy + 1) == '2')
		put_pixelmap(map, x, y, 15);
	else if (get_tile(sl, cx - 1, cy) == '2' && get_tile(sl, cx, cy - 1) == '2' && get_tile(sl, cx - 1, cy - 1) == '2')
		put_pixelmap(map, x, y, 16);
	else if (get_tile(sl, cx + 1, cy) == '2' && get_tile(sl, cx, cy + 1) == '2')
		put_pixelmap(map, x, y, 37);
	else if (get_tile(sl, cx + 1, cy) == '2' && get_tile(sl, cx, cy - 1) == '2')
		put_pixelmap(map, x, y, 35);
	else if (get_tile(sl, cx - 1, cy) == '2' && get_tile(sl, cx, cy + 1) == '2')
		put_pixelmap(map, x, y, 36);
	else if (get_tile(sl, cx - 1, cy) == '2' && get_tile(sl, cx, cy - 1) == '2')
		put_pixelmap(map, x, y, 34);
}

void	fborder3(t_data *sl, t_map *map, int x, int y)
{
	int	cx;
	int	cy;

	cx = x / 128;
	cy = y / 128;
	if (get_tile(sl, cx + 1, cy) == '2' && get_tile(sl, cx - 1, cy) == '2' && get_tile(sl, cx, cy + 1) == '2')
	{
		if (get_tile(sl, cx + 1, cy + 1) != '2' && get_tile(sl, cx - 1, cy + 1) != '2')
			put_pixelmap(map, x, y, 38);
		else if (get_tile(sl, cx + 1, cy + 1) != '2')
			put_pixelmap(map, x, y, 42);
		else if (get_tile(sl, cx - 1, cy + 1) != '2')
			put_pixelmap(map, x, y, 43);
		else
			put_pixelmap(map, x, y, 5);
	}
	else if (get_tile(sl, cx + 1, cy) == '2' && get_tile(sl, cx - 1, cy) == '2' && get_tile(sl, cx, cy - 1) == '2')
	{
		if (get_tile(sl, cx + 1, cy - 1) != '2' && get_tile(sl, cx - 1, cy - 1) != '2')
			put_pixelmap(map, x, y, 39);
		else if (get_tile(sl, cx + 1, cy - 1) != '2')
			put_pixelmap(map, x, y, 48);
		else if (get_tile(sl, cx - 1, cy - 1) != '2')
			put_pixelmap(map, x, y, 49);
		else
			put_pixelmap(map, x, y, 6);
	}
	else if (get_tile(sl, cx, cy + 1) == '2' && get_tile(sl, cx, cy - 1) == '2' && get_tile(sl, cx + 1, cy) == '2')
	{
		if (get_tile(sl, cx + 1, cy + 1) != '2' && get_tile(sl, cx + 1, cy - 1) != '2')
			put_pixelmap(map, x, y, 41);
		else if (get_tile(sl, cx + 1, cy + 1) != '2')
			put_pixelmap(map, x, y, 46);
		else if (get_tile(sl, cx + 1, cy - 1) != '2')
			put_pixelmap(map, x, y, 47);
		else
			put_pixelmap(map, x, y, 8);
	}
	else if (get_tile(sl, cx, cy + 1) == '2' && get_tile(sl, cx, cy - 1) == '2' && get_tile(sl, cx - 1, cy) == '2')
	{
		if (get_tile(sl, cx - 1, cy + 1) != '2' && get_tile(sl, cx - 1, cy - 1) != '2')
			put_pixelmap(map, x, y, 40);
		else if (get_tile(sl, cx - 1, cy + 1) != '2')
			put_pixelmap(map, x, y, 44);
		else if (get_tile(sl, cx - 1, cy - 1) != '2')
			put_pixelmap(map, x, y, 45);
		else
			put_pixelmap(map, x, y, 7);
	}
}

void	fborder4(t_data *sl, t_map *map, int x, int y)
{
	int	cx;
	int	cy;
	int	wall;

	cx = x / 128;
	cy = y / 128;
	wall = how_many_border(sl, x/128, y/128);
	if (wall == 7)
	{
		if (get_tile(sl, cx + 1, cy+ 1) != '2')
			put_pixelmap(map, x, y, 11);
		else if (get_tile(sl, cx - 1, cy - 1) != '2')
			put_pixelmap(map, x, y, 9);
		else if (get_tile(sl, cx -1, cy + 1) != '2')
			put_pixelmap(map, x, y, 12);
		else if (get_tile(sl, cx + 1, cy - 1) != '2')
			put_pixelmap(map, x, y, 10);
	}
	else if (wall == 6)
	{
		if (get_tile(sl, cx + 1, cy + 1) == '2' && get_tile(sl, cx - 1, cy - 1) == '2')
			put_pixelmap(map, x, y, 20);
		else if (get_tile(sl, cx + 1, cy - 1) == '2' && get_tile(sl, cx - 1, cy + 1) == '2')
			put_pixelmap(map, x, y, 21);
		else if (get_tile(sl, cx + 1, cy - 1) == '2' && get_tile(sl, cx - 1, cy - 1) == '2')
			put_pixelmap(map, x, y, 33);
		else if (get_tile(sl, cx + 1, cy + 1) == '2' && get_tile(sl, cx - 1, cy + 1) == '2')
			put_pixelmap(map, x, y, 30);
		else if (get_tile(sl, cx + 1, cy + 1) == '2' && get_tile(sl, cx + 1, cy - 1) == '2')
			put_pixelmap(map, x, y, 32);
		else if (get_tile(sl, cx - 1, cy + 1) == '2' && get_tile(sl, cx - 1, cy - 1) == '2')
			put_pixelmap(map, x, y, 31);
	}
	else if (wall == 5)
	{
		if (get_tile(sl, cx + 1, cy + 1) == '2')
			put_pixelmap(map, x, y, 25);
		else if (get_tile(sl, cx + 1, cy - 1) == '2')
			put_pixelmap(map, x, y, 23);
		else if (get_tile(sl, cx - 1, cy + 1) == '2')
			put_pixelmap(map, x, y, 24);
		else if (get_tile(sl, cx - 1, cy - 1) == '2')
			put_pixelmap(map, x, y, 22);
	}
	
}
void	which_border(t_data *sl, t_map *map, int x, int y)
{
	int	fwall;
	int	wall;

	fwall = how_many_fborder(sl, x/128, y/128);
	wall = how_many_border(sl, x/128, y/128);
	if (fwall == 1)
		fborder1(sl, map, x, y);
	else if	(fwall == 2)
		fborder2(sl, map, x, y);
	else if	(fwall == 3)
		fborder3(sl, map, x, y);
	else if (fwall == 4 && wall == 4)
		put_pixelmap(map, x, y, 50);
	else if (wall == 8)
		put_pixelmap(map, x, y, 51);
	else
		fborder4(sl, map, x, y);
	
}
