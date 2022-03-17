/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:57:04 by mabdelba          #+#    #+#             */
/*   Updated: 2022/02/11 22:54:57 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	nbr_ligne(char *path)
{
	char	*line;
	int		compt;
	int		fd;

	fd = open(path, O_RDONLY);
	compt = 0;
	line = get_next_line(fd);
	if (!line)
	{
		write(1, "No map !", 8);
		exit(0);
	}
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		compt++;
	}
	return (compt);
}

void	initialse_var(char *path, t_point *fd_nbc, t_point *b)
{
	fd_nbc->x = open(path, O_RDONLY);
	b->x = nbr_ligne(path);
}

t_matr	**ft_matrice(char *path)
{
	t_matr	**matrice;
	char	*str;
	t_point	b;
	t_point	fd_nbc;

	initialse_var(path, &fd_nbc, &b);
	str = get_next_line(fd_nbc.x);
	fd_nbc.y = nbr_colonne(str);
	matrice = malloc((b.x) * sizeof(t_matr *));
	if (!matrice)
		return (NULL);
	b.y = -1;
	while (++(b.y) < b.x)
	{
		if (nbr_colonne(str) < fd_nbc.y)
		{
			write(1, "Found wrong line length. Exiting.", 33);
			exit(0);
		}
		matrice[b.y] = ft_line(str);
		free(str);
		str = get_next_line(fd_nbc.x);
	}
	return (matrice);
}
