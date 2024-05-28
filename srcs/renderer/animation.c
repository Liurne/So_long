/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:01:26 by jcoquard          #+#    #+#             */
/*   Updated: 2024/05/28 19:09:11 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animation_start(t_data *sl)
{
	t_rect	src;
	t_rect	dst;

	ft_setrect(&dst, ft_vec(0, 0), sl->win.renderer.img_w, sl->win.renderer.img_h);
	ft_setrect(&src, ft_vec(1, 1), 2, 2);
	put_img_to_img(&sl->win.renderer, &sl->map.img, &src, &dst);
	ft_setrect(&dst, ft_vec(0, sl->win.h - sl->time), sl->win.renderer.img_w, sl->win.renderer.img_h);
	ft_setrect(&src, ft_vec(0, 0), sl->map.w * 128, sl->map.h * 128);
	put_img_to_img(&sl->win.renderer, &sl->map.img, &src, &dst);
	mlx_put_image_to_window(sl->win.mlx, sl->win.win,
		sl->win.renderer.img, 0, 0);
	if (sl->time < sl->win.h)
		sl->time += 4;
}