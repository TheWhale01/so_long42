/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <hubretec@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:52:27 by hubretec          #+#    #+#             */
/*   Updated: 2022/03/02 15:28:01 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "so_long.h"

void	exit_msg(int exit_code, char *str, t_game *game)
{
	if (str)
		ft_putendl_fd(str, STDERR);
	free_game(game);
	exit(exit_code);
}

void	*free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab && tab[++i])
		free(tab[i]);
	free(tab);
	return (NULL);
}

int	is_in(char **tab, char c)
{
	int	i;

	i = -1;
	while (tab && tab[++i])
		if (ft_strchr(tab[i], c))
			return (1);
	return (0);
}

int	tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}
