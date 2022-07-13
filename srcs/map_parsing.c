/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 11:41:13 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/07/12 12:01:51 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Je devrais normalement passer un double pointeur si je veux que mon pointeur original soit modifie???
// On pourrait mettre cette fonction ailleurs. Initialize les items a 0;

void	map_parsing(t_game *game)
{
	int	i;

	i = 0;
	init_items(game);
	while (game->map[i])
	{
		if (i == 0 || i == (game->height - 1))
			verify_map_walls(game, &i);
		else
			verify_map_lines(game, &i);
		i++;
	}
	if (game->collectibles < 1 || game->exits < 1 || game->players != 1)
		error(ERR_ITEMS);
}

void	verify_map_walls(t_game *game, int *i)
{
	int	j;

	j = 0;
	while (game->map[*i][j])
	{
		if (game->map[*i][j] != '1')
			error(ERR_MAP);
		j++;
	}
}

void	verify_map_lines(t_game *game, int *i)
{
	int	j;

	j = 0;
	while (game->map[*i][j])
	{
		if (j == 0 | j == (game->width - 1))
			verify_vertical_wall(game, i, &j);
		else
			verify_map_items(&game, i, &j);
		j++;
	}
}

void	verify_vertical_wall(t_game *game, int *i, int *j)
{
	if (game->map[*i][*j] != '1')
		error(ERR_MAP);
}

void	verify_map_items(t_game **game, int *i, int *j)
{
	int digit;
		
	digit = 0;
	if ((*game)->map[*i][*j] == '0' || (*game)->map[*i][*j] == '1')
		digit +=1; 
	else if ((*game)->map[*i][*j] == 'C')
		(*game)->collectibles += 1;
	else if ((*game)->map[*i][*j] == 'E')
		(*game)->exits += 1;
	else if ((*game)->map[*i][*j] == 'P')
	{
		(*game)->player_x = *i;
		(*game)->player_y = *j;
		(*game)->players += 1;
	}
	else
		error(ERR_MAP);
}
