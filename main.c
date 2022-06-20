/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:20:45 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/06/20 12:52:38 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h" // inclut la libraire mlx.h
#include <unistd.h>

// Ce qu'on doit mettre pour compiler ce programme 
//gcc -Iminilibx-linux  main.c -L minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit
//gcc -Iminilibx_opengl_20191021 main.c -L minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit

void ft_putchar(char c);
void	ft_putnbr_fd(int n, int fd);

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	nb;

	nb = (long long)n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd((nb / 10), fd);
		nb = nb % 10;
	}
	if (nb >= 0 && nb < 10)
		ft_putchar(nb + '0');
}

int deal_key(int key, void *param)
{
    //ft_putchar('Y');
	ft_putnbr_fd(key, 0);
	ft_putchar('\n');
    return (0);
}

int main ()
{
    void    *mlx_ptr; // pointeur void qui va contenir l'identifiant de connexion au serveur graphique 
    void    *win_ptr; // pointeur void qui va contenir l'identifiant de la nouvelle fenetre ouverte. 
    
    mlx_ptr = mlx_init(); // mlx_init renvoie un void *. Cela cree un identifiant de connexion au serveur graphique. Une fois appele, la connexion est etablie
	//if (!mlx_ptr)
	//	return ; // Or return NULL
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "so long"); //Recuperer l'identifiant de la nouvelle fenetre ouverte
    mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xffa500); // Fonction qui permet de dessiner un pixel specifique dans win_ptr and utilisant les coordonnees X et Y. 
	mlx_key_hook(win_ptr, deal_key, (void *)0);
    mlx_loop(mlx_ptr); // Cette fonction va dire au macOs de dessiner ce que vous lui avez demande de dessine. Permet aussi de gerer des evenements.  
}