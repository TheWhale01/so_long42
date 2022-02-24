/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <hubretec@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:50:41 by hubretec          #+#    #+#             */
/*   Updated: 2022/02/24 15:06:49 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	check(ac, av, &(game));
	display_map("./assets", &game);
	mlx_hook(game.mlx_win, 2, (1L << 0), do_event, &game);
	mlx_hook(game.mlx_win, 17, (1L << 0), quit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
