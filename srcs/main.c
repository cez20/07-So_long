/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:20:45 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/07/11 19:43:33 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// system_profiler SPDisplaysDataType | grep Resolution

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	t_img	img;
	int		fd;

	if (argc == 2)
	{
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
		game.window = mlx_new_window(game.mlx, game.width * 64, game.height * 64, "so_long");
		img.img = mlx_new_image(game.mlx, game.width * 64, game.height * 64);
		img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
		load_images(&game);
		mlx_events(&game);
		mlx_loop_hook(game.mlx, put_image_on_symbol, &game);// Verifier si map est correct 
		mlx_loop(game.mlx);
		free_game (&game);
	}
	return (0);
}

//Another name for map_size could be map_width_height.
// Je vais verifier s'il vaudrait la peine de mettre fd dans la struct t_var