/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <hubretec@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:56:18 by hubretec          #+#    #+#             */
/*   Updated: 2022/02/22 19:02:36 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "so_long.h"

int	check_assets(t_map	map)
{
	if (!is_in(map.map, map.assets.collectible))
		return (0);
	if (!is_in(map.map, map.assets.empty))
		return (0);
	if (!is_in(map.map, map.assets.exit))
		return (0);
	if (!is_in(map.map, map.assets.start))
		return (0);
	if (!is_in(map.map, map.assets.wall))
		return (0);
	return (1);
}

int	check_map(t_map map)
{
	int	i;
	int	j;

	i = -1;
	if (!check_assets(map))
		return (0);
	while (map.map[++i])
	{
		j = -1;
		if (ft_strlen(map.map[i]) != (size_t)map.width)
			return (0);
		while (map.map[i][++j])
		{
			if ((!(i % map.height) && map.map[i][j] != map.assets.wall) ||
				(!(j % map.width) && map.map[i][j] != map.assets.wall))
				return (0);
			if (map.map[i][j] != map.assets.collectible && map.map[i][j]
				!= map.assets.empty && map.map[i][j] != map.assets.exit
				&& map.map[i][j] != map.assets.start && map.map[i][j]
				!= map.assets.wall)
				return (0);
		}
	}
	return (1);
}

void	check(int ac, char **av)
{
	char	*start;

	if (ac != 2)
		exit(EXIT_FAILURE);
	start = ft_strstr(av[1], ".ber");
	if (!start || ft_strcmp(".ber", start))
		exit(EXIT_FAILURE);
}
