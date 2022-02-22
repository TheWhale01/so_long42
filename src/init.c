/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <hubretec@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:09:42 by hubretec          #+#    #+#             */
/*   Updated: 2022/02/22 19:04:58 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "so_long.h"

void	store_map(int fd, t_map *map)
{
	char	*line;

	map->map = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->map = add_line(map->map, line);
		if (!map->width)
			map->width = ft_strlen(line);
		free(line);
	}
}

void	init(char *filename, t_map *map)
{
	int	fd;

	map->width = 0;
	fd = open(filename, O_RDONLY, 0644);
	if (fd == -1)
		exit(EXIT_FAILURE);
	init_assets(&(map->assets));
	store_map(fd, map);
	map->height = tablen(map->map);
	if (!check_map(*map))
	{
		free_tab(map->map);
		exit(EXIT_FAILURE);
	}
}

void	init_assets(t_assets *assets)
{
	assets->exit = 'E';
	assets->wall = '1';
	assets->empty = '0';
	assets->start = 'P';
	assets->collectible = 'C';
}
