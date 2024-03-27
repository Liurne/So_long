/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:36:17 by jcoquard          #+#    #+#             */
/*   Updated: 2024/03/27 16:31:14 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
static void	load_map_img(t_data *sl)
{
	load_img(sl, "texture/grass_empty.xpm", &(sl->map.tex[0]));						//0
	load_img(sl, "texture/grass_alt.xpm", &(sl->map.tex[1]));						//1
	load_img(sl, "texture/grass_alt_2.xpm", &(sl->map.tex[2]));						//2
	load_img(sl, "texture/stone.xpm", &(sl->map.tex[3]));							//3
	load_img(sl, "texture/stone_alt.xpm", &(sl->map.tex[4]));						//4
	load_img(sl, "texture/border_d.xpm", &(sl->map.tex[5]));						//5
	load_img(sl, "texture/border_u.xpm", &(sl->map.tex[6]));						//6
	load_img(sl, "texture/border_l.xpm", &(sl->map.tex[7]));						//7
	load_img(sl, "texture/border_r.xpm", &(sl->map.tex[8]));						//8
	load_img(sl, "texture/border_dr.xpm", &(sl->map.tex[9]));						//9
	load_img(sl, "texture/border_dl.xpm", &(sl->map.tex[10]));						//10
	load_img(sl, "texture/border_ul.xpm", &(sl->map.tex[11]));						//11
	load_img(sl, "texture/border_ur.xpm", &(sl->map.tex[12]));						//12
	load_img(sl, "texture/border_river_h.xpm", &(sl->map.tex[13]));					//	13
	load_img(sl, "texture/border_river_v.xpm", &(sl->map.tex[14]));					//	14
	load_img(sl, "texture/border_corner_ld.xpm", &(sl->map.tex[15]));				//	15	
	load_img(sl, "texture/border_corner_lu.xpm", &(sl->map.tex[16]));				//	16	
	load_img(sl, "texture/border_corner_rd.xpm", &(sl->map.tex[17]));				//	17	
	load_img(sl, "texture/border_corner_ru.xpm", &(sl->map.tex[18]));				//	18	
	load_img(sl, "texture/border_empty.xpm", &(sl->map.tex[19]));					//	19
	load_img(sl, "texture/border_cross_dlur.xpm", &(sl->map.tex[20]));				//	20	
	load_img(sl, "texture/border_cross_drul.xpm", &(sl->map.tex[21]));				//	21	
	load_img(sl, "texture/border_river_cross_dl.xpm", &(sl->map.tex[22]));			//	22		
	load_img(sl, "texture/border_river_cross_dr.xpm", &(sl->map.tex[23]));			//	23		
	load_img(sl, "texture/border_river_cross_ul.xpm", &(sl->map.tex[24]));			//	24		
	load_img(sl, "texture/border_river_cross_ur.xpm", &(sl->map.tex[25]));			//	25		
	load_img(sl, "texture/border_river_end_d.xpm", &(sl->map.tex[26]));				//	26	
	load_img(sl, "texture/border_river_end_l.xpm", &(sl->map.tex[27]));				//	27	
	load_img(sl, "texture/border_river_end_r.xpm", &(sl->map.tex[28]));				//	28	
	load_img(sl, "texture/border_river_end_u.xpm", &(sl->map.tex[29]));				//	29	
	load_img(sl, "texture/border_river_ed.xpm", &(sl->map.tex[30]));				//	30	
	load_img(sl, "texture/border_river_el.xpm", &(sl->map.tex[31]));				//	31	
	load_img(sl, "texture/border_river_er.xpm", &(sl->map.tex[32]));				//	32	
	load_img(sl, "texture/border_river_eu.xpm", &(sl->map.tex[33]));				//	33	
	load_img(sl, "texture/border_turn_dl.xpm", &(sl->map.tex[34]));					//	34
	load_img(sl, "texture/border_turn_dr.xpm", &(sl->map.tex[35]));					//	35
	load_img(sl, "texture/border_turn_ul.xpm", &(sl->map.tex[36]));					//	36
	load_img(sl, "texture/border_turn_ur.xpm", &(sl->map.tex[37]));					//	37
	load_img(sl, "texture/border_river_cross_d.xpm", &(sl->map.tex[38]));			//	38		
	load_img(sl, "texture/border_river_cross_u.xpm", &(sl->map.tex[39]));			//	39		
	load_img(sl, "texture/border_river_cross_l.xpm", &(sl->map.tex[40]));			//	40		
	load_img(sl, "texture/border_river_cross_r.xpm", &(sl->map.tex[41]));			//	41		
	load_img(sl, "texture/border_river_cross_dul.xpm", &(sl->map.tex[42]));			//	42		
	load_img(sl, "texture/border_river_cross_dur.xpm", &(sl->map.tex[43]));			//	43		
	load_img(sl, "texture/border_river_cross_ldl.xpm", &(sl->map.tex[44]));			//	44		
	load_img(sl, "texture/border_river_cross_lul.xpm", &(sl->map.tex[45]));			//	45		
	load_img(sl, "texture/border_river_cross_rdr.xpm", &(sl->map.tex[46]));			//	46		
	load_img(sl, "texture/border_river_cross_rur.xpm", &(sl->map.tex[47]));			//	47		
	load_img(sl, "texture/border_river_cross_udl.xpm", &(sl->map.tex[48]));			//	48		
	load_img(sl, "texture/border_river_cross_udr.xpm", &(sl->map.tex[49]));			//	49		
	load_img(sl, "texture/border_river_cross.xpm", &(sl->map.tex[50]));				//	50	
	load_img(sl, "texture/border_empty.xpm", &(sl->map.tex[51]));					//	51
	load_img(sl, "texture/end_empty.xpm", &(sl->map.tex[52]));						//52
	load_img(sl, "texture/end_full.xpm", &(sl->map.tex[53]));//a clear				//	53	
	load_img(sl, "texture/end_full.xpm", &(sl->map.tex[54]));						//54
	load_img(sl, "texture/collectible_empty.xpm", &(sl->map.tex[55]));				//	55	
	load_img(sl, "texture/collectible_empty.xpm", &(sl->map.tex[56]));//a clear		//	56			
}
*/
static void	load_pl_img(t_data *sl)
{
	load_img(sl, "texture/pl_front.xpm", &(sl->tex_pl[0][0]));
	load_img(sl, "texture/pl_front_walk1.xpm", &(sl->tex_pl[0][1]));
	load_img(sl, "texture/pl_front.xpm", &(sl->tex_pl[0][2]));
	load_img(sl, "texture/pl_front_walk2.xpm", &(sl->tex_pl[0][3]));
	load_img(sl, "texture/pl_back.xpm", &(sl->tex_pl[1][0]));
	load_img(sl, "texture/pl_back_walk1.xpm", &(sl->tex_pl[1][1]));
	load_img(sl, "texture/pl_back.xpm", &(sl->tex_pl[1][2]));
	load_img(sl, "texture/pl_back_walk2.xpm", &(sl->tex_pl[1][3]));
	load_img(sl, "texture/pl_right.xpm", &(sl->tex_pl[2][0]));
	load_img(sl, "texture/pl_right_walk1.xpm", &(sl->tex_pl[2][1]));
	load_img(sl, "texture/pl_right.xpm", &(sl->tex_pl[2][2]));
	load_img(sl, "texture/pl_right_walk2.xpm", &(sl->tex_pl[2][3]));
	load_img(sl, "texture/pl_left.xpm", &(sl->tex_pl[3][0]));
	load_img(sl, "texture/pl_left_walk1.xpm", &(sl->tex_pl[3][1]));
	load_img(sl, "texture/pl_left.xpm", &(sl->tex_pl[3][2]));
	load_img(sl, "texture/pl_left_walk2.xpm", &(sl->tex_pl[3][3]));
	load_img(sl, "texture/pl_pet_heart.xpm", &(sl->tex_pl[4][0]));
	load_img(sl, "texture/pl_front.xpm", &(sl->tex_pl[4][1]));
	load_img(sl, "texture/pl_killed.xpm", &(sl->tex_pl[4][2]));
}

