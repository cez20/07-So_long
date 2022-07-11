/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:20:45 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/07/11 11:46:45 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// system_profiler SPDisplaysDataType | grep Resolution
//man /usr/share/man/man3/mlx

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
		if (game.width * 64 > 800 || game.height * 64 > 600)
			error(ERR_WIN);
		game.window = mlx_new_window(game.mlx, game.width * 64, game.height * 64, "so_long");
		img.img = mlx_new_image(game.mlx, game.width * 64, game.height * 64);
		img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
		load_images(&game);
		mlx_events(&game);
		mlx_loop_hook(game.mlx, put_image_on_symbol, &game);// Verifier si map est correct 
		mlx_loop(game.mlx);
	}
	return (0);
}

void	error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

// Pour lire les man /usr/share/man/man3/ <page/
//Don't forget to close fd at the end of program.
//Another name for map_size could be map_width_height.
// Je vais verifier s'il vaudrait la peine de mettre fd dans la struct t_var