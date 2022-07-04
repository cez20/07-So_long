/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:20:45 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/07/04 14:19:11 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// system_profiler SPDisplaysDataType | grep Resolution
//man /usr/share/man/man3/mlx

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_var	map;
	t_mlx	mlx;
	t_img	img;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			error(ERR_FD);
		map_valid_extension(argv[1], fd);
		map_size(&map, fd);
		map_malloc(&map, fd, argv[1]);
		map_parsing(&map);
		mlx.mlx = mlx_init();
		if (map.width * 64 > 1920 || map.height * 64 > 1080) // Find a way for computer to detect size of main screen.  
			error(ERR_WIN);
		mlx.window = mlx_new_window(mlx.mlx, map.width * 64, map.height * 64, "so_long"); // Cree une nouvelle fenetre
		img.img = mlx_new_image(mlx.mlx, map.width * 64, map.height * 64); //Cree une nouvelle image de la meme grosseur que la fenetre. 
		img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian); // On obtient l'adresse de l'image complete
		load_images(mlx.mlx, &map);
		mlx_loop(mlx.mlx);
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