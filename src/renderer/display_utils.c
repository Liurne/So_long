/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:52:39 by liurne            #+#    #+#             */
/*   Updated: 2024/02/23 19:55:30 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= img->img_w || y < 0 || y >= img->img_h)
		return ;
	((int *)img->addr)[y * (img->line_length >> 2) + x] = color;
}

int	get_pixel(t_img *img, int x, int y)
{
	if (x < 0 || x >= img->img_w || y < 0 || y >= img->img_h)
		return (0);
	return (((int *)img->addr)[y * (img->line_length >> 2) + x]);
}

int	transparence(int c1, int c2, int t)
{
	int	r;
	int	g;
	int	b;
	float tr;

	tr = (float)t / 100;
	r = (((c1 >> 16) & 0xFF) * (1.0 - tr) + ((c2 >> 16) & 0xFF) * tr);
	if (r > 255)
		r = 255;
	g = (((c1 >> 8) & 0xFF) * (1.0 - tr) + ((c2 >> 8) & 0xFF) * tr);
	if (g > 255)
		g = 255;
	b = (c1 & 0xFF) * (1.0 - tr) + ((c2 & 0xFF) * tr);
	if (b > 255)
		b = 255;
	return (255 << 24 | r << 16 | g << 8 | b);
}

void	animation(t_data *sl)
{
	size_t	i;

	i = -1;
	while(++i < sl->nb_dogs + 2)
	{
		if (!sl->entities[i]->inmove)
			sl->entities[i]->animation = 0;
		if (sl->entities[i]->inmove && sl->time >= 7)
			sl->entities[i]->animation = (sl->entities[i]->animation + 1) % 4;
	}
	if (sl->time >= 7)
		sl->time = 0;
	++sl->time;
}
