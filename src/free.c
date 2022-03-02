/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <hubretec@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:48:28 by hubretec          #+#    #+#             */
/*   Updated: 2022/03/02 15:50:20 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "so_long.h"

void	*free_img(t_game *game)
{
	mlx_destroy_image(game->mlx, game->map.assets.collectible.img);
	mlx_destroy_image(game->mlx, game->map.assets.empty.img);
	mlx_destroy_image(game->mlx, game->map.assets.exit.img);
	mlx_destroy_image(game->mlx, game->map.assets.wall.img);
	mlx_destroy_image(game->mlx, game->player.img);
	return (NULL);
}

void	*free_game(t_game *game)
{
	free_tab(game->map.map);
	free_img(game);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	return (NULL);
}
