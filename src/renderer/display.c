/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:13:30 by jcoquard          #+#    #+#             */
/*   Updated: 2024/02/23 23:20:18 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_text(t_data	*sl)
{
	char	*tmp;

	mlx_string_put(sl->win.mlx, sl->win.win, 10, 20, 0xFFFFFFFF,
		"Number of tiles traveled : ");
	tmp = ft_itoa(sl->pl.nb_mv);
	if (!tmp)
	{
		ft_putstr_fd("Error : malloc failled\n", 2);
		close_window(sl);
	}
	mlx_string_put(sl->win.mlx, sl->win.win, 175, 21, 0xFFFFFFFF, tmp);
	free(tmp);
	mlx_string_put(sl->win.mlx, sl->win.win, 10, 35, 0xFFFFFFFF,
		"Number of boxes remaining : ");
	tmp = ft_itoa(sl->nb_dogs);
	if (!tmp)
	{
		ft_putstr_fd("Error : malloc failled\n", 2);
		close_window(sl);
	}
	mlx_string_put(sl->win.mlx, sl->win.win, 175, 36, 0xFFFFFFFF, tmp);
	free(tmp);
}

void	render_display(t_data *sl)
{
	int	x;
	int	y;

	x = -1;
	while (x++ < sl->win.w && x - sl->map.pos.x < sl->map.w * 128)
	{
		y = -1;
		while (y++ < sl->win.h && y - sl->map.pos.y < sl->map.h * 128)
			put_pixel(&(sl->win.renderer), x, y, transparence(get_pixel(
						&(sl->map.img), x - sl->map.pos.x, y - sl->map.pos.y),
					C_NIGHT, sl->night));
	}
	display_entity(sl, sl->entities, 0, sl->nb_entities);
	mlx_put_image_to_window(sl->win.mlx, sl->win.win,
		sl->win.renderer.img, 0, 0);
	display_text(sl);
}
