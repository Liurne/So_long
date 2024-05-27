/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities_constructor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:53:59 by liurne            #+#    #+#             */
/*   Updated: 2024/04/28 18:07:58 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_pl(t_entity *pl, int x, int y)
{
	pl->id = 0;
	pl->type = PLAYER;
	pl->active = 1;
	pl->pos.x = x * 128;
	pl->pos.y = y * 128;
	pl->speed = 11;
	pl->hitbox.pos.x = 40;
	pl->hitbox.pos.y = 32;
	pl->hitbox.w = 48;
	pl->hitbox.h = 96;
	pl->walkbox.pos.x = 40;
	pl->walkbox.pos.y = 104;
	pl->walkbox.w = 48;
	pl->walkbox.h = 23;
	pl->delay = 150;
}

void	init_bad(t_entity *e, int x, int y)
{
	e->id = 0;
	e->type = BAD;
	e->active = 0;
	e->pos.x = x * 128;
	e->pos.y = y * 128;
	e->speed = 11;
	e->hitbox.pos.x = 40;
	e->hitbox.pos.y = 32;
	e->hitbox.w = 48;
	e->hitbox.h = 96;
	e->walkbox.pos.x = 40;
	e->walkbox.pos.y = 104;
	e->walkbox.w = 48;
	e->walkbox.h = 23;
}

void	init_cat(t_entity *e, int x, int y, int nb)
{
	e->id = nb;
	e->type = CAT;
	e->active = 1;
	e->pos.x = x * 128;
	e->pos.y = y * 128;
	e->speed = 10;
	e->hitbox.pos.x = 32;
	e->hitbox.pos.y = 32;
	e->hitbox.w = 64;
	e->hitbox.h = 64;
	e->walkbox.pos.x = 32;
	e->walkbox.pos.y = 80;
	e->walkbox.w = 64;
	e->walkbox.h = 15;
	e->delay = 50;
}
