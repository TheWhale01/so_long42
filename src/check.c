/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <hubretec@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:56:18 by hubretec          #+#    #+#             */
/*   Updated: 2022/03/02 15:42:02 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "so_long.h"

int	check_assets(t_game game)
{
	if (!is_in(game.map.map, game.map.assets.collectible.value))
		return (0);
	if (!is_in(game.map.map, game.map.assets.empty.value))
		return (0);
	if (!is_in(game.map.map, game.map.assets.exit.value))
		return (0);
	if (!is_in(game.map.map, game.map.assets.wall.value))
		return (0);
	return (1);
}

int	check_map(t_game game)
{
	int	i;
	int	j;

	i = -1;
	if (!check_assets(game))
		return (0);
	while (game.map.map[++i])
	{
		j = -1;
		if (ft_strlen(game.map.map[i]) != (size_t)game.map.width)
			return (0);
		while (game.map.map[i][++j])
		{
			if ((!(i % (game.map.height - 1)) || !(j % (game.map.width - 1)))
				&& game.map.map[i][j] != game.map.assets.wall.value)
				return (0);
			if (game.map.map[i][j] != game.map.assets.collectible.value
				&& game.map.map[i][j] != game.map.assets.empty.value
				&& game.map.map[i][j] != game.map.assets.exit.value
				&& game.map.map[i][j] != game.map.assets.wall.value
				&& game.map.map[i][j] != game.player.value)
				return (0);
		}
	}
	return (1);
}

void	check(int ac, char **av, t_game *game)
{
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->map.map = NULL;
	if (ac != 2)
		exit_msg(EXIT_FAILURE, "Wrong number of args.", game);
	if (!ft_strnstr(&av[1][ft_strlen(av[1]) - 4], ".ber", 4))
		exit_msg(EXIT_FAILURE, "Invalid filename : <filename>.ber", game);
	init(av[1], game);
}
