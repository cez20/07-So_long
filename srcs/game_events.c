/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:58:02 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/07/26 14:18:33 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_tile(t_game **game, int x, int y)
{
	(*game)->map[(*game)->player_x][(*game)->player_y] = '0';
	(*game)->map[x][y] = 'P';
	(*game)->player_x = x;
	(*game)->player_y = y;
}

void	move_player(t_game *game, int a, int b)
{
	int	x;
	int	y;

	x = game->player_x + a;
	y = game->player_y + b;
	if (game->map[x][y] != '1')
	{
		if (game->map[x][y] == 'E')
			quit(game);
		else if (game->map[x][y] == 'C')
		{
			game->collectibles -= 1;
			change_tile(&game, x, y);
		}
		else if (game->map[x][y] == '0')
			change_tile(&game, x, y);
		if (game->map[x][y] != 'E')
		{
			game->count += 1;
			ft_putnbr_fd(game->count, 0);
			ft_putchar_fd('\n', 0);
		}
	}
}

int	key_code(int key, t_game *game)
{
	if (key == 53)
		close_window(game);
	else if (key == 0)
		move_player(game, 0, -1);
	else if (key == 1)
		move_player(game, 1, 0);
	else if (key == 2)
		move_player(game, 0, 1);
	else if (key == 13)
		move_player(game, -1, 0);
	return (0);
}

void	mlx_events(t_game *game)
{
	mlx_key_hook(game->window, key_code, game);
	mlx_hook(game->window, 17, 0, close_window, game);
}
