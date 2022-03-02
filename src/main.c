/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <hubretec@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:50:41 by hubretec          #+#    #+#             */
/*   Updated: 2022/03/02 15:14:51 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "so_long.h"

char	**add_line(char **tab, char *line)
{
	int		i;
	int		len;
	char	**new;

	new = malloc(sizeof(char *) * (tablen(tab) + 2));
	if (!new)
		return (NULL);
	i = 0;
	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	while (tab && tab[i])
	{
		new[i] = ft_strdup(tab[i]);
		free(tab[i++]);
	}
	new[i++] = line;
	new[i] = NULL;
	free(tab);
	return (new);
}

int	main(int ac, char **av)
{
	t_game	game;

	check(ac, av, &(game));
	display_map(&game);
	mlx_hook(game.mlx_win, 2, (1L << 0), do_event, &game);
	mlx_hook(game.mlx_win, 17, (1L << 0), quit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