static void	load_dog_img(t_data *sl)
{
	load_img(sl, "texture/dog_front.xpm", &(sl->tex_dog[0][0]));
	load_img(sl, "texture/dog_front_walk1.xpm", &(sl->tex_dog[0][1]));
	load_img(sl, "texture/dog_front.xpm", &(sl->tex_dog[0][2]));
	load_img(sl, "texture/dog_front_walk2.xpm", &(sl->tex_dog[0][3]));
	load_img(sl, "texture/dog_back.xpm", &(sl->tex_dog[1][0]));
	load_img(sl, "texture/dog_back_walk1.xpm", &(sl->tex_dog[1][1]));
	load_img(sl, "texture/dog_back.xpm", &(sl->tex_dog[1][2]));
	load_img(sl, "texture/dog_back_walk2.xpm", &(sl->tex_dog[1][3]));
	load_img(sl, "texture/dog_right.xpm", &(sl->tex_dog[2][0]));
	load_img(sl, "texture/dog_right_walk1.xpm", &(sl->tex_dog[2][1]));
	load_img(sl, "texture/dog_right.xpm", &(sl->tex_dog[2][2]));
	load_img(sl, "texture/dog_right_walk2.xpm", &(sl->tex_dog[2][3]));
	load_img(sl, "texture/dog_left.xpm", &(sl->tex_dog[3][0]));
	load_img(sl, "texture/dog_left_walk1.xpm", &(sl->tex_dog[3][1]));
	load_img(sl, "texture/dog_left.xpm", &(sl->tex_dog[3][2]));
	load_img(sl, "texture/dog_left_walk2.xpm", &(sl->tex_dog[3][3]));
	load_img(sl, "texture/dog_lay.xpm", &(sl->tex_dog[4][0]));
}

