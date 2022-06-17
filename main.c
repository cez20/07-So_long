/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:20:45 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/06/17 14:54:50 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h" // inclut la libraire mlx.h
#include <unistd.h>

// Ce qu'on doit mettre pour compiler ce programme 
//gcc -Iminilibx-linux  main.c -L minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit

void ft_putchar(char c)
{
    write(1, &c, 1);
}


int deal_key(int key, void *param)
{
    ft_putchar('Y');
    ft_putchar('E');
    ft_putchar('S');
    return (0);
}

int main ()
{
    void    *mlx_ptr;
    void    *win_ptr;
    
    mlx_ptr = mlx_init(); // mlx_init renvoie un void *. Cela cree un identifiant de connexion au serveur graphique. Une fois appele, la connexion est etablie   
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "so long"); //Recuperer l'identifiant de la nouvelle fenetre ouverte
    mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
    mlx_key_hook(win_ptr, deal_key, (void *)0);
    mlx_loop(mlx_ptr); // Cette fonction va dire au macOs de dessiner ce que vous lui avez demande de dessine. Permet aussi de gerer des evenements.  
}