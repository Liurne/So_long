/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:34:36 by jcoquard          #+#    #+#             */
/*   Updated: 2024/04/26 10:50:43 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_map_size(t_data *sl)
{
	int	tmp;

	tmp = 0;
	while (sl->map.map[tmp] != '\n' && sl->map.map[tmp])
		tmp++;
	if (!sl->map.map[tmp])
		return (0);
	sl->map.w = tmp;
	if (sl->map.w > 100)
		return(0);
	if ((ft_strlen(sl->map.map) + 1) % (tmp + 1))
		return (0);
	sl->map.h = (ft_strlen(sl->map.map) + 1) / (tmp + 1);
	if (sl->map.h > 100)
		return(0);
	return (1);
}

int	parcour_map(t_data *sl)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (++i < sl->map.w)
	{
		j = -1;
		while (++j < sl->map.h)
		{
			c = get_tile(&sl->map, i, j);
			if (c != 'C' && c != 'P' && c != '1' && c != '0'
				&& c != 'E' && !c)
				return (0);
			if (i == sl->map.w - 1 || i == 0 || j == sl->map.h - 1 || j == 0)
				if (c != '1')
					return (0);
		}
	}
	return (1);
}

int	verif_count(t_data *sl)
{
	int	p;
	int	e;
	int	i;

	p = 0;
	e = 0;
	i = -1;
	dog_alloc(sl);
	while (sl->map.map[++i])
	{
		if (sl->map.map[i] == 'P')
			p++;
		if (sl->map.map[i] == 'E')
			e++;
		if (sl->map.map[i] == 'C')
			sl->nb_dogs++;
		if (sl->map.map[i] == 'C' || sl->map.map[i] == '0')
			sl->nb_tile++;
		init_entity(sl, sl->map.map[i], i - ((i / (sl->map.w + 1)) * \
			(sl->map.w + 1)), i / (sl->map.w + 1));
	}
	if (p != 1 || e != 1 || sl->nb_dogs < 1)
		return (0);
	return (1);
}

int	recu_finder(t_data *sl, char *map, int x, int y)
{
	char	*tile;

	tile = &map[(y * (sl->map.w + 1)) + x];
	if (x >= sl->map.w || x < 0 || y >= sl->map.h || y < 0
		|| *tile == '1' || *tile == '.')
		return (0);
	if (*tile == 'E')
	{
		*tile = '.';
		return (0);
	}
	*tile = '.';
	recu_finder(sl, map, x - 1, y);
	recu_finder(sl, map, x + 1, y);
	recu_finder(sl, map, x, y - 1);
	recu_finder(sl, map, x, y + 1);
	return (0);
}

int	verif_map(t_data *sl)
{
	char	*tmp;

	tmp = ft_strdup(sl->map.map);
	if (!tmp)
		return (0);
	if (!verif_map_size(sl) || !verif_count(sl) || !parcour_map(sl))
		return (free(tmp), 0);
	sl->map.map_hitbox = ft_calloc((sl->map.w * 2) * (sl->map.h * 2), sizeof(char));
	recu_finder(sl, tmp, sl->map.start.x, sl->map.start.y);
	if (is_still(tmp))
		return (free(tmp), 0);
	complete_border(&sl->map, 0, 0);
	pars_lake(&sl->map, tmp);
	return (free(tmp), 1);
}
