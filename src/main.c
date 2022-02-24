/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <hubretec@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:50:41 by hubretec          #+#    #+#             */
/*   Updated: 2022/02/24 12:37:24 by hubretec         ###   ########.fr       */
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
	mlx_loop(game.mlx);
	free_tab(game.map.map);
	free_game(&game);
	return (0);
}
