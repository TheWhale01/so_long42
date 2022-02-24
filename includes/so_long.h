/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <hubretec@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:03:26 by hubretec          #+#    #+#             */
/*   Updated: 2022/02/24 12:26:40 by hubretec         ###   ########.fr       */
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

typedef struct s_img
{
	int		size;
}	t_img;


typedef struct s_game
{
	t_map	map;
	t_img	img;
	void	*mlx;
	void	*mlx_win;
}	t_game;

int		tablen(char **tab);
int		check_map(t_map map);
int		is_in(char **tab, char c);

void	init_assets(t_assets *assets);
void	store_map(int fd, t_map *map);
void	exit_msg(char *str, t_game *game);
void	init(char *filename, t_game *game);
void	check(int ac, char **av, t_game *game);

void	*free_tab(char **tab);
void	*load_win(t_game *game);
void	*free_game(t_game *game);

char	**add_line(char **tab, char *line);

#endif