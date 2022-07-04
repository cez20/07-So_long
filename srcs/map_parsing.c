/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 11:41:13 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/07/03 17:03:37 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_parsing(t_var *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		if (i == 0 || i == (map->height - 1))
			verify_map_walls(map, &i);
		else
			verify_map_lines(map, &i);
		i++;
	}
	if (map->collect < 1 || map->exits < 1 || map->pos < 1)
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
}

void	verify_vertical_wall(t_var *map, int *i, int *j)
{
	if (map->map[*i][*j] != '1')
		error(ERR_MAP);
}

void	verify_map_items(t_var *map, int *i, int *j)
{
	//int	digit;

	//digit = 0;
	if (map->map[*i][*j] == '0' || map->map[*i][*j] == '1');
		//digit = 1;
	else if (map->map[*i][*j] == 'C')
		map->collect = 1;
	else if (map->map[*i][*j] == 'E')
		map->exits = 1;
	else if (map->map[*i][*j] == 'P')
		map->pos = 1;
	else
		error(ERR_MAP);
}
