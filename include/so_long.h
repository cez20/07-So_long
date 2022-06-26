/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:04:51 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/06/26 12:04:37 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include <mlx.h> Cette facon devrait aussi fonctionner 
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h> 
# include <stdio.h> // Important de l'enlever sauf si on utilise perror
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# define ERR_FD "ERROR! Argument(map) does not exist\n"
# define ERR_EXT "ERROR! Map does not have extension .ber\n"
# define ERR_MAP "ERROR! Map does not meet basic requirements\n"

typedef struct s_var
{
	int		width;
	int		height;
	char	**map;
}				t_var;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

// *** MAIN.C ***
int		main(int argc, char **argv);
void	map_extension_validation(char *str, int fd);

// *** PARSING.C ***
void	map_parsing(t_var *map);
void	verify_walls(t_var *map, int *i);
void	map_size(t_var *map, int fd);
void	map_malloc(t_var *map, int fd, char *argv);
void	error(char *str);

#endif