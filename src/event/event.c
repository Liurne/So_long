/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:29:51 by liurne            #+#    #+#             */
/*   Updated: 2024/02/20 17:30:51 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_night(t_data *sl)
{
	int	i;

	if (sl->trans < 80)
		sl->trans = (int)(((((float)sl->pl.nb_mv
					/ (float)(sl->nb_case)) * 4) / 5) * 100);
	if (sl->trans >= 80 && sl->dog[0].alive)
	{
		sl->need_pet = 250;
		sl->wolf.alive = 1;
		sl->wolf.inmove = 1;
		i = -1;
		while (++i < sl->nb_dogs)
			sl->dog[i].alive = 0;
		ft_putstr_fd("The big bad wolf is...\nCOMMING!!!!!\n", 1);
	}
}

static void	bad_end(t_data *sl)
{
	if (sl->time > 20)
	{
		sl->pl.animation = 2;
		sl->wolf.animation = 2;
		sl->time = 0;
	}
	sl->time++;
}

int	event_manager(t_data *sl)
{
	int		i;

	if (sl->pl.alive)
	{
		player_manager(sl);
		if (sl->need_pet > 110 && sl->pl.dir >= 4)
			sl->pl.dir = 0;
		animation(sl);
		update_night(sl);
		i = -1;
		while (++i < sl->nb_dogs && sl->dog[i].alive)
			dog_manager(sl, &(sl->dog[i]));	
		if (sl->wolf.alive)
			wolf_manager(sl, &(sl->wolf));
	}
	else
		bad_end(sl);
	render_display(sl);
	return (0);
}
