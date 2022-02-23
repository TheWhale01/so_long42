/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <hubretec@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:52:27 by hubretec          #+#    #+#             */
/*   Updated: 2022/02/23 14:45:51 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	exit_msg(char *str)
{
	if (str)
		ft_putendl_fd(str, STDERR);
	exit(EXIT_FAILURE);
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
