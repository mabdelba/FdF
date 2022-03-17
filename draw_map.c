/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:56:20 by mabdelba          #+#    #+#             */
/*   Updated: 2022/02/11 19:14:39 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*in_pt(int i, int j, int z)
{
	t_point	*a;

	a = (t_point *) malloc(sizeof(t_point));
	iso(&i, &j, z);
	a->x = i;
	a->y = j;
	return (a);
}

void	in_filed(char *path, int *nbl, int *nbc, t_point *a)
{
	int		fd;
	char	*str;

	fd = open(path, O_RDONLY);
	*nbl = nbr_ligne(path);
	str = get_next_line(fd);
	*nbc = nbr_colonne(str);
	free(str);
	(*a).y = 120;
	(*a).x = 770;
}

void	draw_map(int zoom, char *path, t_data *img, t_matr **mat)
{
	t_point	ij;
	t_point	a;
	int		nbl;
	int		nbc;

	in_filed(path, &nbl, &nbc, &a);
	ij.y = -1;
	while (++(ij.y) < nbc)
	{
		ij.x = -1;
		while (++(ij.x) < nbl)
		{
			if (ij.x < nbl - 1)
				bham(in_pt(a.x, a.y, mat[ij.x][ij.y].hg),
					in_pt(a.x, a.y + zoom, mat[(ij.x) + 1][ij.y].hg),
					img, mat[ij.x][ij.y].clr);
			if (ij.y < nbc - 1)
				bham(in_pt(a.x, a.y, mat[ij.x][ij.y].hg),
					in_pt(a.x + zoom, a.y, mat[ij.x][(ij.y) + 1].hg),
					img, mat[ij.x][ij.y].clr);
			a.y = a.y + zoom;
		}
		a.x = a.x + zoom;
		a.y = 120;
	}
}
