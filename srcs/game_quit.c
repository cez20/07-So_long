/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_quit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:22:05 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/07/14 13:23:25 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	quit(t_game *game)
{
	if (game->collectibles == 0)
		close_window(game);
}

int	close_window(t_game *game)
{
	free_game(game);
	exit(EXIT_SUCCESS);
}
