/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:36:17 by jcoquard          #+#    #+#             */
/*   Updated: 2024/04/23 23:22:03 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_pl_img(t_data *sl)
{
	load_img(sl, "asset/texture/player/pl_d.xpm", &(sl->tex_pl[0][0]));
	load_img(sl, "asset/texture/player/pl_walk_d_1.xpm", &(sl->tex_pl[0][1]));
	load_img(sl, "asset/texture/player/pl_d.xpm", &(sl->tex_pl[0][2]));
	load_img(sl, "asset/texture/player/pl_walk_d_2.xpm", &(sl->tex_pl[0][3]));
	load_img(sl, "asset/texture/player/pl_pet_d_1.xpm", &(sl->tex_pl[0][4]));
	load_img(sl, "asset/texture/player/pl_pet_d_2.xpm", &(sl->tex_pl[0][5]));
	load_img(sl, "asset/texture/player/pl_u.xpm", &(sl->tex_pl[1][0]));
	load_img(sl, "asset/texture/player/pl_walk_u_1.xpm", &(sl->tex_pl[1][1]));
	load_img(sl, "asset/texture/player/pl_u.xpm", &(sl->tex_pl[1][2]));
	load_img(sl, "asset/texture/player/pl_walk_u_2.xpm", &(sl->tex_pl[1][3]));
	load_img(sl, "asset/texture/player/pl_pet_u_1.xpm", &(sl->tex_pl[1][4]));
	load_img(sl, "asset/texture/player/pl_pet_u_2.xpm", &(sl->tex_pl[1][5]));
	load_img(sl, "asset/texture/player/pl_r.xpm", &(sl->tex_pl[2][0]));
	load_img(sl, "asset/texture/player/pl_walk_r_1.xpm", &(sl->tex_pl[2][1]));
	load_img(sl, "asset/texture/player/pl_r.xpm", &(sl->tex_pl[2][2]));
	load_img(sl, "asset/texture/player/pl_walk_r_2.xpm", &(sl->tex_pl[2][3]));
	load_img(sl, "asset/texture/player/pl_l.xpm", &(sl->tex_pl[3][0]));
	load_img(sl, "asset/texture/player/pl_walk_l_1.xpm", &(sl->tex_pl[3][1]));
	load_img(sl, "asset/texture/player/pl_l.xpm", &(sl->tex_pl[3][2]));
	load_img(sl, "asset/texture/player/pl_walk_l_2.xpm", &(sl->tex_pl[3][3]));
	load_img(sl, "asset/texture/player/pl_d.xpm", &(sl->tex_pl[4][2]));
	load_img(sl, "asset/texture/player/pl_killed.xpm", &(sl->tex_pl[4][3]));
}

static void	load_dog_img(t_data *sl)
{
	load_img(sl, "asset/texture/cat/cat_down_1.xpm", &(sl->tex_dog[0][0]));
	load_img(sl, "asset/texture/cat/cat_down_walk_1.xpm", &(sl->tex_dog[0][1]));
	load_img(sl, "asset/texture/cat/cat_down_2.xpm", &(sl->tex_dog[0][2]));
	load_img(sl, "asset/texture/cat/cat_down_walk_2.xpm", &(sl->tex_dog[0][3]));
	load_img(sl, "asset/texture/cat/cat_up_1.xpm", &(sl->tex_dog[1][0]));
	load_img(sl, "asset/texture/cat/cat_up_walk_1.xpm", &(sl->tex_dog[1][1]));
	load_img(sl, "asset/texture/cat/cat_up_2.xpm", &(sl->tex_dog[1][2]));
	load_img(sl, "asset/texture/cat/cat_up_walk_2.xpm", &(sl->tex_dog[1][3]));
	load_img(sl, "asset/texture/cat/cat_right_1.xpm", &(sl->tex_dog[2][0]));
	load_img(sl,
		"asset/texture/cat/cat_right_walk_1.xpm", &(sl->tex_dog[2][1]));
	load_img(sl, "asset/texture/cat/cat_right_2.xpm", &(sl->tex_dog[2][2]));
	load_img(sl,
		"asset/texture/cat/cat_right_walk_2.xpm", &(sl->tex_dog[2][3]));
	load_img(sl, "asset/texture/cat/cat_left_1.xpm", &(sl->tex_dog[3][0]));
	load_img(sl, "asset/texture/cat/cat_left_walk_1.xpm", &(sl->tex_dog[3][1]));
	load_img(sl, "asset/texture/cat/cat_left_2.xpm", &(sl->tex_dog[3][2]));
	load_img(sl, "asset/texture/cat/cat_left_walk_2.xpm", &(sl->tex_dog[3][3]));
	load_img(sl, "asset/texture/cat/cat_sleep.xpm", &(sl->tex_dog[4][0]));
	load_img(sl, "asset/texture/cat/cat_heart_1.xpm", &(sl->tex_dog[4][1]));
	load_img(sl, "asset/texture/cat/cat_heart_2.xpm", &(sl->tex_dog[4][2]));
	load_img(sl, "asset/texture/cat/cat_heart_3.xpm", &(sl->tex_dog[4][3]));
}

static void	load_wolf_img(t_data *sl)
{
	load_img(sl, "asset/texture/bad/pl_front.xpm", &(sl->tex_wolf[0][0]));
	load_img(sl, "asset/texture/bad/pl_front_walk1.xpm", &(sl->tex_wolf[0][1]));
	load_img(sl, "asset/texture/bad/pl_front.xpm", &(sl->tex_wolf[0][2]));
	load_img(sl, "asset/texture/bad/pl_front_walk2.xpm", &(sl->tex_wolf[0][3]));
	load_img(sl, "asset/texture/bad/pl_back.xpm", &(sl->tex_wolf[1][0]));
	load_img(sl, "asset/texture/bad/pl_back_walk1.xpm", &(sl->tex_wolf[1][1]));
	load_img(sl, "asset/texture/bad/pl_back.xpm", &(sl->tex_wolf[1][2]));
	load_img(sl, "asset/texture/bad/pl_back_walk2.xpm", &(sl->tex_wolf[1][3]));
	load_img(sl, "asset/texture/bad/pl_right.xpm", &(sl->tex_wolf[2][0]));
	load_img(sl, "asset/texture/bad/pl_right_walk1.xpm", &(sl->tex_wolf[2][1]));
	load_img(sl, "asset/texture/bad/pl_right.xpm", &(sl->tex_wolf[2][2]));
	load_img(sl, "asset/texture/bad/pl_right_walk2.xpm", &(sl->tex_wolf[2][3]));
	load_img(sl, "asset/texture/bad/pl_left.xpm", &(sl->tex_wolf[3][0]));
	load_img(sl, "asset/texture/bad/pl_left_walk1.xpm", &(sl->tex_wolf[3][1]));
	load_img(sl, "asset/texture/bad/pl_left.xpm", &(sl->tex_wolf[3][2]));
	load_img(sl, "asset/texture/bad/pl_left_walk2.xpm", &(sl->tex_wolf[3][3]));
	load_img(sl, "asset/texture/bad/pl_kill1.xpm", &(sl->tex_wolf[4][1]));
	load_img(sl, "asset/texture/bad/pl_kill2.xpm", &(sl->tex_wolf[4][2]));
}

void	load_all_image(t_data *sl)
{
	load_map_img(sl);
	load_pl_img(sl);
	load_dog_img(sl);
	load_wolf_img(sl);
}
