/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:58:02 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/07/06 19:13:57 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void quit(t_game *game)
{
	if (game->collectibles == 0)
		close_window();
}

void change_tile(t_game **game, int x, int y) // Voir si je peux passer un simple pointeur. 
{
	(*game)->map[(*game)->player_x][(*game)->player_y] = '0';
	(*game)->map[x][y] = 'P';
	(*game)->player_x = x;
	(*game)->player_y = y;
}

void move_player(t_game *game, int a, int b)
{
	int x;
	int y;

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
		if (game->map[x][y] != 'E') // Verifier si on ne peut pas faire autrement ici
		{
			game->count += 1;
			ft_putnbr_fd(game->count, 0);
			ft_putchar_fd('\n', 0);
		}
	}
}

int close_window(void)
{
	exit(EXIT_FAILURE);
	return (0);
}

int	key_code(int key, t_game *game) //Normalement la fonction key_code prend void* key_code(int key, void *param)
{
	if (key == 53) // Est-ce que ceci est considere comme quitte clean. On je dois free tout avant. 
		close_window();
	else if(key == 0)
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
}

// int	key_code(int key, t_game *game) //Normalement la fonction key_code prend void* key_code(int key, void *param)
// {
// 	if (key == 53) // Est-ce que ceci est considere comme quitte clean. On je dois free tout avant. 
// 		close_window();
// 	else if(key == 0)
// 		move_left(game);
// 	else if (key == 1)
// 		move_down(game);
// 	else if (key == 2)
// 		move_right(game);
// 	else if (key == 13)
// 		move_up(game);
// 	return (0);
// }


// void move_right(t_game *game)
// {
// 	int x;
// 	int y;

// 	x = game->player_x;
// 	y = game->player_y + 1;
	
// 	if (game->map[x][y] != '1')
// 	{
// 		game->count += 1;
// 		if (game->map[x][y] == 'E')
// 			quit(game);	
// 		else if (game->map[x][y] == 'C')
// 		{
// 			game->collectibles -= 1;
// 			change_tile(&game, x, y);
// 		}
// 		else if (game->map[x][y] == '0')
// 			change_tile(&game, x, y);
// 		ft_putnbr_fd(game->count, 0);
// 		ft_putchar_fd('\n', 0);	
// 	}
	
// }

// void move_up(t_game *game)
// {
// 	int x;
// 	int y;

// 	x = game->player_x - 1;
// 	y = game->player_y;
	
// 	if (game->map[x][y] != '1')
// 	{
// 		game->count += 1;
// 		if (game->map[x][y] == 'E')
// 			quit(game);	
// 		else if (game->map[x][y] == 'C')
// 		{
// 			game->collectibles -= 1;
// 			change_tile(&game, x, y);
// 		}
// 		else if (game->map[x][y] == '0')
// 			change_tile(&game, x, y);
// 		ft_putnbr_fd(game->count, 0);
// 		ft_putchar_fd('\n', 0);	
// 	}
// }


// void move_down(t_game *game)
// {
// 	int x;
// 	int y;

// 	x = game->player_x + 1;
// 	y = game->player_y;
	
// 	if (game->map[x][y] != '1')
// 	{
// 		game->count += 1;
// 		if (game->map[x][y] == 'E')
// 			quit(game);	
// 		else if (game->map[x][y] == 'C')
// 		{
// 			game->collectibles -= 1;
// 			change_tile(&game, x, y);
// 		}
// 		else if (game->map[x][y] == '0')
// 			change_tile(&game, x, y);
// 		ft_putnbr_fd(game->count, 0);
// 		ft_putchar_fd('\n', 0);	
// 	}
// }

// void move_left(t_game *game)
// {
// 	int x;
// 	int y;

// 	x = game->player_x;
// 	y = game->player_y - 1;
	
// 	if (game->map[x][y] != '1')
// 	{
// 		game->count += 1;
// 		if (game->map[x][y] == 'E')
// 			quit(game);	
// 		else if (game->map[x][y] == 'C')
// 		{
// 			game->collectibles -= 1;
// 			change_tile(&game, x, y);
// 		}
// 		else if (game->map[x][y] == '0')
// 			change_tile(&game, x, y);
// 		ft_putnbr_fd(game->count, 0);
// 		ft_putchar_fd('\n', 0);	
// 	}
// }