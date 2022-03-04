/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <hubretec@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:03:26 by hubretec          #+#    #+#             */
/*   Updated: 2022/03/04 15:12:13 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_img
{
	char	value;
	char	*path;
	void	*img;
}	t_img;

typedef struct s_player
{
	char	value;
	void	*img_back;
	void	*img_left;
	void	*img_right;
	void	*img_front;
	char	*path_back;
	char	*path_left;
	char	*path_right;
	char	*path_front;
	t_pos	pos;
}	t_player;

typedef struct s_assets
{
	int		size;
	t_pos	pos;
	t_img	exit;
	t_img	wall;
	t_img	empty;
	t_img	collectible;
}	t_assets;

typedef struct s_map
{
	int			width;
	int			height;
	char		**map;
	t_assets	assets;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_map		map;
	t_player	player;
}	t_game;

int		tablen(char **tab);
int		quit_game(t_game *game);
int		is_in(char **tab, char c);
int		do_event(int keycode, t_game *game);

void	check_map(t_game *game);
void	free_game(t_game *game);
void	display_map(t_game *game);
void	store_map(int fd, t_map *map);
void	init(char *filename, t_game *game);
void	check(int ac, char **av, t_game *game);
void	exit_msg(int exit_code, char *str, t_game *game);

void	*free_tab(char **tab);
void	*load_win(t_game *game);

char	**add_line(char **tab, char *line);

#endif
