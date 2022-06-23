/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:20:45 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/06/23 15:12:10 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Pour lire les man /usr/share/man/man3/ <page/

void	error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

// Enlever les printf ici-bas 
// width is 10 (index), but len is 11 
//Might have to put height = 1, because 1 line has already been read.
//height is 3 (index), but len is 4.
//while (1) is an infinite loop until you tell to break it.  
void	map_size(t_var *map, int fd)
{
	char	*str;
	char	*str1;

	str = get_next_line(fd);
	str1 = ft_strtrim(str, "\n");
	free(str);
	map->width = ft_strlen(str1); // Sinon j'aurais pu mettre map-.width = ft_strlen(str) - 1;
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

//Please remove printf below
void	map_extension_validation(char *str, int fd)
{
	str = ft_strrchr(str, '.');
	if (ft_strcmp(str, ".ber") != 0)
	{
		close(fd);
		error(ERR_MAP);
	}
	printf("This map is valid!\n");
}

void	map_malloc(t_var *map, int fd, char *argv)
{
	char	*str;
	char	*str1;
	int 	i;
	int 	width;

	i = 0;
	width = map->width;
	map->map = malloc((map->height + 1) * sizeof(map->map));
	map->map[map->height] = 0;
	while (i < map->height)
	{
		map->map[i] = malloc((map->width + 1) * sizeof(char *));
		map->map[i][map->width] = '\0';
		i++;
	}
	close(fd);
	fd = open(argv, O_RDONLY);
	i = 0;
	while (i < map->height)
	{
		str = get_next_line(fd);
		str1 = ft_strtrim(str, "\n"); // Est-ce qu'il s'agit d'une bonne pratique reprendre meme pointeur
		free(str);
		strcpy(map->map[i], str1);
		free(str1);
		i++;
	}
	printf("%s\n", str);
	printf("%s\n", str1); // Ce pointeur ne semble pas vouloir free. 
	
}

//Version plus courte mais avec un bloc de memoire de plus pour chaque string
// void	map_malloc(t_var *map, int fd, char *argv)
// {
// 	int i;
// 	int width;

// 	i = 0;
// 	width = map->width;
// 	map->map = malloc((map->height + 1) * sizeof(map->map));
// 	map->map[map->height] = 0;
// 	close(fd);
//  	fd = open(argv, O_RDONLY);
// 	while (i < map->height)
// 	{
// 		map->map[i] = get_next_line(fd); // je vais avoir 2 \0 pcq strudpt en mets deja un 
// 		map->map[i][map->width] = '\0';
// 		i++;
// 	}
// }


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
	}
	return (0);
}
