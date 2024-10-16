/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:54:27 by liurne            #+#    #+#             */
/*   Updated: 2024/04/26 22:30:14 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_pet(t_entity *pl, t_entity *cat)
{
	static unsigned int	delay;

	if (pl->frame < 4)
		pl->frame = 4;
	if (!(delay % 8))
		pl->frame = ((pl->frame - 3) % 2) + 4;
	if (pl->pos.y + pl->hitbox.pos.y + pl->hitbox.h
		> cat->pos.y + cat->hitbox.pos.y + cat->hitbox.h)
		pl->dir = 1;
	else
		pl->dir = 0;
	pl->collision_entity = 0;
	delay++;
}
void	update_cam(t_wins *win, t_entity *pl, t_map *map)
{
	if (map->w * 128 > win->w)
	{
		if (pl->pos.x >= win->w * 0.5)
			map->pos.x = -(pl->pos.x - (win->w * 0.5));
		if (map->pos.x * -1 > (map->w * 128) - win->w)
			map->pos.x = (map->w * -128) + win->w;
	}
	if (map->h * 128 > win->h)
	{
		if (pl->pos.y >= win->h * 0.5)
			map->pos.y = -(pl->pos.y - (win->h * 0.5));
		if (map->pos.y * -1 > (map->h * 128) - win->h)
			map->pos.y = (map->h * -128) + win->h;
	}
}

int	player_move(t_data *sl, int x, int y, int dir)
{
	sl->pl.dir = dir;
	if (!x && !y)
		return (0);
	if (!sl->pl.inmove)
		sl->pl.frame = 1;
	sl->pl.inmove = 1;
	if (!map_collision(sl, &sl->pl, x, y) && (x || y))
	{
		sl->pl.dist += sl->pl.speed;
		if (sl->pl.dist >= 128)
		{
			ft_putmove_fd(sl->pl.nb_mv++, 1);
			sl->pl.dist = 0;
		}
		sl->pl.pos.x += x;
		sl->pl.pos.y += y;
		update_cam(&sl->win, &sl->pl, &sl->map);
	}
	return (0);
}

void	player_manager(t_data *sl)
{
	if (sl->keys.up)
		player_move(sl, 0, -sl->pl.speed, 1);
	if (sl->keys.down)
		player_move(sl, 0, sl->pl.speed, 0);
	if (sl->keys.left)
		player_move(sl, -sl->pl.speed, 0, 3);
	if (sl->keys.right)
		player_move(sl, sl->pl.speed, 0, 2);
	if (!sl->keys.up && !sl->keys.down && !sl->keys.left
		&& !sl->keys.right)
	{
		sl->pl.inmove = 0;
		if (sl->pl.collision_entity)
			player_pet(&sl->pl, &sl->cats[sl->pl.collision_entity - 1]);
		else
			sl->pl.frame = 0;
	}
}
