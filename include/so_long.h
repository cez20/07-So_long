/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:04:51 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/06/28 13:20:25 by cemenjiv         ###   ########.fr       */
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
# define ERR_ITEMS "ERROR! There are some mandatory items missing\n"

typedef struct s_var
{
	char	**map;
	int		width;
	int		height;
	int		pos;
	int		exit;
	int 	collectible;
}				t_var;

typedef struct s_mlx
{
	void	*mlx; // A mettre dans un autre structure?
	void	*window; // A mettre dans une autre structure? 
	void	*img;
	char	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_mlx;

// typedef struct s_data
// {
// 	void	*img;
// 	char	*img_addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// *** MAIN.C ***
int		main(int argc, char **argv);
void	error(char *str);

// *** MAP_VALIDATION.C
void	map_extension_validation(char *str, int fd);
void	map_size(t_var *map, int fd);
void	map_malloc(t_var *map, int fd, char *argv);

// *** MAP_PARSING.C *** 
void	map_parsing(t_var *map);
void	verify_map_walls(t_var *map, int *i);
void	verify_map_lines(t_var *map, int *i);
void	verify_vertical_wall(t_var *map, int *i, int *j);
void	verify_map_items(t_var *map, int *i, int *j);

// *** INIT_MLX ***
void	init_mlx(t_var *map);
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);


#endif