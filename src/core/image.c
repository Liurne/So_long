/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:58:59 by jcoquard          #+#    #+#             */
/*   Updated: 2024/02/22 18:01:28 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	new_img(t_data *sl, t_img *img, int w, int h)
{
	img->img = mlx_new_image(sl->win.mlx, w, h);
	img->img_h = h;
	img->img_w = w;
	if (!img->img)
		error(sl, ERR_IMG);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	if (!img->addr)
		error(sl, ERR_IMG);
	return (0);
}

int	load_img(t_data *sl, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(sl->win.mlx, path, &(img->img_w),
			&(img->img_h));
	if (!img->img)
	{
		printf("%s\n", path);
		error(sl, ERR_TEX);
	}
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	if (!img->addr)
		error(sl, ERR_TEX);
	return (0);
}

int	destroy_img(t_data *sl, t_img *img)
{
	if (img->img)
		mlx_destroy_image(sl->win.mlx, img->img);
	return (0);
}