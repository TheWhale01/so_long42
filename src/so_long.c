/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <hubretec@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:49:02 by hubretec          #+#    #+#             */
/*   Updated: 2022/02/24 16:04:49 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "so_long.h"

int	quit_game(t_game *game)
{
	exit_msg(EXIT_SUCCESS, NULL, game);
	return (1);
}

int	do_event(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit_msg(EXIT_SUCCESS, NULL, game);
	return (1);
}

void	display_img(char *filename, t_game *game)
{
	void	*img;

	img = mlx_xpm_file_to_image(game, filename,
			&(game->img.width), &(game->img.height));
	(void)img;
}

void	display_map(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (game->map.map[++i])
	{
		j = -1;
		while (game->map.map[i][++j])
		{
			if (game->map.map[i][j] == game->map.assets.wall)
				 display_img("./assets/wall.xpm", game);
			else if (game->map.map[i][j] == game->map.assets.empty)
				display_img("./assets/clay.xpm", game);
			else if (game->map.map[i][j] == game->map.assets.collectible)
				display_img("./assets/amethyst.xpm", game);
		}
	}
}
