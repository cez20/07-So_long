/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:33:53 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/06/27 13:58:49 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_extension_validation(char *str, int fd)
{
	str = ft_strrchr(str, '.');
	if (ft_strcmp(str, ".ber") != 0)
	{
		close(fd);
		error(ERR_EXT);
	}
}

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
	int		i;

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
		if (ft_strlen(map->map[i]) != (size_t)map->width)
			error (ERR_MAP);
		i++;
	}
}
