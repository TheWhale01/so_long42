/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <hubretec@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:19:59 by hubretec          #+#    #+#             */
/*   Updated: 2022/03/07 11:42:21 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "so_long.h"

void	create_img_ptr_player(t_game *game)
{
	game->player.front.img = mlx_xpm_file_to_image(game->mlx,
			game->player.front.path, &(game->map.assets.size),
			&(game->map.assets.size));
	game->player.back.img = mlx_xpm_file_to_image(game->mlx,
			game->player.back.path, &(game->map.assets.size),
			&(game->map.assets.size));
	game->player.left.img = mlx_xpm_file_to_image(game->mlx,
			game->player.left.path, &(game->map.assets.size),
			&(game->map.assets.size));
	game->player.right.img = mlx_xpm_file_to_image(game->mlx,
			game->player.right.path, &(game->map.assets.size),
			&(game->map.assets.size));
	if (!game->player.back.img || !game->player.front.img
		|| !game->player.left.img || !game->player.right.img)
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
				display_img(game->player.front.img, game);
		}
	}
}
