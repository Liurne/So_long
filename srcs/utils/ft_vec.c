/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:43:27 by jcoquard          #+#    #+#             */
/*   Updated: 2024/03/26 22:48:49 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vec	ft_vec(int x, int y)
{
	t_vec	res;

	res.x = x;
	res.y = y;
	return (res);
}

void	ft_setvec(t_vec *vec, int x, int y)
{
	vec->x = x;
	vec->y = y;
}

float	ft_getdistance(t_vec first, t_vec second)
{
	return (sqrt(pow(first.x - second.x, 2) + pow(first.y - second.y, 2)));
}
