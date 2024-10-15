/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:26:10 by jcoquard          #+#    #+#             */
/*   Updated: 2024/10/15 18:42:25 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_border_img_1(t_data *sl)
{
	load_img(sl, "assets/texture/map/border_d.xpm", &(sl->map.tex[9]));
	load_img(sl, "assets/texture/map/border_u.xpm", &(sl->map.tex[10]));
	load_img(sl, "assets/texture/map/border_l.xpm", &(sl->map.tex[11]));
	load_img(sl, "assets/texture/map/border_r.xpm", &(sl->map.tex[12]));
	load_img(sl, "assets/texture/map/border_dr.xpm", &(sl->map.tex[13]));
	load_img(sl, "assets/texture/map/border_dl.xpm", &(sl->map.tex[14]));
	load_img(sl, "assets/texture/map/border_ul.xpm", &(sl->map.tex[15]));
	load_img(sl, "assets/texture/map/border_ur.xpm", &(sl->map.tex[16]));
	load_img(sl, "assets/texture/map/border_river_h.xpm", &(sl->map.tex[17]));
	load_img(sl, "assets/texture/map/border_river_v.xpm", &(sl->map.tex[18]));
	load_img(sl, "assets/texture/map/border_corner_ld.xpm", &(sl->map.tex[19]));
	load_img(sl, "assets/texture/map/border_corner_lu.xpm", &(sl->map.tex[20]));
	load_img(sl, "assets/texture/map/border_corner_rd.xpm", &(sl->map.tex[21]));
	load_img(sl, "assets/texture/map/border_corner_ru.xpm", &(sl->map.tex[22]));
	load_img(sl, "assets/texture/map/border_empty.xpm", &(sl->map.tex[23]));
	load_img(sl, "assets/texture/map/border_cross_dlur.xpm",
		&(sl->map.tex[24]));
	load_img(sl, "assets/texture/map/border_cross_drul.xpm",
		&(sl->map.tex[25]));
	load_img(sl,
		"assets/texture/map/border_river_cross_dl.xpm", &(sl->map.tex[26]));
}

static void	map_border_img_2(t_data *sl)
{
	load_img(sl,
		"assets/texture/map/border_river_cross_dr.xpm", &(sl->map.tex[27]));
	load_img(sl,
		"assets/texture/map/border_river_cross_ul.xpm", &(sl->map.tex[28]));
	load_img(sl,
		"assets/texture/map/border_river_cross_ur.xpm", &(sl->map.tex[29]));
	load_img(sl,
		"assets/texture/map/border_river_end_d.xpm", &(sl->map.tex[30]));
	load_img(sl,
		"assets/texture/map/border_river_end_l.xpm", &(sl->map.tex[31]));
	load_img(sl,
		"assets/texture/map/border_river_end_r.xpm", &(sl->map.tex[32]));
	load_img(sl,
		"assets/texture/map/border_river_end_u.xpm", &(sl->map.tex[33]));
	load_img(sl, "assets/texture/map/border_river_ed.xpm", &(sl->map.tex[34]));
	load_img(sl, "assets/texture/map/border_river_el.xpm", &(sl->map.tex[35]));
	load_img(sl, "assets/texture/map/border_river_er.xpm", &(sl->map.tex[36]));
	load_img(sl, "assets/texture/map/border_river_eu.xpm", &(sl->map.tex[37]));
	load_img(sl, "assets/texture/map/border_turn_dl.xpm", &(sl->map.tex[38]));
	load_img(sl, "assets/texture/map/border_turn_dr.xpm", &(sl->map.tex[39]));
	load_img(sl, "assets/texture/map/border_turn_ul.xpm", &(sl->map.tex[40]));
	load_img(sl, "assets/texture/map/border_turn_ur.xpm", &(sl->map.tex[41]));
	load_img(sl,
		"assets/texture/map/border_river_cross_d.xpm", &(sl->map.tex[42]));
}

static void	map_border_img_3(t_data *sl)
{
	load_img(sl,
		"assets/texture/map/border_river_cross_u.xpm", &(sl->map.tex[43]));
	load_img(sl,
		"assets/texture/map/border_river_cross_l.xpm", &(sl->map.tex[44]));
	load_img(sl,
		"assets/texture/map/border_river_cross_r.xpm", &(sl->map.tex[45]));
	load_img(sl,
		"assets/texture/map/border_river_cross_dul.xpm", &(sl->map.tex[46]));
	load_img(sl,
		"assets/texture/map/border_river_cross_dur.xpm", &(sl->map.tex[47]));
	load_img(sl,
		"assets/texture/map/border_river_cross_ldl.xpm", &(sl->map.tex[48]));
	load_img(sl,
		"assets/texture/map/border_river_cross_lul.xpm", &(sl->map.tex[49]));
	load_img(sl,
		"assets/texture/map/border_river_cross_rdr.xpm", &(sl->map.tex[50]));
	load_img(sl,
		"assets/texture/map/border_river_cross_rur.xpm", &(sl->map.tex[51]));
	load_img(sl,
		"assets/texture/map/border_river_cross_udl.xpm", &(sl->map.tex[52]));
	load_img(sl,
		"assets/texture/map/border_river_cross_udr.xpm", &(sl->map.tex[53]));
	load_img(sl,
		"assets/texture/map/border_river_cross.xpm", &(sl->map.tex[54]));
}

static void	map_base_img(t_data *sl)
{
	load_img(sl, "assets/texture/map/border_empty.xpm", &(sl->map.tex[0]));
	sl->col_ocean = get_pixel(&sl->map.tex[0], 0, 0);
	load_img(sl, "assets/texture/map/grass_empty.xpm", &(sl->map.tex[1]));
	load_img(sl, "assets/texture/map/grass_alt.xpm", &(sl->map.tex[2]));
	load_img(sl, "assets/texture/map/grass_alt_2.xpm", &(sl->map.tex[3]));
	load_img(sl, "assets/texture/map/stone.xpm", &(sl->map.tex[4]));
	load_img(sl, "assets/texture/map/stone_alt.xpm", &(sl->map.tex[5]));
	load_img(sl, "assets/texture/map/end_closed.xpm", &(sl->map.tex[6]));
	load_img(sl, "assets/texture/map/end_open.xpm", &(sl->map.tex[7]));
	load_img(sl, "assets/texture/map/collectible.xpm", &(sl->map.tex[8]));
	load_img(sl, "assets/texture/map/collectible_cat.xpm", &(sl->map.tex[55]));
	load_img(sl, "assets/texture/map/player_spawn.xpm", &(sl->map.tex[56]));
}

void	load_map_img(t_data *sl)
{
	map_base_img(sl);
	map_border_img_1(sl);
	map_border_img_2(sl);
	map_border_img_3(sl);
}