static void	load_wolf_img(t_data *sl)
{
	load_img(sl, "texture/test/pl_front.xpm", &(sl->tex_wolf[0][0]));
	load_img(sl, "texture/test/pl_front_walk1.xpm", &(sl->tex_wolf[0][1]));
	load_img(sl, "texture/test/pl_front.xpm", &(sl->tex_wolf[0][2]));
	load_img(sl, "texture/test/pl_front_walk2.xpm", &(sl->tex_wolf[0][3]));
	load_img(sl, "texture/test/pl_back.xpm", &(sl->tex_wolf[1][0]));
	load_img(sl, "texture/test/pl_back_walk1.xpm", &(sl->tex_wolf[1][1]));
	load_img(sl, "texture/test/pl_back.xpm", &(sl->tex_wolf[1][2]));
	load_img(sl, "texture/test/pl_back_walk2.xpm", &(sl->tex_wolf[1][3]));
	load_img(sl, "texture/test/pl_right.xpm", &(sl->tex_wolf[2][0]));
	load_img(sl, "texture/test/pl_right_walk1.xpm", &(sl->tex_wolf[2][1]));
	load_img(sl, "texture/test/pl_right.xpm", &(sl->tex_wolf[2][2]));
	load_img(sl, "texture/test/pl_right_walk2.xpm", &(sl->tex_wolf[2][3]));
	load_img(sl, "texture/test/pl_left.xpm", &(sl->tex_wolf[3][0]));
	load_img(sl, "texture/test/pl_left_walk1.xpm", &(sl->tex_wolf[3][1]));
	load_img(sl, "texture/test/pl_left.xpm", &(sl->tex_wolf[3][2]));
	load_img(sl, "texture/test/pl_left_walk2.xpm", &(sl->tex_wolf[3][3]));
	load_img(sl, "texture/test/pl_kill1.xpm", &(sl->tex_wolf[4][1]));
	load_img(sl, "texture/test/pl_kill2.xpm", &(sl->tex_wolf[4][2]));
}

void	load_all_image(t_data *sl)
{
	load_map_img(sl);
	load_pl_img(sl);
	load_dog_img(sl);
	load_wolf_img(sl);
}
