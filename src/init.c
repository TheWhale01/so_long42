/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <hubretec@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:09:42 by hubretec          #+#    #+#             */
/*   Updated: 2022/02/24 12:04:25 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "so_long.h"

char	**add_line(char **tab, char *line)
{
	int		i;
	int		len;
	char	**new;

	new = malloc(sizeof(char *) * (tablen(tab) + 2));
	if (!new)
		return (NULL);
	i = 0;
	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	while (tab && tab[i])
	{
		new[i] = ft_strdup(tab[i]);
		free(tab[i++]);
	}
	new[i++] = ft_strdup(line);
	new[i] = NULL;
	free(tab);
	return (new);
}

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

void	init(char *filename, t_game *game)
{
	int	fd;

	game->map.width = 0;
	fd = open(filename, O_RDWR | __O_NOFOLLOW);
	if (fd == -1)
		exit_msg("Could not open the file.");
	init_assets(&(game->map.assets));
	store_map(fd, &(game->map));
	game->map.height = tablen(game->map.map);
	if (!check_map(game->map))
	{
		free_tab(game->map.map);
		exit_msg("Invalid map.");
	}
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, 640, 640, "test");
}

void	init_assets(t_assets *assets)
{
	assets->exit = 'E';
	assets->wall = '1';
	assets->empty = '0';
	assets->start = 'P';
	assets->collectible = 'C';
}
