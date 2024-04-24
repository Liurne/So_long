/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:25:14 by jcoquard          #+#    #+#             */
/*   Updated: 2024/04/23 23:20:29 by liurne           ###   ########.fr       */
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

static void	destroy_img_dog(t_data *sl)
{
	destroy_img(sl, &(sl->tex_dog[0][0]));
	destroy_img(sl, &(sl->tex_dog[0][1]));
	destroy_img(sl, &(sl->tex_dog[0][2]));
	destroy_img(sl, &(sl->tex_dog[0][3]));
	destroy_img(sl, &(sl->tex_dog[1][0]));
	destroy_img(sl, &(sl->tex_dog[1][1]));
	destroy_img(sl, &(sl->tex_dog[1][2]));
	destroy_img(sl, &(sl->tex_dog[1][3]));
	destroy_img(sl, &(sl->tex_dog[2][0]));
	destroy_img(sl, &(sl->tex_dog[2][1]));
	destroy_img(sl, &(sl->tex_dog[2][2]));
	destroy_img(sl, &(sl->tex_dog[2][3]));
	destroy_img(sl, &(sl->tex_dog[3][0]));
	destroy_img(sl, &(sl->tex_dog[3][1]));
	destroy_img(sl, &(sl->tex_dog[3][2]));
	destroy_img(sl, &(sl->tex_dog[3][3]));
	destroy_img(sl, &(sl->tex_dog[4][0]));
	destroy_img(sl, &(sl->tex_dog[4][1]));
	destroy_img(sl, &(sl->tex_dog[4][2]));
	destroy_img(sl, &(sl->tex_dog[4][3]));
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
	while (i < 55)
	{
		destroy_img(sl, &(sl->map.tex[i]));
		i++;
	}
}

void	destroy_all_image(t_data *sl)
{
	destroy_img_map(sl);
	destroy_img_pl(sl);
	destroy_img_dog(sl);
	destroy_img_wolf(sl);
}
