/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:25:14 by jcoquard          #+#    #+#             */
/*   Updated: 2024/06/25 14:27:52 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_img_pl(t_data *sl)
{
	destroy_img(sl, &(sl->tex_pl[0][0]));
	destroy_img(sl, &(sl->tex_pl[0][1]));
	destroy_img(sl, &(sl->tex_pl[0][2]));
	destroy_img(sl, &(sl->tex_pl[0][3]));
	destroy_img(sl, &(sl->tex_pl[0][4]));
	destroy_img(sl, &(sl->tex_pl[0][5]));
	destroy_img(sl, &(sl->tex_pl[1][0]));
	destroy_img(sl, &(sl->tex_pl[1][1]));
	destroy_img(sl, &(sl->tex_pl[1][2]));
	destroy_img(sl, &(sl->tex_pl[1][3]));
	destroy_img(sl, &(sl->tex_pl[1][4]));
	destroy_img(sl, &(sl->tex_pl[1][5]));
	destroy_img(sl, &(sl->tex_pl[2][0]));
	destroy_img(sl, &(sl->tex_pl[2][1]));
	destroy_img(sl, &(sl->tex_pl[2][2]));
	destroy_img(sl, &(sl->tex_pl[2][3]));
	destroy_img(sl, &(sl->tex_pl[3][0]));
	destroy_img(sl, &(sl->tex_pl[3][1]));
	destroy_img(sl, &(sl->tex_pl[3][2]));
	destroy_img(sl, &(sl->tex_pl[3][3]));
	destroy_img(sl, &(sl->tex_pl[4][2]));
	destroy_img(sl, &(sl->tex_pl[4][3]));
}

static void	destroy_img_cat(t_data *sl)
{
	destroy_img(sl, &(sl->tex_cat[0][0]));
	destroy_img(sl, &(sl->tex_cat[0][1]));
	destroy_img(sl, &(sl->tex_cat[0][2]));
	destroy_img(sl, &(sl->tex_cat[0][3]));
	destroy_img(sl, &(sl->tex_cat[1][0]));
	destroy_img(sl, &(sl->tex_cat[1][1]));
	destroy_img(sl, &(sl->tex_cat[1][2]));
	destroy_img(sl, &(sl->tex_cat[1][3]));
	destroy_img(sl, &(sl->tex_cat[2][0]));
	destroy_img(sl, &(sl->tex_cat[2][1]));
	destroy_img(sl, &(sl->tex_cat[2][2]));
	destroy_img(sl, &(sl->tex_cat[2][3]));
	destroy_img(sl, &(sl->tex_cat[3][0]));
	destroy_img(sl, &(sl->tex_cat[3][1]));
	destroy_img(sl, &(sl->tex_cat[3][2]));
	destroy_img(sl, &(sl->tex_cat[3][3]));
	destroy_img(sl, &(sl->tex_cat[4][0]));
	destroy_img(sl, &(sl->tex_cat[4][1]));
	destroy_img(sl, &(sl->tex_cat[4][2]));
	destroy_img(sl, &(sl->tex_cat[4][3]));
}

static void	destroy_img_wolf(t_data *sl)
{
	destroy_img(sl, &(sl->tex_wolf[0][0]));
	destroy_img(sl, &(sl->tex_wolf[0][1]));
	destroy_img(sl, &(sl->tex_wolf[0][2]));
	destroy_img(sl, &(sl->tex_wolf[0][3]));
	destroy_img(sl, &(sl->tex_wolf[1][0]));
	destroy_img(sl, &(sl->tex_wolf[1][1]));
	destroy_img(sl, &(sl->tex_wolf[1][2]));
	destroy_img(sl, &(sl->tex_wolf[1][3]));
	destroy_img(sl, &(sl->tex_wolf[2][0]));
	destroy_img(sl, &(sl->tex_wolf[2][1]));
	destroy_img(sl, &(sl->tex_wolf[2][2]));
	destroy_img(sl, &(sl->tex_wolf[2][3]));
	destroy_img(sl, &(sl->tex_wolf[3][0]));
	destroy_img(sl, &(sl->tex_wolf[3][1]));
	destroy_img(sl, &(sl->tex_wolf[3][2]));
	destroy_img(sl, &(sl->tex_wolf[3][3]));
	destroy_img(sl, &(sl->tex_wolf[4][1]));
	destroy_img(sl, &(sl->tex_wolf[4][2]));
}

static void	destroy_img_map(t_data *sl)
{
	int	i;

	i = 0;
	while (i < 57)
	{
		destroy_img(sl, &(sl->map.tex[i]));
		i++;
	}
}

void	destroy_all_image(t_data *sl)
{
	destroy_img_map(sl);
	destroy_img_pl(sl);
	destroy_img_cat(sl);
	destroy_img_wolf(sl);
}
