/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <hubretec@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:19:59 by hubretec          #+#    #+#             */
/*   Updated: 2022/03/07 13:48:15 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "so_long.h"

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
	while (game->map.map[++i])
	{
		j = -1;
		while (game->map.map[i][++j])
		{
			if (game->map.map[i][j] == game->map.assets.collectible.value)
				display_img(&(game->map.assets.collectible.img), game);
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
