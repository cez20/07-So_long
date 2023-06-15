/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:20:45 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/06/14 21:01:24 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error(ERR_ARGS);
	game.fd = open(argv[1], O_RDONLY);
	if (game.fd == -1)
		error(ERR_FD);
	map_valid_extension(argv[1], game.fd);
	map_size(&game, game.fd);
	map_malloc(&game, game.fd, argv[1]);
	map_parsing(&game);
	game.mlx = mlx_init();
	if (game.width * 64 > 1080 || game.height * 64 > 720)   //
		error(ERR_WIN);
	game.window = mlx_new_window(game.mlx, game.width * 64, \
	game.height * 64, "so_long");
	load_images(&game);
	mlx_events(&game);
	mlx_loop_hook(game.mlx, put_image_on_symbol, &game);
	mlx_loop(game.mlx);
	return (0);
}
