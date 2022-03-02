/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <hubretec@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:09:42 by hubretec          #+#    #+#             */
/*   Updated: 2022/03/02 15:14:01 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "mlx.h"
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
	}
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_msg(EXIT_FAILURE, "Could not load mlx.", game);
	game->map.assets.pos.x = 0;
	game->map.assets.pos.y = 0;
	game->mlx_win = mlx_new_window(game->mlx,
			game->map.assets.size * game->map.width,
			game->map.assets.size * game->map.height, "so_long");
}

void	init_player(t_game *game)
{
	game->player.img = NULL;
	game->player.value = 'P';
	game->player.path_back = "assets/player_B.xpm";
	game->player.path_front = "assets/player_F.xpm";
	game->player.path_left = "assets/player_L.xpm";
	game->player.path_right = "assets/player_R.xpm";
}

void	init_assets(t_assets *assets)
{
	assets->size = 64;
	assets->exit.img = NULL;
	assets->exit.value = 'E';
	assets->exit.path = "assets/wall.xpm";
	assets->wall.img = NULL;
	assets->wall.value = '1';
	assets->wall.path = "assets/wall_2.xpm";
	assets->empty.img = NULL;
	assets->empty.value = '0';
	assets->empty.path = "assets/clay.xpm";
	assets->collectible.img = NULL;
	assets->collectible.value = 'C';
	assets->collectible.path = "assets/amethyst.xpm";
}

void	init(char *filename, t_game *game)
{
	int	fd;

	game->map.width = 0;
	fd = open(filename, O_RDWR | __O_NOFOLLOW);
	if (fd == -1)
		exit_msg(EXIT_FAILURE, "Could not open the file.", game);
	init_assets(&(game->map.assets));
	init_player(game);
	store_map(fd, &(game->map));
	game->map.height = tablen(game->map.map);
	if (!check_map(*game))
		exit_msg(EXIT_FAILURE, "Invalid map.", game);
	init_game(game);
}
