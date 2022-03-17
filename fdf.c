/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:12:10 by mabdelba          #+#    #+#             */
/*   Updated: 2022/02/12 23:36:16 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_zoom(int *zoom, char *path)
{
	int	nbl;

	nbl = nbr_ligne(path);
	if (nbl < 50 && nbl != 47)
		*zoom = 20;
	else if (nbl <= 80)
		*zoom = 10;
	else if (nbl <= 115)
		*zoom = 6;
	else if (nbl <= 205)
		*zoom = 3;
	else
		*zoom = 1;
}

int	key_hook(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_fdf	fdf;
	t_data	img;
	t_matr	**matrice;
	int		zoom;
	t_vars	vars;

	if (ac != 0)
	{
		fdf.mlx = mlx_init();
		fdf.mlx_win = mlx_new_window(fdf.mlx, 1920, 1080, "Abdelbar's FdF");
		img.img = mlx_new_image(fdf.mlx, 1920, 1080);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
				&img.line_length, &img.endian);
		vars.mlx = fdf.mlx;
		vars.win = fdf.mlx_win;
		matrice = ft_matrice(av[1]);
		change_zoom(&zoom, av[1]);
		draw_map(zoom, av[1], &img, matrice);
		mlx_key_hook(fdf.mlx_win, key_hook, &vars);
		mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, img.img, 0, 0);
		mlx_loop(fdf.mlx);
	}
}
