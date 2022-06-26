/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:20:45 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/06/26 13:11:42 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Don't forget to close fd at the end of program
//Another name for map_size could be map_width_height.
// Je vais verifier s'il vaudrait la peine de mettre fd dans la struct t_var
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
	}
	return (0);
}

//Please remove printf below
void	map_extension_validation(char *str, int fd)
{
	str = ft_strrchr(str, '.');
	if (ft_strcmp(str, ".ber") != 0)
	{
		close(fd);
		error(ERR_EXT);
	}
	printf("This map is valid!\n");
}

// Enlever les printf ici-bas
void	map_size(t_var *map, int fd)
{
	char	*str;
	char	*str1;

	str = get_next_line(fd);
	str1 = ft_strtrim(str, "\n");
	free(str);
	map->width = ft_strlen(str1); 
	free(str1);
	printf("%d\n", map->width);
	map->height = 1;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		free(str);
		map->height++;
	}
	printf("%d\n", map->height);
}

void	map_malloc(t_var *map, int fd, char *argv)
{
	char	*str;
	char	*str1;
	int 	i;
	
	i = 0;
	map->map = malloc((map->height + 1) * sizeof(map->map));
	map->map[map->height] = 0;
	close(fd);
 	fd = open(argv, O_RDONLY);
	while (i < map->height)
	{
		map->map[i] = malloc((map->width + 1) * sizeof(char *));
		str = get_next_line(fd);
		str1 = ft_strtrim(str, "\n");
		free (str);
		ft_strlcpy(map->map[i], str1, ft_strlen(str1) + 1);
		free (str1);
		if(ft_strlen(map->map[i]) != (size_t)map->width)
			error (ERR_MAP);
		i++;
	}
	printf("%zu\n", ft_strlen(map->map[0]));
}

// Pour lire les man /usr/share/man/man3/ <page/
void	error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}
