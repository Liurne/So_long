/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:37:03 by liurne            #+#    #+#             */
/*   Updated: 2024/03/27 00:55:37 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	how_many_border(t_data *sl, int x, int y)
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

int	how_many_fborder(t_data *sl, int x, int y)
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

t_img*	fborder1(t_data *sl, t_map *map, int x, int y)
{
	int	cx;
	int	cy;

	cx = x / 128;
	cy = y / 128;
	if (get_tile(sl, cx + 1, cy) == '2')
		return (&map->tex[28]);
	else if (get_tile(sl, cx - 1, cy) == '2')
		return (&map->tex[27]);
	else if (get_tile(sl, cx, cy + 1) == '2')
		return (&map->tex[26]);
	else if (get_tile(sl, cx, cy - 1) == '2')
		return (&map->tex[29]);
	return (&map->tex[22]);
}

t_img*	fborder2(t_data *sl, t_map *map, int x, int y)
{
	int	cx;
	int	cy;

	cx = x / 128;
	cy = y / 128;
	if (get_tile(sl, cx + 1, cy) == '2' && get_tile(sl, cx - 1, cy) == '2')
		return (&map->tex[13]);
	else if (get_tile(sl, cx, cy + 1) == '2' && get_tile(sl, cx, cy - 1) == '2')
		return (&map->tex[14]);
	else if (get_tile(sl, cx + 1, cy) == '2' && get_tile(sl, cx, cy - 1) == '2' && get_tile(sl, cx + 1, cy - 1) == '2')
		return (&map->tex[18]);
	else if (get_tile(sl, cx + 1, cy) == '2' && get_tile(sl, cx, cy + 1) == '2' && get_tile(sl, cx + 1, cy + 1) == '2')
		return (&map->tex[17]);
	else if (get_tile(sl, cx - 1, cy) == '2' && get_tile(sl, cx, cy + 1) == '2' && get_tile(sl, cx - 1, cy + 1) == '2')
		return (&map->tex[15]);
	else if (get_tile(sl, cx - 1, cy) == '2' && get_tile(sl, cx, cy - 1) == '2' && get_tile(sl, cx - 1, cy - 1) == '2')
		return (&map->tex[16]);
	else if (get_tile(sl, cx + 1, cy) == '2' && get_tile(sl, cx, cy + 1) == '2')
		return (&map->tex[37]);
	else if (get_tile(sl, cx + 1, cy) == '2' && get_tile(sl, cx, cy - 1) == '2')
		return (&map->tex[35]);
	else if (get_tile(sl, cx - 1, cy) == '2' && get_tile(sl, cx, cy + 1) == '2')
		return (&map->tex[36]);
	else if (get_tile(sl, cx - 1, cy) == '2' && get_tile(sl, cx, cy - 1) == '2')
		return (&map->tex[34]);
	return (&map->tex[22]);
}

t_img*	fborder3(t_data *sl, t_map *map, int x, int y)
{
	int	cx;
	int	cy;

	cx = x / 128;
	cy = y / 128;
	if (get_tile(sl, cx + 1, cy) == '2' && get_tile(sl, cx - 1, cy) == '2' && get_tile(sl, cx, cy + 1) == '2')
	{
		if (get_tile(sl, cx + 1, cy + 1) != '2' && get_tile(sl, cx - 1, cy + 1) != '2')
			return (&map->tex[38]);
		else if (get_tile(sl, cx + 1, cy + 1) != '2')
			return (&map->tex[42]);
		else if (get_tile(sl, cx - 1, cy + 1) != '2')
			return (&map->tex[43]);
		else
			return (&map->tex[5]);
	}
	else if (get_tile(sl, cx + 1, cy) == '2' && get_tile(sl, cx - 1, cy) == '2' && get_tile(sl, cx, cy - 1) == '2')
	{
		if (get_tile(sl, cx + 1, cy - 1) != '2' && get_tile(sl, cx - 1, cy - 1) != '2')
			return (&map->tex[39]);
		else if (get_tile(sl, cx + 1, cy - 1) != '2')
			return (&map->tex[48]);
		else if (get_tile(sl, cx - 1, cy - 1) != '2')
			return (&map->tex[49]);
		else
			return (&map->tex[6]);
	}
	else if (get_tile(sl, cx, cy + 1) == '2' && get_tile(sl, cx, cy - 1) == '2' && get_tile(sl, cx + 1, cy) == '2')
	{
		if (get_tile(sl, cx + 1, cy + 1) != '2' && get_tile(sl, cx + 1, cy - 1) != '2')
			return (&map->tex[41]);
		else if (get_tile(sl, cx + 1, cy + 1) != '2')
			return (&map->tex[46]);
		else if (get_tile(sl, cx + 1, cy - 1) != '2')
			return (&map->tex[47]);
		else
			return (&map->tex[8]);
	}
	else if (get_tile(sl, cx, cy + 1) == '2' && get_tile(sl, cx, cy - 1) == '2' && get_tile(sl, cx - 1, cy) == '2')
	{
		if (get_tile(sl, cx - 1, cy + 1) != '2' && get_tile(sl, cx - 1, cy - 1) != '2')
			return (&map->tex[40]);
		else if (get_tile(sl, cx - 1, cy + 1) != '2')
			return (&map->tex[44]);
		else if (get_tile(sl, cx - 1, cy - 1) != '2')
			return (&map->tex[45]);
		else
			return (&map->tex[7]);
	}
	return (&map->tex[22]);
}

t_img*	fborder4(t_data *sl, t_map *map, int x, int y)
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
			return (&map->tex[11]);
		else if (get_tile(sl, cx - 1, cy - 1) != '2')
			return (&map->tex[9]);
		else if (get_tile(sl, cx -1, cy + 1) != '2')
			return (&map->tex[12]);
		else if (get_tile(sl, cx + 1, cy - 1) != '2')
			return (&map->tex[10]);
	}
	else if (wall == 6)
	{
		if (get_tile(sl, cx + 1, cy + 1) == '2' && get_tile(sl, cx - 1, cy - 1) == '2')
			return (&map->tex[20]);
		else if (get_tile(sl, cx + 1, cy - 1) == '2' && get_tile(sl, cx - 1, cy + 1) == '2')
			return (&map->tex[21]);
		else if (get_tile(sl, cx + 1, cy - 1) == '2' && get_tile(sl, cx - 1, cy - 1) == '2')
			return (&map->tex[33]);
		else if (get_tile(sl, cx + 1, cy + 1) == '2' && get_tile(sl, cx - 1, cy + 1) == '2')
			return (&map->tex[30]);
		else if (get_tile(sl, cx + 1, cy + 1) == '2' && get_tile(sl, cx + 1, cy - 1) == '2')
			return (&map->tex[32]);
		else if (get_tile(sl, cx - 1, cy + 1) == '2' && get_tile(sl, cx - 1, cy - 1) == '2')
			return (&map->tex[31]);
	}
	else if (wall == 5)
	{
		if (get_tile(sl, cx + 1, cy + 1) == '2')
			return (&map->tex[25]);
		else if (get_tile(sl, cx + 1, cy - 1) == '2')
			return (&map->tex[23]);
		else if (get_tile(sl, cx - 1, cy + 1) == '2')
			return (&map->tex[24]);
		else if (get_tile(sl, cx - 1, cy - 1) == '2')
			return (&map->tex[22]);
	}
	return (&map->tex[22]);
}
t_img*	which_border(t_data *sl, t_map *map, int x, int y)
{
	int	fwall;
	int	wall;

	fwall = how_many_fborder(sl, x/128, y/128);
	wall = how_many_border(sl, x/128, y/128);
	if (fwall == 1)
		return(fborder1(sl, map, x, y));
	else if	(fwall == 2)
		return(fborder2(sl, map, x, y));
	else if	(fwall == 3)
		return(fborder3(sl, map, x, y));
	else if (fwall == 4 && wall == 4)
		return (&map->tex[50]);
	else if (wall == 8)
		return (&map->tex[51]);
	else
		return(fborder4(sl, map, x, y));
}

t_img*	which_tile(t_data *sl, int x, int y)
{
	if (get_tile(sl, x / 128, y / 128) == '0')
	{
		if (((x / 128) + (y / 128)) % 5 == 4)
			return (&sl->map.tex[1]);
		else if (((x / 128) + (y / 128)) % 5 == 1)
			return (&sl->map.tex[2]);
		else
			return (&sl->map.tex[0]);
	}
	if (get_tile(sl, x / 128, y / 128) == '2')
		return (which_border(sl, &(sl->map), x, y));
	else if (get_tile(sl, x / 128, y / 128) == '1')
		return (&sl->map.tex[3 + (x / 128 + y / 128) % 2]);
	else if (get_tile(sl, x / 128, y / 128) == 'C')
		return (&sl->map.tex[55]);
	else if (get_tile(sl, x / 128, y / 128) == 'I')
		return (&sl->map.tex[53]);
	else if (get_tile(sl, x / 128, y / 128) == 'E')
		return (&sl->map.tex[52]);
	else if (get_tile(sl, x / 128, y / 128) == 'F')
		return (&sl->map.tex[54]);
	else
		return (&sl->map.tex[55]);
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
			which_tile (sl, x, y);
			y++;
		}
		x++;
	}
}

int	map_to_img(t_data *sl)
{
	t_vec	pos;
	t_rect	src;
	t_rect	dst;

	new_img(sl, &(sl->map.img), sl->map.w * 128, sl->map.h * 128);
	ft_setvec(&pos, 0, 0);
	ft_setrect(&src, pos, 32, 32);
	while (pos.x < sl->map.w)
	{
		pos.y = 0;
		while (pos.y < sl->map.h)
		{
			ft_setrect(&dst, ft_vec(pos.x * 128, pos.y * 128), 128, 128);
			put_img_to_img(&sl->map.img, which_tile(sl, pos.x, pos.y), &src, &dst);
			pos.y++;
		}
		pos.x++;
	}
	return (0);
}