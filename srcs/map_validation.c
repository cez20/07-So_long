/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:33:53 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/07/13 16:05:38 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_valid_extension(char *str, int fd)
{
	str = ft_strrchr(str, '.');
	if (ft_strcmp(str, ".ber") != 0)
	{
		close(fd);
		error(ERR_EXT);
	}
}

void	map_size(t_game *map, int fd)
{
	char	*str;
	char	*str1;

	str = get_next_line(fd);
	if (!str)
		error(ERR_EMPTY_LINE);
	str1 = ft_strtrim(str, "\n");
	free(str);
	str = NULL; // Avoid dangling pointer
	map->width = ft_strlen(str1);
	free(str1);
	str1 = NULL; // Avoid dangling pointer 
	map->height = 1;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		free(str);
		str = NULL;
		map->height++;
	}
}

void	map_malloc(t_game *game, int fd, char *argv)
{
	char	*str;
	int		i;

	i = 0;
	game->map = malloc((game->height + 1) * sizeof(char *));
	if (!game->map) // P-e a enlever
		error(ERR_EMPTY_LINE); //P-e a enlever
	game->map[game->height] = 0;
	close(fd);
	fd = open(argv, O_RDONLY);
	while (i < game->height)
	{
		str = get_next_line(fd);
		game->map[i] = ft_strtrim(str, "\n");
		free (str);
		str = NULL;
		if (ft_strlen(game->map[i]) != (size_t)game->width)
			error (ERR_LENGTH);
		i++;
	}
	close(fd);
}
