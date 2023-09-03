/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:36:17 by jcoquard          #+#    #+#             */
/*   Updated: 2023/08/21 17:30:02 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	load_map_img(t_data *sl)
{
	(void)sl;
	load_img(sl, "data/texture/grass_empty.xpm", &(sl->map.tex[0]));
	load_img(sl, "data/texture/grass_alt.xpm", &(sl->map.tex[1]));
	load_img(sl, "data/texture/grass_alt_2.xpm", &(sl->map.tex[2]));
	load_img(sl, "data/texture/stone.xpm", &(sl->map.tex[3]));
	load_img(sl, "data/texture/stone_alt.xpm", &(sl->map.tex[4]));
	load_img(sl, "data/texture/border_d.xpm", &(sl->map.tex[5]));
	load_img(sl, "data/texture/border_u.xpm", &(sl->map.tex[6]));
	load_img(sl, "data/texture/border_l.xpm", &(sl->map.tex[7]));
	load_img(sl, "data/texture/border_r.xpm", &(sl->map.tex[8]));
	load_img(sl, "data/texture/border_dr.xpm", &(sl->map.tex[9]));
	load_img(sl, "data/texture/border_dl.xpm", &(sl->map.tex[10]));
	load_img(sl, "data/texture/border_ul.xpm", &(sl->map.tex[11]));
	load_img(sl, "data/texture/border_ur.xpm", &(sl->map.tex[12]));
	load_img(sl, "data/texture/border_riverh.xpm", &(sl->map.tex[13]));
	load_img(sl, "data/texture/border_riverv.xpm", &(sl->map.tex[14]));
	load_img(sl, "data/texture/border_cornerld.xpm", &(sl->map.tex[15]));
	load_img(sl, "data/texture/border_cornerlu.xpm", &(sl->map.tex[16]));
	load_img(sl, "data/texture/border_cornerrd.xpm", &(sl->map.tex[17]));
	load_img(sl, "data/texture/border_cornerru.xpm", &(sl->map.tex[18]));
	load_img(sl, "data/texture/border_empty.xpm", &(sl->map.tex[19]));
	load_img(sl, "data/texture/border_crossdlur.xpm", &(sl->map.tex[20]));
	load_img(sl, "data/texture/border_crossdrul.xpm", &(sl->map.tex[21]));
	load_img(sl, "data/texture/border_river_crossdl.xpm", &(sl->map.tex[22]));
	load_img(sl, "data/texture/border_river_crossdr.xpm", &(sl->map.tex[23]));
	load_img(sl, "data/texture/border_river_crossul.xpm", &(sl->map.tex[24]));
	load_img(sl, "data/texture/border_river_crossur.xpm", &(sl->map.tex[25]));
	load_img(sl, "data/texture/border_river_endd.xpm", &(sl->map.tex[26]));
	load_img(sl, "data/texture/border_river_endl.xpm", &(sl->map.tex[27]));
	load_img(sl, "data/texture/border_river_endr.xpm", &(sl->map.tex[28]));
	load_img(sl, "data/texture/border_river_endu.xpm", &(sl->map.tex[29]));
	load_img(sl, "data/texture/border_river_ed.xpm", &(sl->map.tex[30]));
	load_img(sl, "data/texture/border_river_el.xpm", &(sl->map.tex[31]));
	load_img(sl, "data/texture/border_river_er.xpm", &(sl->map.tex[32]));
	load_img(sl, "data/texture/border_river_eu.xpm", &(sl->map.tex[33]));
	load_img(sl, "data/texture/border_turndl.xpm", &(sl->map.tex[34]));
	load_img(sl, "data/texture/border_turndr.xpm", &(sl->map.tex[35]));
	load_img(sl, "data/texture/border_turnul.xpm", &(sl->map.tex[36]));
	load_img(sl, "data/texture/border_turnur.xpm", &(sl->map.tex[37]));
	load_img(sl, "data/texture/border_river_crossd.xpm", &(sl->map.tex[38]));
	load_img(sl, "data/texture/border_river_crossu.xpm", &(sl->map.tex[39]));
	load_img(sl, "data/texture/border_river_crossl.xpm", &(sl->map.tex[40]));
	load_img(sl, "data/texture/border_river_crossr.xpm", &(sl->map.tex[41]));
	load_img(sl, "data/texture/border_river_crossdul.xpm", &(sl->map.tex[42]));
	load_img(sl, "data/texture/border_river_crossdur.xpm", &(sl->map.tex[43]));
	load_img(sl, "data/texture/border_river_crossldl.xpm", &(sl->map.tex[44]));
	load_img(sl, "data/texture/border_river_crosslul.xpm", &(sl->map.tex[45]));
	load_img(sl, "data/texture/border_river_crossrdr.xpm", &(sl->map.tex[46]));
	load_img(sl, "data/texture/border_river_crossrur.xpm", &(sl->map.tex[47]));
	load_img(sl, "data/texture/border_river_crossudl.xpm", &(sl->map.tex[48]));
	load_img(sl, "data/texture/border_river_crossudr.xpm", &(sl->map.tex[49]));
	load_img(sl, "data/texture/border_river_cross.xpm", &(sl->map.tex[50]));
	load_img(sl, "data/texture/border_empty.xpm", &(sl->map.tex[51]));
	load_img(sl, "data/texture/end_empty.xpm", &(sl->map.tex[52]));
	load_img(sl, "data/texture/end_inprogress.xpm", &(sl->map.tex[53]));
	load_img(sl, "data/texture/end_full.xpm", &(sl->map.tex[54]));
	load_img(sl, "data/texture/collectible_empty.xpm", &(sl->map.tex[55]));
	load_img(sl, "data/texture/collectible.xpm", &(sl->map.tex[56]));
}

static void	load_pl_img(t_data *sl)
{
	load_img(sl, "data/texture/pl_front.xpm", &(sl->pl.tex[0][0]));
	load_img(sl, "data/texture/pl_front_walk1.xpm", &(sl->pl.tex[0][1]));
	load_img(sl, "data/texture/pl_front.xpm", &(sl->pl.tex[0][2]));
	load_img(sl, "data/texture/pl_front_walk2.xpm", &(sl->pl.tex[0][3]));
	load_img(sl, "data/texture/pl_back.xpm", &(sl->pl.tex[1][0]));
	load_img(sl, "data/texture/pl_back_walk1.xpm", &(sl->pl.tex[1][1]));
	load_img(sl, "data/texture/pl_back.xpm", &(sl->pl.tex[1][2]));
	load_img(sl, "data/texture/pl_back_walk2.xpm", &(sl->pl.tex[1][3]));
	load_img(sl, "data/texture/pl_right.xpm", &(sl->pl.tex[2][0]));
	load_img(sl, "data/texture/pl_right_walk1.xpm", &(sl->pl.tex[2][1]));
	load_img(sl, "data/texture/pl_right.xpm", &(sl->pl.tex[2][2]));
	load_img(sl, "data/texture/pl_right_walk2.xpm", &(sl->pl.tex[2][3]));
	load_img(sl, "data/texture/pl_left.xpm", &(sl->pl.tex[3][0]));
	load_img(sl, "data/texture/pl_left_walk1.xpm", &(sl->pl.tex[3][1]));
	load_img(sl, "data/texture/pl_left.xpm", &(sl->pl.tex[3][2]));
	load_img(sl, "data/texture/pl_left_walk2.xpm", &(sl->pl.tex[3][3]));
	load_img(sl, "data/texture/pl_pet_heart.xpm", &(sl->pl.tex[4][0]));
	load_img(sl, "data/texture/pl_front.xpm", &(sl->pl.tex[4][1]));
	load_img(sl, "data/texture/pl_killed.xpm", &(sl->pl.tex[4][2]));
}

static void	load_dog_img(t_data *sl)
{
	load_img(sl, "data/texture/dog_front.xpm", &(sl->dog[0].tex[0][0]));
	load_img(sl, "data/texture/dog_front_walk1.xpm", &(sl->dog[0].tex[0][1]));
	load_img(sl, "data/texture/dog_front.xpm", &(sl->dog[0].tex[0][2]));
	load_img(sl, "data/texture/dog_front_walk2.xpm", &(sl->dog[0].tex[0][3]));
	load_img(sl, "data/texture/dog_back.xpm", &(sl->dog[0].tex[1][0]));
	load_img(sl, "data/texture/dog_back_walk1.xpm", &(sl->dog[0].tex[1][1]));
	load_img(sl, "data/texture/dog_back.xpm", &(sl->dog[0].tex[1][2]));
	load_img(sl, "data/texture/dog_back_walk2.xpm", &(sl->dog[0].tex[1][3]));
	load_img(sl, "data/texture/dog_right.xpm", &(sl->dog[0].tex[2][0]));
	load_img(sl, "data/texture/dog_right_walk1.xpm", &(sl->dog[0].tex[2][1]));
	load_img(sl, "data/texture/dog_right.xpm", &(sl->dog[0].tex[2][2]));
	load_img(sl, "data/texture/dog_right_walk2.xpm", &(sl->dog[0].tex[2][3]));
	load_img(sl, "data/texture/dog_left.xpm", &(sl->dog[0].tex[3][0]));
	load_img(sl, "data/texture/dog_left_walk1.xpm", &(sl->dog[0].tex[3][1]));
	load_img(sl, "data/texture/dog_left.xpm", &(sl->dog[0].tex[3][2]));
	load_img(sl, "data/texture/dog_left_walk2.xpm", &(sl->dog[0].tex[3][3]));
	load_img(sl, "data/texture/dog_lay.xpm", &(sl->dog[0].tex[4][0]));
}

static void	load_wolf_img(t_data *sl)
{
	load_img(sl, "data/texture/test/pl_front.xpm", &(sl->wolf.tex[0][0]));
	load_img(sl, "data/texture/test/pl_front_walk1.xpm", &(sl->wolf.tex[0][1]));
	load_img(sl, "data/texture/test/pl_front.xpm", &(sl->wolf.tex[0][2]));
	load_img(sl, "data/texture/test/pl_front_walk2.xpm", &(sl->wolf.tex[0][3]));
	load_img(sl, "data/texture/test/pl_back.xpm", &(sl->wolf.tex[1][0]));
	load_img(sl, "data/texture/test/pl_back_walk1.xpm", &(sl->wolf.tex[1][1]));
	load_img(sl, "data/texture/test/pl_back.xpm", &(sl->wolf.tex[1][2]));
	load_img(sl, "data/texture/test/pl_back_walk2.xpm", &(sl->wolf.tex[1][3]));
	load_img(sl, "data/texture/test/pl_right.xpm", &(sl->wolf.tex[2][0]));
	load_img(sl, "data/texture/test/pl_right_walk1.xpm", &(sl->wolf.tex[2][1]));
	load_img(sl, "data/texture/test/pl_right.xpm", &(sl->wolf.tex[2][2]));
	load_img(sl, "data/texture/test/pl_right_walk2.xpm", &(sl->wolf.tex[2][3]));
	load_img(sl, "data/texture/test/pl_left.xpm", &(sl->wolf.tex[3][0]));
	load_img(sl, "data/texture/test/pl_left_walk1.xpm", &(sl->wolf.tex[3][1]));
	load_img(sl, "data/texture/test/pl_left.xpm", &(sl->wolf.tex[3][2]));
	load_img(sl, "data/texture/test/pl_left_walk2.xpm", &(sl->wolf.tex[3][3]));
	load_img(sl, "data/texture/test/pl_kill1.xpm", &(sl->wolf.tex[4][1]));
	load_img(sl, "data/texture/test/pl_kill2.xpm", &(sl->wolf.tex[4][2]));
}

void	load_all_image(t_data *sl)
{
	load_map_img(sl);
	load_pl_img(sl);
	load_dog_img(sl);
	load_wolf_img(sl);
}
