/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_quit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:22:05 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/07/26 14:18:57 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	quit(t_game *game)
{
	if (game->collectibles == 0)
		close_window(game);
}

int	close_window(t_game *game)
{
	free_game(game);
	mlx_destroy_image(game->mlx, game->wall.img);
	mlx_destroy_image(game->mlx, game->floor.img);
	mlx_destroy_image(game->mlx, game->player.img);
	mlx_destroy_image(game->mlx, game->gold.img);
	mlx_destroy_image(game->mlx, game->exit.img);
	mlx_destroy_window(game->mlx, game->window);
	exit(EXIT_SUCCESS);
}
