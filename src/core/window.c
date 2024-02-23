/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:14:03 by jcoquard          #+#    #+#             */
/*   Updated: 2024/02/23 18:40:24 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	close_window(t_data *sl)
{
	destroy_all_image(sl);
	destroy_img(sl, &(sl->map.img));
	destroy_img(sl, &(sl->win.renderer));
	if (sl->dogs)
		free(sl->dogs);
	if (sl->entities)
		free(sl->entities);
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

int	error(t_data *sl, char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	close_window(sl);
	return (1);
}
