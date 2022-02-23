/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <hubretec@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:03:26 by hubretec          #+#    #+#             */
/*   Updated: 2022/02/23 14:46:05 by hubretec         ###   ########.fr       */
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
	int			height;
	char		**map;
	t_assets	assets;
}	t_map;

int		tablen(char **tab);
int		check_map(t_map map);
int		is_in(char **tab, char c);

void	exit_msg(char *str);
void	init_assets(t_assets *assets);
void	store_map(int fd, t_map *map);
void	init(char *filename, t_map *map);
void	check(int ac, char **av, t_map *map);

void	*free_tab(char **tab);

char	**add_line(char **tab, char *line);

#endif