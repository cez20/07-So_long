/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:47:19 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/07/26 12:37:30 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	game->wall.img = mlx_xpm_file_to_image(game->mlx, "./sprites/wall.xpm", \
		&game->wall.width, &game->wall.height);
	game->floor.img = mlx_xpm_file_to_image(game->mlx, "./sprites/floor.xpm", \
		&game->floor.width, &game->floor.height);
	game->player.img = mlx_xpm_file_to_image(game->mlx, "./sprites/player.xpm", \
		&game->player.width, &game->player.height);
	game->gold.img = mlx_xpm_file_to_image(game->mlx, "./sprites/gold.xpm", \
		&game->gold.width, &game->gold.height);
	game->exit.img = mlx_xpm_file_to_image(game->mlx, "./sprites/exit.xpm", \
		&game->exit.width, &game->exit.height);
}
