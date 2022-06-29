/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:03:15 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/06/29 13:44:41 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->img_addr + ((y * data->line_length) + (x * (data->bits_per_pixel / 8)));
// 	*(unsigned int*)dst = color; // On va essayer de mieux comprendre ceci prochainement.  
// }

void	init_mlx(t_var *map)
{
	t_mlx	mlx;
	t_img	img;
	char    *relative_path = "./images/wall.xpm";
	char    *relative_path1 = "./images/floor.xpm";
	char    *relative_path2 = "./images/exit.xpm";
	char    *relative_path3 = "./images/gold.xpm";
	char    *relative_path4 = "./images/player.xpm";
	int 	i;
	int		j;
	int		x;
	int 	y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, map->width * 64, map->height * 64, "so_long");
	img.img = mlx_new_image(mlx.mlx, map->width * 64, map->height * 64);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while (y < (map->height * 64))
	{
		while (x < (map->width * 64))   
		{
			j = 0;
			if (map->map[i][j] == '1')
				img.img = mlx_xpm_file_to_image(mlx.mlx, relative_path, &img.width, &img.height);
			else if(map->map[i][j] == '0')
				img.img = mlx_xpm_file_to_image(mlx.mlx, relative_path1, &img.width, &img.height);
			else if (map->map[i][j] == 'E')
				img.img = mlx_xpm_file_to_image(mlx.mlx, relative_path2, &img.width, &img.height);
			else if (map->map[i][j] == 'C')
				img.img = mlx_xpm_file_to_image(mlx.mlx, relative_path3, &img.width, &img.height);
			else if (map->map[i][j] == 'P')
				img.img = mlx_xpm_file_to_image(mlx.mlx, relative_path4, &img.width, &img.height);
			mlx_put_image_to_window(mlx.mlx, mlx.window, img.img, x, y);
			x += 64;
			j++;
		}
		i++;
		x = 0;
		y += 64;
	}	
    mlx_loop(mlx.mlx);
}