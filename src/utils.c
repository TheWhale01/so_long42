/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <hubretec@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:52:27 by hubretec          #+#    #+#             */
/*   Updated: 2022/02/22 19:10:55 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

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

char	**add_line(char **tab, char *line)
{
	int		i;
	char	**new;

	new = malloc(sizeof(char *) * (tablen(tab) + 2));
	if (!new)
		return (NULL);
	i = 0;
	line[ft_strlen(line) - 1] = '\0';
	while (tab && tab[i])
	{
		new[i] = ft_strdup(tab[i]);
		free(tab[i++]);
	}
	new[i++] = ft_strdup(line);
	new[i] = NULL;
	free(tab);
	return (new);
}
