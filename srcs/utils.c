/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:07:11 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/07/12 13:05:36 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

void	free_game(t_game *game)
{
	int i;

	i = game->height - 1;
	while (i >= 0)
	{
		free(game->map[i]);
		i--;
	}
	i = 0;
	free(game->map);
}

void	init_items(t_game *game)
{
	game->collectibles = 0;
	game->players = 0;
	game->exits = 0;
	game->count = 0;
	game->player_x = 0;
	game->player_y = 0;
}