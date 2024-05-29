/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:01:26 by jcoquard          #+#    #+#             */
/*   Updated: 2024/05/29 17:35:37 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	background_ocean(t_data *sl, t_img *renderer)
{
	t_rect	dst;
	t_rect	src;

	ft_setrect(&dst, ft_vec(0, 0), renderer->img_w, renderer->img_h);
	ft_setrect(&src, ft_vec(0, 0), 32, 32);
	put_img_to_img(&sl->win.renderer, &sl->map.tex[0], &src, &dst);
}

void	animation_arriving(t_data *sl, t_img *renderer)
{
	t_rect	src;
	t_rect	dst;
	int		w;
	int		h;

	background_ocean(sl, renderer);
	w = renderer->img_w;
	h = renderer->img_h;
	if (renderer->img_h > sl->map.h * 128)
		h = sl->map.w * 128;
	if (renderer->img_w > sl->map.w * 128)
		w = sl->map.w * 128;
	ft_setrect(&dst, ft_vec(0, renderer->img_h - sl->time), w, h);
	ft_setrect(&src, ft_vec(0, 0), sl->map.w * 128, sl->map.h * 128);
	put_img_to_img(renderer, &sl->map.img, &src, &dst);
	mlx_put_image_to_window(sl->win.mlx, sl->win.win,
		sl->win.renderer.img, 0, 0);
	if (sl->time < renderer->img_h)
		sl->time += 4;
	else
	{
		sl->game_status = RUN;
		sl->time = 0;
	}
}
