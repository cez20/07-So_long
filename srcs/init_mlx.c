/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:03:15 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/06/27 14:26:44 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img_addr + ((y * data->line_length) + (x * (data->bits_per_pixel / 8)));
	*(unsigned int*)dst = color; // On va essayer de mieux comprendre ceci prochainement.  
}

void	init_mlx()
{
	t_mlx	mlx;
	int		x;
	int 	y;

	x = 0;
	y = 0;
	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, 1920, 1080, "so_long");
	mlx.img = mlx_new_image(mlx.mlx, 1920, 1080); // Permet de creer un image de meme format que la fenetre pour y mettre
	mlx.img_addr =  mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length, &mlx.endian);
	while (y < 100)
	{
		while (x < 100)
		{
			my_mlx_pixel_put(&mlx, x, y, 0x2F3297);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.img, 0, 0);
    mlx_loop(mlx.mlx);
}