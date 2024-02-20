/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:25:14 by jcoquard          #+#    #+#             */
/*   Updated: 2024/02/20 17:31:01 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_img_pl(t_data *sl)
{
	destroy_img(sl, &(sl->pl.tex[0][0]));
	destroy_img(sl, &(sl->pl.tex[0][1]));
	destroy_img(sl, &(sl->pl.tex[0][2]));
	destroy_img(sl, &(sl->pl.tex[0][3]));
	destroy_img(sl, &(sl->pl.tex[1][0]));
	destroy_img(sl, &(sl->pl.tex[1][1]));
	destroy_img(sl, &(sl->pl.tex[1][2]));
	destroy_img(sl, &(sl->pl.tex[1][3]));
	destroy_img(sl, &(sl->pl.tex[2][0]));
	destroy_img(sl, &(sl->pl.tex[2][1]));
	destroy_img(sl, &(sl->pl.tex[2][2]));
	destroy_img(sl, &(sl->pl.tex[2][3]));
	destroy_img(sl, &(sl->pl.tex[3][0]));
	destroy_img(sl, &(sl->pl.tex[3][1]));
	destroy_img(sl, &(sl->pl.tex[3][2]));
	destroy_img(sl, &(sl->pl.tex[3][3]));
	destroy_img(sl, &(sl->pl.tex[4][0]));
	destroy_img(sl, &(sl->pl.tex[4][1]));
	destroy_img(sl, &(sl->pl.tex[4][2]));
}

static void	destroy_img_dog(t_data *sl)
{
	destroy_img(sl, &(sl->dog[0].tex[0][0]));
	destroy_img(sl, &(sl->dog[0].tex[0][1]));
	destroy_img(sl, &(sl->dog[0].tex[0][2]));
	destroy_img(sl, &(sl->dog[0].tex[0][3]));
	destroy_img(sl, &(sl->dog[0].tex[1][0]));
	destroy_img(sl, &(sl->dog[0].tex[1][1]));
	destroy_img(sl, &(sl->dog[0].tex[1][2]));
	destroy_img(sl, &(sl->dog[0].tex[1][3]));
	destroy_img(sl, &(sl->dog[0].tex[2][0]));
	destroy_img(sl, &(sl->dog[0].tex[2][1]));
	destroy_img(sl, &(sl->dog[0].tex[2][2]));
	destroy_img(sl, &(sl->dog[0].tex[2][3]));
	destroy_img(sl, &(sl->dog[0].tex[3][0]));
	destroy_img(sl, &(sl->dog[0].tex[3][1]));
	destroy_img(sl, &(sl->dog[0].tex[3][2]));
	destroy_img(sl, &(sl->dog[0].tex[3][3]));
	destroy_img(sl, &(sl->dog[0].tex[4][0]));
}

static void	destroy_img_wolf(t_data *sl)
{
	destroy_img(sl, &(sl->wolf.tex[0][0]));
	destroy_img(sl, &(sl->wolf.tex[0][1]));
	destroy_img(sl, &(sl->wolf.tex[0][2]));
	destroy_img(sl, &(sl->wolf.tex[0][3]));
	destroy_img(sl, &(sl->wolf.tex[1][0]));
	destroy_img(sl, &(sl->wolf.tex[1][1]));
	destroy_img(sl, &(sl->wolf.tex[1][2]));
	destroy_img(sl, &(sl->wolf.tex[1][3]));
	destroy_img(sl, &(sl->wolf.tex[2][0]));
	destroy_img(sl, &(sl->wolf.tex[2][1]));
	destroy_img(sl, &(sl->wolf.tex[2][2]));
	destroy_img(sl, &(sl->wolf.tex[2][3]));
	destroy_img(sl, &(sl->wolf.tex[3][0]));
	destroy_img(sl, &(sl->wolf.tex[3][1]));
	destroy_img(sl, &(sl->wolf.tex[3][2]));
	destroy_img(sl, &(sl->wolf.tex[3][3]));
	destroy_img(sl, &(sl->wolf.tex[4][1]));
	destroy_img(sl, &(sl->wolf.tex[4][2]));
}

static void	destroy_img_map(t_data *sl)
{
	destroy_img(sl, &(sl->map.tex[0]));
	destroy_img(sl, &(sl->map.tex[1]));
	destroy_img(sl, &(sl->map.tex[2]));
	destroy_img(sl, &(sl->map.tex[3]));
	destroy_img(sl, &(sl->map.tex[4]));
	destroy_img(sl, &(sl->map.tex[5]));
	destroy_img(sl, &(sl->map.tex[6]));
	destroy_img(sl, &(sl->map.tex[7]));
	destroy_img(sl, &(sl->map.tex[8]));
	destroy_img(sl, &(sl->map.tex[9]));
	destroy_img(sl, &(sl->map.tex[10]));
	destroy_img(sl, &(sl->map.tex[11]));
	destroy_img(sl, &(sl->map.tex[12]));
	destroy_img(sl, &(sl->map.tex[13]));
	destroy_img(sl, &(sl->map.tex[14]));
	destroy_img(sl, &(sl->map.tex[15]));
	destroy_img(sl, &(sl->map.tex[16]));
	destroy_img(sl, &(sl->map.tex[17]));
	destroy_img(sl, &(sl->map.tex[18]));
	destroy_img(sl, &(sl->map.tex[19]));
	destroy_img(sl, &(sl->map.tex[20]));
	destroy_img(sl, &(sl->map.tex[21]));
	destroy_img(sl, &(sl->map.tex[22]));
	destroy_img(sl, &(sl->map.tex[23]));
	destroy_img(sl, &(sl->map.tex[24]));
	destroy_img(sl, &(sl->map.tex[25]));
	destroy_img(sl, &(sl->map.tex[26]));
	destroy_img(sl, &(sl->map.tex[27]));
	destroy_img(sl, &(sl->map.tex[28]));
	destroy_img(sl, &(sl->map.tex[29]));
	destroy_img(sl, &(sl->map.tex[30]));
	destroy_img(sl, &(sl->map.tex[31]));
	destroy_img(sl, &(sl->map.tex[32]));
	destroy_img(sl, &(sl->map.tex[33]));
	destroy_img(sl, &(sl->map.tex[34]));
	destroy_img(sl, &(sl->map.tex[35]));
	destroy_img(sl, &(sl->map.tex[36]));
	destroy_img(sl, &(sl->map.tex[37]));
	destroy_img(sl, &(sl->map.tex[38]));
	destroy_img(sl, &(sl->map.tex[39]));
	destroy_img(sl, &(sl->map.tex[40]));
	destroy_img(sl, &(sl->map.tex[41]));
	destroy_img(sl, &(sl->map.tex[42]));
	destroy_img(sl, &(sl->map.tex[43]));
	destroy_img(sl, &(sl->map.tex[44]));
	destroy_img(sl, &(sl->map.tex[45]));
	destroy_img(sl, &(sl->map.tex[46]));
	destroy_img(sl, &(sl->map.tex[47]));
	destroy_img(sl, &(sl->map.tex[48]));
	destroy_img(sl, &(sl->map.tex[49]));
	destroy_img(sl, &(sl->map.tex[50]));
	destroy_img(sl, &(sl->map.tex[51]));
	destroy_img(sl, &(sl->map.tex[52]));
	destroy_img(sl, &(sl->map.tex[53]));
	destroy_img(sl, &(sl->map.tex[54]));
	destroy_img(sl, &(sl->map.tex[55]));
	destroy_img(sl, &(sl->map.tex[56]));
}

void	destroy_all_image(t_data *sl)
{
	destroy_img_map(sl);
	destroy_img_pl(sl);
	destroy_img_dog(sl);
	destroy_img_wolf(sl);
}
