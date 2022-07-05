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

void	put_image_to_screen(t_var *map, t_mlx *mlx, int x, int y)
{
	if (map->map[y][x] == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->window, \
		map->wall.img, x * 64, y * 64);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->window, \
		map->floor.img, x * 64, y * 64);
	if (map->map[y][x] == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->window, \
		map->player.img, x * 64, y * 64);
	else if (map->map[y][x] == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->window, \
		map->gold.img, x * 64 + 8, y * 64 + 12);
	else if (map->map[y][x] == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->window, \
		map->exit.img, x * 64, y * 88);
}

int	put_image_on_symbol(t_var *map, t_mlx *mlx)
{
	(void)mlx;
	int i;
	int j;

	j = 0;
	while (map->map[j])
	{
		i = 0;
		while (map->map[j][i])
		{
			put_image_to_screen(map, mlx, i, j);
			i++;		
		}
		j++;		
	}
	return (0);	
}