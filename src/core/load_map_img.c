/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:26:10 by jcoquard          #+#    #+#             */
/*   Updated: 2024/03/27 16:32:42 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_border_img_2(t_data *sl)
{
	load_img(sl, "texture/border_river_end_l.xpm", &(sl->map.tex[31]));				//	27	
	load_img(sl, "texture/border_river_end_r.xpm", &(sl->map.tex[32]));				//	28	
	load_img(sl, "texture/border_river_end_u.xpm", &(sl->map.tex[33]));				//	29	
	load_img(sl, "texture/border_river_ed.xpm", &(sl->map.tex[34]));				//	30	
	load_img(sl, "texture/border_river_el.xpm", &(sl->map.tex[35]));				//	31	
	load_img(sl, "texture/border_river_er.xpm", &(sl->map.tex[36]));				//	32	
	load_img(sl, "texture/border_river_eu.xpm", &(sl->map.tex[37]));				//	33	
	load_img(sl, "texture/border_turn_dl.xpm", &(sl->map.tex[38]));					//	34
	load_img(sl, "texture/border_turn_dr.xpm", &(sl->map.tex[39]));					//	35
	load_img(sl, "texture/border_turn_ul.xpm", &(sl->map.tex[40]));					//	36
	load_img(sl, "texture/border_turn_ur.xpm", &(sl->map.tex[41]));					//	37
	load_img(sl, "texture/border_river_cross_d.xpm", &(sl->map.tex[42]));			//	38		
	load_img(sl, "texture/border_river_cross_u.xpm", &(sl->map.tex[43]));			//	39		
	load_img(sl, "texture/border_river_cross_l.xpm", &(sl->map.tex[44]));			//	40		
	load_img(sl, "texture/border_river_cross_r.xpm", &(sl->map.tex[45]));			//	41		
	load_img(sl, "texture/border_river_cross_dul.xpm", &(sl->map.tex[46]));			//	42		
	load_img(sl, "texture/border_river_cross_dur.xpm", &(sl->map.tex[47]));			//	43		
	load_img(sl, "texture/border_river_cross_ldl.xpm", &(sl->map.tex[48]));			//	44		
	load_img(sl, "texture/border_river_cross_lul.xpm", &(sl->map.tex[49]));			//	45		
	load_img(sl, "texture/border_river_cross_rdr.xpm", &(sl->map.tex[50]));			//	46		
	load_img(sl, "texture/border_river_cross_rur.xpm", &(sl->map.tex[51]));			//	47		
	load_img(sl, "texture/border_river_cross_udl.xpm", &(sl->map.tex[52]));			//	48		
	load_img(sl, "texture/border_river_cross_udr.xpm", &(sl->map.tex[53]));			//	49		
	load_img(sl, "texture/border_river_cross.xpm", &(sl->map.tex[54]));				//	50	
}

static void	map_border_img_1(t_data *sl)
{
	//4
	load_img(sl, "texture/border_d.xpm", &(sl->map.tex[9]));						//5
	load_img(sl, "texture/border_u.xpm", &(sl->map.tex[10]));						//6
	load_img(sl, "texture/border_l.xpm", &(sl->map.tex[11]));						//7
	load_img(sl, "texture/border_r.xpm", &(sl->map.tex[12]));						//8
	load_img(sl, "texture/border_dr.xpm", &(sl->map.tex[13]));						//9
	load_img(sl, "texture/border_dl.xpm", &(sl->map.tex[14]));						//10
	load_img(sl, "texture/border_ul.xpm", &(sl->map.tex[15]));						//11
	load_img(sl, "texture/border_ur.xpm", &(sl->map.tex[16]));						//12
	load_img(sl, "texture/border_river_h.xpm", &(sl->map.tex[17]));					//	13
	load_img(sl, "texture/border_river_v.xpm", &(sl->map.tex[18]));					//	14
	load_img(sl, "texture/border_corner_ld.xpm", &(sl->map.tex[19]));				//	15	
	load_img(sl, "texture/border_corner_lu.xpm", &(sl->map.tex[20]));				//	16	
	load_img(sl, "texture/border_corner_rd.xpm", &(sl->map.tex[21]));				//	17	
	load_img(sl, "texture/border_corner_ru.xpm", &(sl->map.tex[22]));				//	18	
	load_img(sl, "texture/border_empty.xpm", &(sl->map.tex[23]));					//	19
	load_img(sl, "texture/border_cross_dlur.xpm", &(sl->map.tex[24]));				//	20	
	load_img(sl, "texture/border_cross_drul.xpm", &(sl->map.tex[25]));				//	21	
	load_img(sl, "texture/border_river_cross_dl.xpm", &(sl->map.tex[26]));			//	22		
	load_img(sl, "texture/border_river_cross_dr.xpm", &(sl->map.tex[27]));			//	23		
	load_img(sl, "texture/border_river_cross_ul.xpm", &(sl->map.tex[28]));			//	24		
	load_img(sl, "texture/border_river_cross_ur.xpm", &(sl->map.tex[29]));			//	25		
	load_img(sl, "texture/border_river_end_d.xpm", &(sl->map.tex[30]));				//	26	
	
}

static void	map_base_img(t_data *sl)
{
	load_img(sl, "texture/border_empty.xpm", &(sl->map.tex[0]));					//51
	load_img(sl, "texture/grass_empty.xpm", &(sl->map.tex[1]));						//0
	load_img(sl, "texture/grass_alt.xpm", &(sl->map.tex[2]));						//1
	load_img(sl, "texture/grass_alt_2.xpm", &(sl->map.tex[3]));						//2
	load_img(sl, "texture/stone.xpm", &(sl->map.tex[4]));							//3
	load_img(sl, "texture/stone_alt.xpm", &(sl->map.tex[5]));						//4
	load_img(sl, "texture/end_closed.xpm", &(sl->map.tex[6]));						//52
	load_img(sl, "texture/end_open.xpm", &(sl->map.tex[7]));//a clear				//53
	load_img(sl, "texture/collectible.xpm", &(sl->map.tex[8]));				//55
}

void	load_map_img(t_data *sl)
{
	map_base_img(sl);
	map_border_img_1(sl);
	map_border_img_2(sl);
}