/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:52:39 by liurne            #+#    #+#             */
/*   Updated: 2024/10/15 17:58:31 by jcoquard         ###   ########.fr       */
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

int transparence(int c1, int c2, int t)
{
	float tr = t * 0.01f;
	float tr_inv = 1.0f - tr;
	int r = ((((c1 >> 16) & 0xFF) * tr_inv) + (((c2 >> 16) & 0xFF) * tr));
	int g = ((((c1 >> 8) & 0xFF) * tr_inv) + (((c2 >> 8) & 0xFF) * tr));
	int b = (((c1 & 0xFF) * tr_inv) + ((c2 & 0xFF) * tr));

	return (255 << 24) | (r << 16) | (g << 8) | b;
}

void	put_img_to_img(t_img *img1, t_img *img2, t_rect *src, t_rect *dst)
{
	int	i;
	int	j;
	int	tmp_x;
	int	tmp_y;

	i = 0;
	while (i < dst->w)
	{
		j = 0;
		tmp_x = src->pos.x + (i * src->w) / dst->w;
		while (j < dst->h)
		{
			tmp_y = src->pos.y + (j * src->h) / dst->h;
			put_pixel(img1, i + dst->pos.x, j + dst->pos.y,
				get_pixel(img2, tmp_x, tmp_y));
			j++;
		}
		i++;
	}
}

void	animation(t_data *sl)
{
	int	i;

	i = -1;
	while (++i < sl->nb_entities)
	{
		if (sl->entities[i]->inmove && !(sl->time % 6))
			sl->entities[i]->frame = (sl->entities[i]->frame + 1) % 4;
	}
	++sl->time;
}
