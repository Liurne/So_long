/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:01:37 by liurne            #+#    #+#             */
/*   Updated: 2024/06/25 15:52:19 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*which_tile(t_map *map, int x, int y)
{
	if (get_tile(map, x, y) == '0')
	{
		if (!(x % 5) && !(y % 4))
			return (&map->tex[2]);
		else if (!(x % 6) && !(y % 3))
			return (&map->tex[3]);
		else
			return (&map->tex[1]);
	}
	else if (get_tile(map, x, y) == '1')
		return (&map->tex[4 + (x + y) % 2]);
	else if (get_tile(map, x, y) == 'c')
		return (&map->tex[8]);
	else if (get_tile(map, x, y) == 'C')
		return (&map->tex[55]);
	else if (get_tile(map, x, y) == 'E')
		return (&map->tex[6]);
	else if (get_tile(map, x, y) == 'F')
		return (&map->tex[7]);
	else if (get_tile(map, x, y) == 'P')
		return (&map->tex[56]);
	else if (get_tile(map, x, y) == 'p')
		return (&map->tex[1]);
	else
		return (which_border(map, x, y));
}

void	reload_tile_img(t_map *map, int x, int y)
{
	t_rect	src;
	t_rect	dst;

	ft_setrect(&src, ft_vec(0, 0), 32, 32);
	ft_setrect(&dst, ft_vec(x * 128, y * 128), 128, 128);
	put_img_to_img(&map->img, which_tile(map, x, y), &src, &dst);
}

void	map_start(t_data *sl, t_map *map)
{
	int	i;

	set_tile(map, sl->pl.pos.x / 128, sl->pl.pos.y / 128, 'p');
	reload_tile_img(map, sl->pl.pos.x / 128, sl->pl.pos.y / 128);
	i = 0;
	while (i < sl->nb_cats)
	{
		set_tile(map, sl->cats[i].pos.x / 128, sl->cats[i].pos.y / 128, 'c');
		reload_tile_img(map, sl->cats[i].pos.x / 128, sl->cats[i].pos.y / 128);
		i++;
	}
	sl->game_status = RUN;
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
			put_img_to_img(&sl->map.img,
				which_tile(&sl->map, pos.x, pos.y), &src, &dst);
			pos.y++;
		}
		pos.x++;
	}
	return (0);
}