/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:45:37 by jcoquard          #+#    #+#             */
/*   Updated: 2023/09/03 18:06:47 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	key_press_op(int keycode, t_data *sl)
{
	if (keycode == 103)
	{
		if (sl->show_hitbox)
			sl->show_hitbox = 0;
		else
			sl->show_hitbox = 1;
	}
	if (keycode == 110)
		sl->pl.nb_mv = sl->nb_case;
	if (keycode == 65451 && sl->nb_dogs < NB_DOG && sl->pl.nb_mv < sl->nb_case)
	{
		sl->dog[sl->nb_dogs].alive = 1;
		sl->nb_dogs++;
	}
	if (keycode == 65453 && sl->nb_dogs > 0 && sl->pl.nb_mv < sl->nb_case)
	{
		sl->dog[sl->nb_dogs].alive = 0;
		sl->nb_dogs--;
	}
}

int	key_press(int keycode, t_data *sl)
{
	if (keycode == 65307)
		close_window(sl);
	if ((keycode == 119 || keycode == 65362) && !sl->keys.down)
		sl->keys.up = 1;
	if ((keycode == 115 || keycode == 65364) && !sl->keys.up)
		sl->keys.down = 1;
	if ((keycode == 97 || keycode == 65361) && !sl->keys.right)
		sl->keys.left = 1;
	if ((keycode == 100 || keycode == 65363) && !sl->keys.left)
		sl->keys.right = 1;
	key_press_op(keycode, sl);
	return (keycode);
}

int	key_release(int keycode, t_data *sl)
{
	if (keycode == 119 || keycode == 65362)
		sl->keys.up = 0;
	if (keycode == 115 || keycode == 65364)
		sl->keys.down = 0;
	if (keycode == 97 || keycode == 65361)
		sl->keys.left = 0;
	if (keycode == 100 || keycode == 65363)
		sl->keys.right = 0;
	return (keycode);
}
