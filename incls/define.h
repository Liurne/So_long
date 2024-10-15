/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:09:46 by jcoquard          #+#    #+#             */
/*   Updated: 2024/10/15 17:52:58 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H
# include "../minilibx/mlx.h"
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# define ERR_MLX "Couldn't initiate mlx"
# define ERR_ARG "Invalid number of argument"
# define ERR_WIN "Couldn't create a window"
# define ERR_LIB "Couldn't create a window"
# define ERR_MAP "Map invalid or non-existant"
# define ERR_FILE "File invalid or non-existant"
# define ERR_TEX "Texture invalid or non-existant"
# define ERR_IMG "Couldn't create an image"
# define ERR_MAL "Malloc failed"
# define ERR_TILE "Invalid element inside the map"
# define ERR_BIG "Map is too big (height or width > 100)"
# define ERR_BORDER "Map isn't correctly bordered"
# define ERR_SQUARE "This map isn't rectangular"
# define ERR_COLLECTIBLE "There is too many collectible"
# define ERR_ELEMENT "There is some necessary element(s) missing"
# define ERR_GOAL "Map imposible to finish"
# define WIN_W 1280
# define WIN_H 768
# define C_NIGHT 0xFF001835
# define C_DEAD 0xFF350C0C//400018

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

typedef struct s_rect
{
	t_vec	pos;
	int		w;
	int		h;
}	t_rect;

typedef enum e_status
{
	RUN,
	WIN,
	LOST,
	ANIMATION,
	STARTING
}	t_status;

typedef enum e_error
{
	GOOD,
	INVALID_TEXTURE,
	INVALID_FILE,
	MAP_TOO_BIG,
	MAP_NOT_CLOSED,
	INVALID_TILE,
	TOO_MANY_COLLECTIBLE
}	t_error;

typedef struct s_map
{
	char	*map;
	char	*map_hitbox;
	int		w;
	int		h;
	t_vec	pos;
	t_vec	start;
	t_vec	end;
	t_img	img;
	t_img	tex[57];
}	t_map;

typedef enum e_mob
{
	PLAYER,
	CAT,
	BAD
}	t_mob;

typedef struct s_entity
{
	int		id;
	t_mob	type;
	t_rect	hitbox;
	t_rect	walkbox;
	int		active;
	t_vec	pos;
	int		dir;
	int		speed;
	int		frame;
	int		delay;
	int		inmove;
	size_t	nb_mv;
	size_t	dist;
	size_t	delay_pet;
}	t_entity;

typedef struct s_keyboard
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	show_hitbox;
}	t_keyboard;

typedef struct s_data
{
	t_wins		win;
	t_keyboard	keys;
	t_map		map;
	t_status	game_status;
	int			nb_tile;
	int			nb_entities;
	int			nb_cats;
	int			nb_cats_active;
	t_entity	pl;
	t_entity	bad;
	t_entity	duck;
	t_entity	*cats;
	t_entity	**entities;
	t_img		tex_pl[5][6];
	t_img		tex_cat[5][4];
	t_img		tex_wolf[5][4];
	t_img		tex_duck[5][4];
	int			is_night;
	int			night;
	int			col_sky;
	int			col_ocean;
	int			time;
}	t_data;

#endif