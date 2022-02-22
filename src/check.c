/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <hubretec@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:56:18 by hubretec          #+#    #+#             */
/*   Updated: 2022/02/22 15:15:36 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	check(int ac, char **av)
{
	char	*start;

	if (ac != 2)
		exit(EXIT_FAILURE);
	start = ft_strstr(av[1], ".ber");
	if (!start || ft_strcmp(".ber", start))
		exit(EXIT_FAILURE);
}
