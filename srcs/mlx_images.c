/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:47:19 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/07/04 14:01:56 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_image(void *mlx, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, &img->endian);
}

void	load_images(void *mlx, t_var *map)
{
	
	load_image(mlx, "./sprites/wall.xpm", &map->wall);
	load_image(mlx, "./sprites/floor.xpm", &map->floor);
	load_image(mlx, "./sprites/player.xpm", &map->player);
	load_image(mlx, "./sprites/gold.xpm", &map->gold);
	load_image(mlx, "./sprites/exit.xpm", &map->exit);
	
}
