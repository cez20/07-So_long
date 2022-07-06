/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imamape_to_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:33:28 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/07/05 11:38:31 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// SI on met des else if partout, les images s'affiche presque au complet. P-e faire des images d'avance
void	put_image_to_screen(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->window, \
		game->wall.img, x * 64, y * 64);
	else 
		mlx_put_image_to_window(game->mlx, game->window, \
		game->floor.img, x * 64, y * 64);
	if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->window, \
		game->player.img, x * 64, y * 64);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->window, \
		game->gold.img, x * 64, y * 64);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, \
		game->exit.img, x * 64, y * 64);
}

int	put_image_on_symbol(t_game *game)
{
	int i;
	int j;

	j = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i])
		{
			put_image_to_screen(game, i, j);
			i++;		
		}
		j++;		
	}
	return (0);	
}