/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:04:51 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/07/13 16:42:04 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h> 
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
//# include <mlx.h> //Cette facon devrait aussi fonctionner si ../minilibx/mlx.h ne fonctionne pas.

# define ERR_ARGS "There is NO arguments or more than 1 argument\n"
# define ERR_FD "FD(map) given does not exist!\n"
# define ERR_EXT "Map does not have extension '.ber'!\n"
# define ERR_LENGTH "Map lines are NOT the same length!\n"
# define ERR_EMPTY_LINE "There is an empty line in file!\n"
# define ERR_MAP "Map does not meet basic requirements!\n"
# define ERR_ITEMS "There are some mandatory items missing!\n"
# define ERR_WIN "The window is bigger than screen resolution!\n"

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

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int 	collectibles;
	int		players;
	int		exits;
	t_img	wall; 
	t_img	floor;
	t_img	player;
	t_img	gold;
	t_img	exit;
	void	*mlx; 
	void	*window; 
	int		count;
	int		player_x;
	int 	player_y;
}				t_game; 

// *** MAIN.C ***
int		main(int argc, char **argv);


// *** MAP_VALIDATION.C
void	map_valid_extension(char *str, int fd);
void	map_size(t_game *map, int fd);
void	map_malloc(t_game *map, int fd, char *argv);

// *** MAP_PARSING.C *** 
void	map_parsing(t_game *game);
void	verify_map_walls(t_game *game, int *i);
void	verify_map_lines(t_game *game, int *i);
void	verify_vertical_wall(t_game *game, int *i, int *j);
void	verify_map_items(t_game **game, int *i, int *j);

// *** GAME_IMAGES.C ***
void	nb_of_collectibles(t_game *game);
void	load_images(t_game *game);
void	load_image(void *mlx, char *path, t_img *img);
void	image_pixel(t_img *image);
unsigned int	get_colors(t_img *data, int x, int y);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

//*** IMAGE_TO_WINDOW.C 
int		put_image_on_symbol(t_game *game);
void	put_image_to_screen(t_game *game, int x, int y);

//** GAME_EVENTS.C
void	mlx_events(t_game *game);
int		key_code(int key, t_game *game);
int		close_window(t_game *game);
void 	change_tile(t_game **game, int x, int y);
void	move_player(t_game *game, int a, int b);
void 	quit(t_game *game);
int 	mouse_code(int button, int x, int y, void *param);

//*** UTILS.C ***
void	error(char *str);
void	free_game(t_game *game);
void	init_items (t_game *game);

#endif