/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:04:51 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/07/05 14:29:12 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h> 
# include <stdio.h> // Important de l'enlever sauf si on utilise perror
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
//# include <mlx.h> Cette facon devrait aussi fonctionner si ../minilibx/mlx.h ne fonctionne pas. 

# define ERR_FD "ERROR! Argument(map) does not exist\n"
# define ERR_EXT "ERROR! Map does not have extension .ber\n"
# define ERR_MAP "ERROR! Map does not meet basic requirements\n"
# define ERR_ITEMS "ERROR! There are some mandatory items missing\n"
# define ERR_WIN "ERROR! The window is bigger than screen resolution\n"

typedef struct s_img
{
 	void	*img;
 	char	*addr;
 	int		bpp;
 	int		line_length;
 	int		endian;
	int		width;
	int 	height;
}				t_img;

typedef struct s_var
{
	char	**map;
	int		width;
	int		height;
	int		players;
	int		exits;
	int 	collectibles;
	t_img	wall; 
	t_img	floor;
	t_img	player;
	t_img	gold;
	t_img	exit; 
}				t_var;

typedef struct s_mlx
{
	void	*mlx; // A mettre dans un autre structure? Par exemple, t_var
	void	*window; // A mettre dans une autre structure? 
}			t_mlx;

// *** MAIN.C ***
int		main(int argc, char **argv);
void	error(char *str);

// *** MAP_VALIDATION.C
void	map_valid_extension(char *str, int fd);
void	map_size(t_var *map, int fd);
void	map_malloc(t_var *map, int fd, char *argv);

// *** MAP_PARSING.C *** 
void	map_parsing(t_var *map);
void	verify_map_walls(t_var *map, int *i);
void	verify_map_lines(t_var *map, int *i);
void	verify_vertical_wall(t_var *map, int *i, int *j);
void	verify_map_items(t_var *map, int *i, int *j);

// *** MLX_IMAGES.C ***
void	load_images(void *mlx, t_var *map);
void	load_image(void *mlx, char *path, t_img *img);
void	image_pixel(t_img *image);
unsigned int	get_colors(t_img *data, int x, int y);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
//void	*image_scale_init(t_img *image, float scale, void *mlx);
//unsigned int	get_colors(t_img **data, int x, int y);
//void	my_mlx_pixel_put(t_img **data, int x, int y, int color);

//*** IMAGE_TO_WINDOW.C 
int		put_image_on_symbol(t_var *map, t_mlx *mlx);
void	put_image_to_screen(t_var *map, t_mlx *mlx, int x, int y);

#endif