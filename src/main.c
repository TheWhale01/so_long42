/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <hubretec@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:50:41 by hubretec          #+#    #+#             */
/*   Updated: 2022/02/23 14:46:26 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "so_long.h"

int	main(int ac, char **av)
{
	int		i;
	t_map	map;

	check(ac, av, &map);
	i = -1;
	while (map.map[++i])
	{
		ft_printf("%s\n", map.map[i]);
		free(map.map[i]);
	}
	free(map.map);
	return (0);
}
