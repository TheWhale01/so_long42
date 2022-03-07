/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <hubretec@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:09:42 by hubretec          #+#    #+#             */
/*   Updated: 2022/03/07 14:03:18 by hubretec         ###   ########.fr       */
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

void	init_img(t_game *game, t_img *img, char *path, char value)
{
	(void)game;
	img->bpp = 4;
	img->img = mlx_xpm_file_to_image(game->mlx, path,
			&(game->map.assets.size), &(game->map.assets.size));
	img->addr = NULL;
	img->path = path;
	img->value = value;
}

void	init_assets(t_game *game)
{
	game->map.assets.size = 64;
	init_img(game, &(game->map.assets.exit), "assets/wall.xpm", 'E');
	init_img(game, &(game->map.assets.wall), "assets/wall_2.xpm", '1');
	init_img(game, &(game->map.assets.empty), "assets/clay.xpm", '0');
	init_img(game, &(game->map.assets.collectible), "assets/amethyst.xpm", 'C');
	init_img(game, &(game->player.back), "assets/player_B.xpm", 'P');
	init_img(game, &(game->player.front), "assets/player_F.xpm", 'P');
	init_img(game, &(game->player.left), "assets/player_L.xpm", 'P');
	init_img(game, &(game->player.right), "assets/player_R.xpm", 'P');
	game->player.value = 'P';
	set_starting_pos(game);
}

void	init(char *filename, t_game *game)
{
	int	fd;

	game->map.width = 0;
	fd = open(filename, O_RDWR | __O_NOFOLLOW);
	if (fd == -1)
		exit_msg(EXIT_FAILURE, "Could not open the file.", game);
	store_map(fd, &(game->map));
	init_assets(game);
	game->map.height = tablen(game->map.map);
	check_map(game);
	init_game(game);
}
