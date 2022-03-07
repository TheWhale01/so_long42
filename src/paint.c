/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <hubretec@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:16:02 by hubretec          #+#    #+#             */
/*   Updated: 2022/03/07 13:48:24 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "so_long.h"

// void	get_img_addr(t_img *img1, t_img *img2, t_game *game)
// {
// 	img2->addr = mlx_get_data_addr(img2->img,
// 			&(img2->bpp), &(img2->line_len), &img2->endian);
// 	if (!img1 || !img2)
// 		exit_msg(EXIT_FAILURE, "Could not get img address.", game);
// }

// int	get_px_color(t_img *img, int x, int y)
// {
// 	char			*px;
// 	unsigned int	color;

// 	px = img->addr + (y * img->line_len + x * (img->bpp / 8));
// 	color = *(unsigned int *)px;
// 	return (color);
// }

// void	put_pixel(t_img *img, int x, int y, int color)
// {
// 	char	*dest;

// 	dest = img->addr + (y * img->line_len + x * (img->bpp / 8));
// 	*(unsigned int *)dest = color;
// }

// void	put_texture(t_img *img, t_game *game)
// {
// 	int				i;
// 	int				j;
// 	unsigned int	color;


// 	i = -1;
// 	while (++i < game->map.assets.size)
// 	{
// 		j = -1;
// 		while (++j < game->map.assets.size)
// 		{
// 			color = get_px_color(img, j, i);
// 			if (color != (unsigned int)(0xFF << 24))
// 				put_pixel(game->tmp, game->map.assets.pos.x + j,
// 					game->map.assets.pos.y + i, color);
// 		}
// 	}
// 	game->map.assets.pos.x += game->map.assets.size;
// 	if (game->map.assets.pos.x == game->map.assets.size * game->map.width)
// 	{
// 		game->map.assets.pos.x = 0;
// 		game->map.assets.pos.y += game->map.assets.size;
// 	}
// }
