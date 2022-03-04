/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <hubretec@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:19:59 by hubretec          #+#    #+#             */
/*   Updated: 2022/03/04 15:23:41 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	close(fd);
}

void	create_img_ptr_player(t_game *game)
{
	game->player.img_front = mlx_xpm_file_to_image(game->mlx,
			game->player.path_front, &(game->map.assets.size),
			&(game->map.assets.size));
	game->player.img_back = mlx_xpm_file_to_image(game->mlx,
			game->player.path_back, &(game->map.assets.size),
			&(game->map.assets.size));
	game->player.img_left = mlx_xpm_file_to_image(game->mlx,
			game->player.path_left, &(game->map.assets.size),
			&(game->map.assets.size));
	game->player.img_right = mlx_xpm_file_to_image(game->mlx,
			game->player.path_right, &(game->map.assets.size),
			&(game->map.assets.size));
	if (!game->player.img_back || !game->player.img_front
		|| !game->player.img_left || !game->player.img_right)
		exit_msg(EXIT_FAILURE, "Could not load player textures.", game);
}

void	create_img_ptr_game(t_game *game)
{
	game->map.assets.collectible.img = mlx_xpm_file_to_image(game->mlx,
			game->map.assets.collectible.path, &(game->map.assets.size),
			&(game->map.assets.size));
	game->map.assets.empty.img = mlx_xpm_file_to_image(game->mlx,
			game->map.assets.empty.path, &(game->map.assets.size),
			&(game->map.assets.size));
	game->map.assets.exit.img = mlx_xpm_file_to_image(game->mlx,
			game->map.assets.exit.path, &(game->map.assets.size),
			&(game->map.assets.size));
	game->map.assets.wall.img = mlx_xpm_file_to_image(game->mlx,
			game->map.assets.wall.path, &(game->map.assets.size),
			&(game->map.assets.size));
	create_img_ptr_player(game);
	if (!game->map.assets.collectible.img || !game->map.assets.empty.img
		|| !game->map.assets.exit.img || !game->map.assets.wall.img)
		exit_msg(EXIT_FAILURE, "Could not load map textures.", game);
}

void	display_img(void *img, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, img,
		game->map.assets.pos.x, game->map.assets.pos.y);
	game->map.assets.pos.x += game->map.assets.size;
	if (game->map.assets.pos.x == game->map.assets.size * game->map.width)
	{
		game->map.assets.pos.x = 0;
		game->map.assets.pos.y += game->map.assets.size;
	}
}

void	display_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	create_img_ptr_game(game);
	while (game->map.map[++i])
	{
		j = -1;
		while (game->map.map[i][++j])
		{
			if (game->map.map[i][j] == game->map.assets.collectible.value)
				display_img(game->map.assets.collectible.img, game);
			else if (game->map.map[i][j] == game->map.assets.empty.value)
				display_img(game->map.assets.empty.img, game);
			else if (game->map.map[i][j] == game->map.assets.exit.value)
				display_img(game->map.assets.exit.img, game);
			else if (game->map.map[i][j] == game->map.assets.wall.value)
				display_img(game->map.assets.wall.img, game);
			else if (game->map.map[i][j] == game->player.value)
				display_img(game->player.img_front, game);
		}
	}
}
