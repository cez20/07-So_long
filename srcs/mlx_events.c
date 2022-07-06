/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:58:02 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/07/06 14:22:50 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(void)
{
	exit(EXIT_FAILURE);
	return (0);
}

void start_count(int param)
{
	ft_putnbr_fd(param, 0);
	ft_putchar_fd('\n', 0);	
}

int	key_code(int key, int *param) //Normalement la fonction key_code prend void* key_code(int key, void *param)
{
	
	if (key == 53) // Est-ce que ceci est considere comme quitte clean. On je dois free tout avant. 
		close_window();
	else if (key == 0 || key == 1 || key == 2 || key == 13)
	{
		*param +=1;
		if (key == 0)
			start_count(*param);
		else if (key == 1)
			start_count(*param);
		else if (key == 2)
			start_count(*param);
		else if (key == 13)
			start_count(*param);
	}
	return (0);
}

void	mlx_events(t_mlx *mlx)
{
	mlx->count = 0;
	mlx_key_hook(mlx->window, key_code, &mlx->count);
}