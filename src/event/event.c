/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:29:51 by liurne            #+#    #+#             */
/*   Updated: 2024/02/20 18:36:17 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_night(t_data *sl)
{
	int	i;

	if (sl->trans < 80)
		sl->trans = (int)(((((float)sl->entities[0].nb_mv
					/ (float)(sl->nb_case)) * 4) / 5) * 100);
	if (sl->trans >= 80)
	{
		sl->entities[0].delay = 250;
		sl->entities[1].alive = 1;
		sl->entities[1].inmove = 1;
		ft_putstr_fd("The big bad wolf is...\nCOMMING!!!!!\n", 1);
	}
}

static void	bad_end(t_data *sl)
{
	if (sl->time > 20)
	{
		sl->entities[0].animation = 2;
		sl->entities[1].animation = 2;
		sl->time = 0;
	}
	sl->time++;
}

int	event_manager(t_data *sl)
{
	int		i;

	if (sl->entities[0].alive)
	{
		player_manager(sl);
		if (sl->entities[0].delay > 110 && sl->entities[0].dir >= 4)
			sl->entities[0].dir = 0;
		animation(sl);
		update_night(sl);
		i = -1;
		while (++i < sl->nb_dogs && sl->entities[2].alive)
			dog_manager(sl, &(sl->entities[2 + i]));	
		if (sl->entities[1].alive)
			wolf_manager(sl, &(sl->entities[1]));
	}
	else
		bad_end(sl);
	render_display(sl);
	return (0);
}
