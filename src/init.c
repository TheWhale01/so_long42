/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubretec <hubretec@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:09:42 by hubretec          #+#    #+#             */
/*   Updated: 2022/02/22 15:15:32 by hubretec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_assets(t_assets *assets)
{
	assets->exit = "E";
	assets->wall = 'W';
	assets->empty = '0';
	assets->start = 'P';
	assets->collectible = 'C';
}
