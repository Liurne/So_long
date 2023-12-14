/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:37:46 by jcoquard          #+#    #+#             */
/*   Updated: 2023/11/07 00:30:37 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../minilibx/mlx.h"
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# define ERR_MLX "Couldn't initiate mlx"
# define ERR_ARG "Invalid number of argument"
# define ERR_LIB "Couldn't create a window"
# define ERR_MAP "Map invalid or non-existant"
# define ERR_TEX "Texture invalid or non-existant"
# define ERR_IMG "Couldn't creater an image"
# define WIN_W 1280
# define WIN_H 768
# define NB_ENTITIES 51
# define NB_WOLF 1
# define NB_DOG 50
# define C_NIGHT 0xFF001835

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_w;
	int		img_h;
}	t_img;

typedef struct s_wins
{
	void	*mlx;
	void	*win;
	t_img	renderer;
	int		w;
	int		h;
}	t_wins;

typedef struct s_vec
{
	int	x;
	int	y;
}	t_vec;

typedef struct s_map
{
	char	*map;
	int		w;
	int		h;
	t_vec	pos;
	t_vec	end;
	t_img	img;
	t_img	tex[57];
}	t_map;

typedef enum e_mob
{
	PLAYER,
	DOG,
	WOLF
}	t_mob;

typedef struct s_entity
{
	int		id;
	t_mob	type;
	t_vec	pos;
	t_vec	tpos;
	int		w;
	int		h;
	int		dir;
	size_t	nb_mv;
	size_t	d;
	int		delay;
	int		inmove;
	int		alive;
	int		animation;
	t_img	tex[5][4];
}	t_entity;

typedef struct s_keyboard
{
	int	up;
	int	down;
	int	left;
	int	right;
}	t_keyboard;

typedef struct s_data
{
	t_wins		win;
	t_keyboard	keys;
	t_map		map;
	t_entity	entities[NB_ENTITIES + 1];
	t_entity	pl;
	t_entity	dog[NB_DOG];
	t_entity	wolf;
	int			nb_dogs;
	size_t		nb_case;
	size_t		nb_col;
	int			trans;
	int			need_pet;
	int			show_hitbox;
	int			time;
}	t_data;

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

/* -----init----- */
int		init_window(t_data *sl, int win_w, int win_h);
int		close_window(t_data *sl);
int		new_img(t_data *sl, t_img *img, int w, int h);
int		load_img(t_data *sl, char *path, t_img *img);
int		destroy_img(t_data *sl, t_img *img);
void	load_all_image(t_data *sl);
void	destroy_all_image(t_data *sl);
int		error(t_data *sl, char *msg);

/* -----parsing----- */
int		load_map(t_data *sl, char *path);
int		verif_map(t_data *sl);
void	complete_border(t_data *sl, int x, int y);
int		is_still(char *map);

/* -----world----- */
char	get_tile(t_data *sl, int x, int y);
int		set_tile(t_data *sl, int x, int y, char c);
void	put_pixelmap(t_map *m, int x, int y, int img);
int		map_to_img(t_data *sl);
void	reload_tile_img(t_data *sl, int x, int y);
void	which_border(t_data *sl, t_map *map, int x, int y);

/* -----entity----- */
void	init_pos(t_data *sl);
int		map_collision(t_data *sl, t_entity *e, int x, int y);
int		entity_collision(t_entity *e1, t_entity *e2);
void	player_manager(t_data *sl);
void	dog_manager(t_data *sl, t_entity *e);
void	wolf_manager(t_data *sl, t_entity *e);

/* -----display----- */
void	put_pixel(t_img *img, int x, int y, int color);
int		get_pixel(t_img *img, int x, int y);
int		transparence(int c1, int c2, int t);
void	display_entity(t_data *sl, t_entity *e);
void	display_dog(t_data *sl, t_entity *e);
void	animation(t_data *sl);
void		render_display(t_data *sl);

/* -----event----- */
int		key_press(int keycode, t_data *sl);
int		key_release(int keycode, t_data *sl);
int		event_manager(t_data *sl);

#endif