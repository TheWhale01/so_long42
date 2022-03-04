/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <hubretec@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:09:42 by hubretec          #+#    #+#             */
/*   Updated: 2022/03/04 15:20:39 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "so_long.h"

void	set_starting_pos(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map.map[++i])
	{
		j = -1;
		while (game->map.map[i][++j])
		{
			if (game->map.map[i][j] == game->player.value)
			{
				game->player.pos.x = j * game->map.assets.size;
				game->player.pos.y = i * game->map.assets.size;
				break ;
			}
		}			
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
	game->player.img_back = NULL;
	game->player.img_front = NULL;
	game->player.img_left = NULL;
	game->player.img_right = NULL;
	game->player.value = 'P';
	game->player.path_back = "assets/player_B.xpm";
	game->player.path_front = "assets/player_F.xpm";
	game->player.path_left = "assets/player_L.xpm";
	game->player.path_right = "assets/player_R.xpm";
	set_starting_pos(game);
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
	store_map(fd, &(game->map));
	init_assets(&(game->map.assets));
	init_player(game);
	game->map.height = tablen(game->map.map);
	check_map(game);
	init_game(game);
}
