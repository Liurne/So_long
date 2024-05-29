/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:35:48 by liurne            #+#    #+#             */
/*   Updated: 2024/05/29 17:12:17 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_night(t_data *sl)
{
	if (sl->night < 70)
		sl->night = (int)(((((float)sl->pl.nb_mv
							/ (float)(sl->nb_tile)) * 4) * 0.2) * 100);
	if (sl->night >= 70 && !sl->bad.active)
	{
		ft_putstr_fd("The big bad wolf is...\nCOMMING!!!!!\n", 1);
		sl->is_night = 1;
		sl->bad.active = 1;
		sl->bad.inmove = 1;
	}
}

void	bad_end(t_data *sl)
{
	if (sl->time > 20)
	{
		sl->pl.frame = 3;
		sl->bad.frame = 2;
		sl->time = 0;
	}
	sl->time++;
}

int	process(t_data *sl)
{
	int		i;
	if (sl->game_status == FIRST_ANIMATION)
		animation_arriving(sl, &sl->win.renderer);
	if (sl->game_status == RUN)
	{
		if (sl->pl.active)
		{
			animation(sl);
			update_night(sl);
			i = -1;
			while (++i < sl->nb_cats)
				cat_manager(sl, &(sl->cats[i]));
			if ((sl->pl.delay > 25 && !sl->bad.active) || sl->bad.active)
				player_manager(sl);
			if (sl->bad.active)
				bad_manager(sl, &(sl->bad));
		}
		else
			bad_end(sl);
		render_display(sl);
	}
	return (0);
}
