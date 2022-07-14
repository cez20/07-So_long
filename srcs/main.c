/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:20:45 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/07/14 13:27:46 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	t_img	img;
	int		fd;

	if (argc != 2)
		error(ERR_ARGS);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error(ERR_FD);
	map_valid_extension(argv[1], fd);
	map_size(&game, fd);
	map_malloc(&game, fd, argv[1]);
	map_parsing(&game);
	game.mlx = mlx_init();
	if (game.width * 64 > 1920 || game.height * 64 > 1080)
		error(ERR_WIN);
	game.window = mlx_new_window(game.mlx, game.width * 64, \
	game.height * 64, "so_long");
	img.img = mlx_new_image(game.mlx, game.width * 64, game.height * 64);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, \
	&img.line_length, &img.endian);
	load_images(&game);
	mlx_events(&game);
	mlx_loop_hook(game.mlx, put_image_on_symbol, &game);
	mlx_loop(game.mlx);
	return (0);
}

// P-e a mettre apres mlx_loop
//	mlx_destroy_image (game.mlx, img.addr); // P-e a enlever 
//	mlx_destroy_window(game.mlx, game.window); // P-e a enlever 
//	free_game(&game);