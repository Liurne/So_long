/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:31:36 by liurne            #+#    #+#             */
/*   Updated: 2024/04/28 18:13:14 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_file(int fd, char *str)
{
	char	buff[43];
	int		rbytes;

	rbytes = 1;
	while (rbytes)
	{
		rbytes = read(fd, buff, 42);
		if (rbytes == -1)
		{
			free(str);
			str = NULL;
			return (NULL);
		}
		buff[rbytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	return (str);
}

int	load_file(t_data *sl, char *path)
{
	int	fd;

	if (!ft_strber(path))
		return (0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	sl->map.map = read_file(fd, sl->map.map);
	close(fd);
	if (!sl->map.map)
		return (0);
	return (1);
}

int	load_map(t_data *sl, char *path)
{
	if (!load_file(sl, path))
		return (error(sl, ERR_FILE));
	if (!verif_map(sl))
		return (0);
	sl->col_sky = C_NIGHT;
	return (1);
}
