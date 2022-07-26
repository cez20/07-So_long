/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:47:19 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/07/26 11:38:36 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	load_image(game->mlx, "./sprites/wall.xpm", &game->wall);
	load_image(game->mlx, "./sprites/floor.xpm", &game->floor);
	load_image(game->mlx, "./sprites/player.xpm", &game->player);
	load_image(game->mlx, "./sprites/gold.xpm", &game->gold);
	load_image(game->mlx, "./sprites/exit.xpm", &game->exit);
	image_pixel(&game->wall);
	image_pixel(&game->floor);
	image_pixel(&game->player);
	image_pixel(&game->gold);
	image_pixel(&game->exit);
}

void	load_image(void *mlx, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, \
	&img->line_length, &img->endian);
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
			my_mlx_pixel_put(image, x, y, color);
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
