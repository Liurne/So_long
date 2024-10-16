/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:37:46 by jcoquard          #+#    #+#             */
/*   Updated: 2024/06/25 14:26:46 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "define.h"

/* -----utils----- */
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strber(const char *haystack);
void	ft_putmove_fd(int nb_move, int fd);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(int n);
t_vec	ft_vec(int x, int y);
void	ft_setvec(t_vec *vec, int x, int y);
t_rect	ft_rect(int x, int y, int w, int h);
void	ft_setrect(t_rect *rect, t_vec pos, int w, int h);

/* -----core----- */
int		init_window(t_data *sl, int win_w, int win_h);
int		close_window(t_data *sl);
int		new_img(t_data *sl, t_img *img, int w, int h);
int		load_img(t_data *sl, char *path, t_img *img);
void	load_map_img(t_data *sl);
int		destroy_img(t_data *sl, t_img *img);
void	load_all_image(t_data *sl);
void	destroy_all_image(t_data *sl);
int		error(t_data *sl, char *msg);

/* -----parsing----- */
void	complete_border(t_map *map, char *tmp_map, int x, int y);
void	pars_lake(t_map *map, char *tmp_map);
void	entities_alloc(t_data *sl, int nb_entities);
void	pars_entity(t_data *sl, char tile, int x, int y);
int		is_still(char *map);
int		load_map(t_data *sl, char *path);
int		verif_map(t_data *sl);
void	map_start(t_data *sl, t_map *map);

/* -----map----- */
char	get_tile(t_map *map, int x, int y);
int		set_tile(t_map *map, int x, int y, char c);
void	put_pixelmap(t_map *m, int x, int y, int img);
int		map_to_img(t_data *sl);
void	reload_tile_img(t_map *map, int x, int y);
void	refresh_end(t_data *sl);
t_img	*which_border(t_map *map, int x, int y);
int		how_many_border(t_map *map, int x, int y);
int		how_many_fborder(t_map *map, int x, int y);

/* -----entities----- */
void	init_pl(t_entity *pl, int x, int y);
void	init_bad(t_entity *e, int x, int y);
void	init_cat(t_entity *e, int x, int y, int nb);
int		entity_collision(t_entity *e1, t_entity *e2);
int		map_collision(t_data *sl, t_entity *e, int x, int y);
int		move_entity(t_data *sl, t_entity *e);
int		roaming_alg(t_data *sl, t_entity *e);
void	update_cam(t_wins *win, t_entity *pl, t_map *map);
void	player_manager(t_data *sl);
int		player_move(t_data *sl, int x, int y, int dir);
void	cat_manager(t_data *sl, t_entity *cat);
void	bad_manager(t_data *sl, t_entity *e);

/* -----renderer----- */
void	put_pixel(t_img *img, int x, int y, int color);
int		get_pixel(t_img *img, int x, int y);
void	put_img_to_img(t_img *img1, t_img *img2, t_rect *src, t_rect *dst);
int		transparence(int c1, int c2, int t);
void	display_entity(t_data *sl, t_entity **mobs);
void	display_dog(t_data *sl, t_entity *e);
void	animation(t_data *sl);
void	render_display(t_data *sl);
void	animation_arriving(t_data *sl, t_img *renderer);

/* -----run----- */
int		process(t_data *sl);
int		key_press(int keycode, t_data *sl);
int		key_release(int keycode, t_data *sl);
void	reset_move(t_data *sl);

#endif