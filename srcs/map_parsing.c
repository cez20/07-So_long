/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 11:41:13 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/06/27 14:01:43 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_parsing(t_var *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		if (i == 0 || i == (map->height - 1))
			verify_map_walls(map, &i);
		else
			verify_map_lines(map, &i);
		i++;
	}
	if (map->collectible < 1 || map->exit < 1 || map->pos < 1)
		error(ERR_ITEMS);
}

void	verify_map_walls(t_var *map, int *i)
{
	int	j;

	j = 0;
	while (map->map[*i][j])
	{
		if (map->map[*i][j] != '1')
			error(ERR_MAP);
		j++;
	}
	printf("First and last line of map is valid\n");
}

void	verify_map_lines(t_var *map, int *i)
{
	int	j;

	j = 0;
	while (map->map[*i][j])
	{
		if (j == 0 | j == (map->width - 1))
			verify_vertical_wall(map, i, &j);
		else
			verify_map_items(map, i, &j);
		j++;
	}
	printf("Inside lines are valid\n");
}

void	verify_vertical_wall(t_var *map, int *i, int *j)
{
	if (map->map[*i][*j] != '1')
		error(ERR_MAP);
}

void	verify_map_items(t_var *map, int *i, int *j)
{
	int	digit;

	digit = 0;
	if (map->map[*i][*j] == '0' || map->map[*i][*j] == '1')
		digit += 1;
	else if (map->map[*i][*j] == 'C')
		map->collectible = 1;
	else if (map->map[*i][*j] == 'E')
		map->exit = 1;
	else if (map->map[*i][*j] == 'P')
		map->pos = 1;
	else
		error(ERR_MAP);
}
