/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:20:45 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/06/27 13:59:55 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_var	map;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			error(ERR_FD);
		map_extension_validation(argv[1], fd);
		map_size(&map, fd);
		map_malloc(&map, fd, argv[1]);
		map_parsing(&map);
		init_mlx();
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