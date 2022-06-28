/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:03:15 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/06/28 15:13:15 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img_addr + ((y * data->line_length) + (x * (data->bits_per_pixel / 8)));
	*(unsigned int*)dst = color; // On va essayer de mieux comprendre ceci prochainement.  
}

void	init_mlx(t_var *map)
{
	(void)map;
	t_mlx	mlx;
	//char    *relative_path = "./images/bricksx64.xpm";
	char	*relative_path1 = "./images/stein2x64.xpm";
	int 	img_width;
	int 	img_height;
	int		x;
	int 	y;
	int		i;
	int		j;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, 1920, 1080, "so_long");
	//mlx.img = mlx_xpm_file_to_image(mlx.mlx, relative_path, &img_width, &img_height);
	//mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.img, x, y);
	while (y < 1080)
	{
		while (x < 1920)
		{
			mlx.img = mlx_xpm_file_to_image(mlx.mlx, relative_path1, &img_width, &img_height);
			mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.img, x, y);
			x += 64;
		}
		x = 0;
		y += 64;
	}	
    mlx_loop(mlx.mlx);
}