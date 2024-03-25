/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:29:51 by liurne            #+#    #+#             */
/*   Updated: 2024/03/25 02:14:04 by liurne           ###   ########.fr       */
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
		sl->pl.animation = 2;
		sl->bad.animation = 2;
		sl->time = 0;
	}
	//sl->col_sky = transparence(C_NIGHT, C_DEAD, 50);
	sl->time++;
}

int	process(t_data *sl)
{
	int		i;

	if (sl->pl.active)
	{
		animation(sl);
		update_night(sl);
		i = -1;
		while (++i < sl->nb_dogs)
			dog_manager(sl, &(sl->dogs[i]));
		if ((sl->pl.delay > 30 && !sl->bad.active) || sl->bad.active)
			player_manager(sl);
		if (sl->bad.active)
			bad_manager(sl, &(sl->bad));
	}
	else
		bad_end(sl);
	render_display(sl);
	return (0);
}
