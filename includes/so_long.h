/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <hubretec@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:03:26 by hubretec          #+#    #+#             */
/*   Updated: 2022/02/22 15:14:43 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_assets
{
	char	exit;
	char	wall;
	char	empty;
	char	start;
	char	collectible;
}	t_assets;

typedef struct s_map
{
	int			width;
	char		**map;
	t_assets	assets;
}	t_map;


void	check(int ac, char **av);
void	init_assets(t_assets *assets);

#endif