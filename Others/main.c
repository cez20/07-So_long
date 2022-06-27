/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:20:45 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/06/27 13:55:43 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Pour lire les man /usr/share/man/man3/ <name of the man page you want to read>
// Ce qu'on doit mettre pour compiler ce programme 
//gcc -Iminilibx-linux  main.c -L minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit
//gcc -Iminilibx_opengl_20191021 main.c -L minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit

// int deal_key(int key, void *param)
// {
// 	(void)param;
// 	ft_putnbr_fd(key, 0);
// 	ft_putchar_fd('\n', 0);
//     return (0);
// }

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color; // On va essayer de mieux comprendre ceci prochainement.  
}

int main (int argc, char **argv) // Je mets ici un document en format .ber.
{
    void    *mlx; // pointeur void qui va contenir l'identifiant de connexion au serveur graphique 
    void    *mlx_window; // pointeur void qui va contenir l'identifiant de la nouvelle fenetre ouverte. 
	t_data	img;
	int x;
	int y;
	
    x = 0;
	y = 0;
    mlx = mlx_init(); // mlx_init renvoie un void *. Cela cree un identifiant de connexion au serveur graphique. Une fois appele, la connexion est etablie
	mlx_window = mlx_new_window(mlx, 1920, 1080, "so long"); //Recuperer l'identifiant de la nouvelle fenetre ouverte
    img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    while (y < 100)
	{
		while (x < 100)
		{
			my_mlx_pixel_put(&img, x, y, 0x2F3297);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
	
	//mlx_key_hook(mlx_window, deal_key, (void *)0);
    mlx_loop(mlx); // Cette fonction va dire au macOs de dessiner ce que vous lui avez demande de dessine. Permet aussi de gerer des evenements.  
}

//Function pour malloc suffisament d'espace a mon tableau 2D. 
void	map_malloc(t_var *map, int fd, char *argv)
{
	char	*str;
	char	*str1;
	int 	i;
	int 	width;

	i = 0;
	width = map->width;
	map->map = malloc((map->height + 1) * sizeof(map->map));
	map->map[map->height] = 0;
	while (i < map->height)
	{
		map->map[i] = malloc((map->width) * sizeof(char *));
		map->map[i][map->width] = '\0';
		i++;
	}
	close(fd);
	fd = open(argv, O_RDONLY);
	i = 0;
	while (i < map->height)
	{
		str = get_next_line(fd);
		str1 = ft_strtrim(str, "\n"); // Est-ce qu'il s'agit d'une bonne pratique reprendre meme pointeur
		ft_strlcpy(map->map[i], str1, ft_strlen(str1));
		free(str);
		free(str1);
		str = NULL;
		str1 = NULL;
		i++;
	}
	printf("%s\n", str);
	printf("%s\n", str1); // Ce pointeur ne semble pas vouloir free. 
}

// void	verify_lines(t_var *map, int *i)
// {
// 	int j;
// 	int c;
// 	int e;
// 	int p;
// 	int o;
// 	int one;

// 	j = 0;
// 	c = 0;
// 	e = 0;
// 	p = 0;
// 	o = 0;
// 	one = 0;
// 	while (map->map[*i][j])
// 	{
// 		if (j == 0 | j == (map->width - 1))
// 		{
// 			if (map->map[*i][j] != '1')
// 				error(ERR_MAP);
// 		}
// 		else
// 		{
// 			if (map->map[*i][j] == '0')
// 				o += 1;
// 			else if (map->map[*i][j] == 'C')
// 				c += 1;
// 			else if (map->map[*i][j] == 'E')
// 				e += 1;
// 			else if (map->map[*i][j] == 'P')
// 				p += 1;
// 			else if (map->map[*i][j] == '1')
// 				one += 1;
// 			else
// 				error(ERR_MAP);
// 		}
// 		j++;
// 	}
// 	printf("Inside lines of index #%d are valid\n", *i);
// }