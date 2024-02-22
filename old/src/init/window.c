/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:14:03 by jcoquard          #+#    #+#             */
/*   Updated: 2024/02/22 17:59:19 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *sl)
{
	destroy_all_image(sl);
	destroy_img(sl, &(sl->map.img));
	destroy_img(sl, &(sl->win.renderer));
	if (sl->map.map)
		free(sl->map.map);
	if (sl->win.win)
		mlx_destroy_window(sl->win.mlx, sl->win.win);
	if (sl->win.mlx)
	{
		mlx_destroy_display(sl->win.mlx);
		free(sl->win.mlx);
	}
	exit(0);
	return (0);
}

int	init_window(t_data *sl, int win_w, int win_h)
{
	ft_bzero(sl, sizeof(t_data));
	sl->win.w = win_w;
	sl->win.h = win_h;
	sl->win.mlx = mlx_init();
	if (!sl->win.mlx)
		error(sl, ERR_MLX);
	sl->win.win = mlx_new_window(sl->win.mlx, sl->win.w, sl->win.h, "so_long");
	if (!sl->win.win)
		error(sl, ERR_LIB);
	new_img(sl, &(sl->win.renderer), sl->win.w, sl->win.h);
	if (!sl->win.renderer.img)
		error(sl, ERR_IMG);
	return (0);
}
