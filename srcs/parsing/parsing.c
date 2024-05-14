/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:32:41 by liurne            #+#    #+#             */
/*   Updated: 2024/04/28 18:40:55 by liurne           ###   ########.fr       */
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
		return (error(sl, ERR_SQUARE));
	sl->map.w = tmp;
	if ((ft_strlen(sl->map.map) + 1) % (tmp + 1))
		return (error(sl, ERR_SQUARE));
	sl->map.h = (ft_strlen(sl->map.map) + 1) / (tmp + 1);
	return (0);
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
				return (error(sl, ERR_TILE));
			if (c == 'C' || c == 'P' || c == 'E')
				pars_entity(sl, c, i, j);
			if (i == sl->map.w - 1 || i == 0 || j == sl->map.h - 1 || j == 0)
				if (c != '1')
					return (error(sl, ERR_BORDER));
		}
	}
	return (0);
}

int	verif_count(t_data *sl)
{
	int	p;
	int	e;
	int	c;
	int	i;

	p = 0;
	e = 0;
	c = 0;
	i = -1;
	while (sl->map.map[++i])
	{
		if (sl->map.map[i] == 'P')
			p++;
		if (sl->map.map[i] == 'E')
			e++;
		if (sl->map.map[i] == 'C')
			c++;
		if (sl->map.map[i] == 'C' || sl->map.map[i] == '0')
			sl->nb_tile++;
	}
	if (p != 1 || e != 1 || c < 1)
		return (error(sl, ERR_ELEMENT));
	entities_alloc(sl, c);
	return (0);
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

	if (verif_map_size(sl) || verif_count(sl) || parcour_map(sl))
		return (0);
	tmp = ft_strdup(sl->map.map);
	if (!tmp)
		return (0);
	recu_finder(sl, tmp, sl->map.start.x, sl->map.start.y);
	if (is_still(tmp))
		return (free(tmp), 0);
	complete_border(&sl->map, tmp, 0, 0);
	printf("map_tmp:\n%s\n", tmp);
	printf("map:\n%s\n", sl->map.map);
	pars_lake(&sl->map, tmp);
	printf("map_tmp:\n%s\n", tmp);
	printf("map_tmp:\n%s\n", sl->map.map);
	return (free(tmp), 1);
}
