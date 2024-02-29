/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:29:51 by liurne            #+#    #+#             */
/*   Updated: 2024/02/29 19:36:49 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_night(t_data *sl)
{
	if (sl->night < 80)
		sl->night = (int)(((((float)sl->pl.nb_mv
					/ (float)(sl->nb_tile)) * 4) / 5) * 100);
	if (sl->night >= 80)
		ft_putstr_fd("The big bad wolf is...\nCOMMING!!!!!\n", 1);
}

void	bad_end(t_data *sl)
{
	if (sl->time > 20)
	{
		sl->pl.animation = 2;
		sl->bad.animation = 2;
		sl->time = 0;
	}
	sl->time++;
}

int	process(t_data *sl)
{
	int		i;

	if (sl->pl.active)
	{
		player_manager(sl);
		if (sl->pl.delay > 110 && sl->pl.dir >= 4)
			sl->pl.dir = 0;
		animation(sl);
		update_night(sl);
		i = -1;
		while (++i < sl->nb_dogs)
			dog_manager(sl, &(sl->dogs[i]));
		if (sl->bad.active)
			bad_manager(sl, &(sl->bad));
	}
	//else
	//	bad_end(sl);
	render_display(sl);
	return (0);
}
