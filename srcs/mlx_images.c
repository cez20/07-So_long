/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:47:19 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/07/05 14:31:35 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(void *mlx, t_var *map)
{
	
	load_image(mlx, "./sprites/wall.xpm", &map->wall);
	load_image(mlx, "./sprites/floor.xpm", &map->floor);
	load_image(mlx, "./sprites/player.xpm", &map->player);
	load_image(mlx, "./sprites/gold.xpm", &map->gold);
	load_image(mlx, "./sprites/exit.xpm", &map->exit);
	image_pixel(&map->player);
	image_pixel(&map->wall);
	image_pixel(&map->floor);
	image_pixel(&map->gold);
	image_pixel(&map->exit);
}

void	load_image(void *mlx, char *path, t_img *img)
{
	
	printf("%d\n", img->width);
	printf("%d\n", img->height);
	img->img = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	printf("%d\n", img->width);
	printf("%d\n", img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, &img->endian);
}

void	image_pixel(t_img *image)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			color = get_colors(image, x, y);
			my_mlx_pixel_put(image, x, y, color); // Mettre &image au lieu de image
			x++;
		}
		y++;
	}
}

unsigned int	get_colors(t_img *data, int x, int y)
{
	char	*dst;

	dst = (data->addr + (y * data->line_length + x * data->bpp / 8));
	return (*(unsigned int *) dst);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = (data->addr + (y * data->line_length + x * data->bpp / 8));
	*(unsigned int *) dst = color;
}









// void	my_mlx_pixel_put(t_img **data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = ((*data)->addr + (y * (*data)->line_length + x * (*data)->bpp / 8));
// 	*(unsigned int *) dst = color;
// }

// unsigned int	get_colors(t_img **data, int x, int y)
// {
// 	char	*dst;

// 	dst = ((*data)->addr + (y * (*data)->line_length + x * (*data)->bpp / 8));
// 	return (*(unsigned int *) dst);
// }

//void	*image_scale_init(t_img *image, float scale, void *mlx)
// {
// 	t_img		image_scale;
// 	int				x;
// 	int				y;
// 	unsigned int	color;

// 	image_scale.width = image->width * scale;
// 	image_scale.height = image->height * scale;
// 	image_scale.img = mlx_new_image(mlx, image_scale.width, image_scale.height);
// 	image_scale.addr = mlx_get_data_addr(image_scale.img, &image_scale.bpp, \
// 	&image_scale.line_length, &image_scale.endian);
// 	y = 0;
// 	while (y < (image->height * scale))
// 	{
// 		x = 0;
// 		while (x < (image->width * scale))
// 		{
// 			color = get_colors(image, (x / scale), (y / scale));
// 			my_mlx_pixel_put(&image_scale, x, y, color);
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (image_scale.img);
// }

// void	load_images(void *mlx, t_var *map)
// {
// 	load_image(mlx, "./sprites/wall.xpm", &map->wall);
// 	load_image(mlx, "./sprites/floor.xpm", &map->floor);
// 	load_image(mlx, "./sprites/player.xpm", &map->player);
// 	load_image(mlx, "./sprites/gold.xpm", &map->gold);
// 	load_image(mlx, "./sprites/exit.xpm", &map->exit);
// 	map->player.img = image_scale_init(&map->player, 1, mlx);
// 	map->wall.img = image_scale_init(&map->wall, 1, mlx);
// 	map->floor.img = image_scale_init(&map->floor, 1, mlx);
// 	map->gold.img = image_scale_init(&map->gold, 1, mlx);
// 	map->exit.img = image_scale_init(&map->exit, 1, mlx);
// }
