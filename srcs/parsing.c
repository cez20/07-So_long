/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 11:41:13 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/06/26 13:12:34 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verify_walls(t_var *map, int *i)
{
	int j;

	j = 0;
	while (map->map[*i][j])
	{
		if(map->map[*i][j] != '1')
			error(ERR_MAP);
		j++;
	}
	printf("First and last line of map is valid\n");
}

void	map_parsing(t_var *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		if(i == 0 || i == (map->height - 1))
			verify_walls(map, &i);
		i++;
	}	
}