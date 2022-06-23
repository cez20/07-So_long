/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:20:45 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/06/22 11:09:33 by cemenjiv         ###   ########.fr       */
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