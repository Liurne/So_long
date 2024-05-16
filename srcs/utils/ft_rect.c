/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:11:15 by jcoquard          #+#    #+#             */
/*   Updated: 2024/03/26 22:49:06 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_rect	ft_rect(int x, int y, int w, int h)
{
	t_rect	res;

	res.pos.x = x;
	res.pos.y = y;
	res.w = w;
	res.h = h;
	return (res);
}

void	ft_setrect(t_rect *rect, t_vec pos, int w, int h)
{
	rect->pos.x = pos.x;
	rect->pos.y = pos.y;
	rect->w = w;
	rect->h = h;
}
