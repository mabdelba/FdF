/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:54:59 by mabdelba          #+#    #+#             */
/*   Updated: 2022/02/11 19:13:44 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	signex(int x1, int x2)
{
	if (x1 < x2)
		return (1);
	else
		return (-1);
}

int	signey(int y1, int y2)
{
	if (y1 < y2)
		return (1);
	else
		return (-1);
}

void	bham(t_point *f, t_point *s, t_data *img, int color)
{
	t_point	delta;
	t_point	*cur;
	int		error[2];

	delta.x = abs(s->x - f->x);
	delta.y = abs(s->y - f->y);
	error[0] = delta.x - delta.y;
	cur = f;
	while (cur->x != s->x || cur->y != s->y)
	{
		my_mlx_pixel_put(img, cur->x, cur->y, color);
		error[1] = error[0] * 2;
		if (error[1] > -delta.y)
		{
			error[0] -= delta.y;
			cur->x += signex(f->x, s->x);
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur->y += signey(f->y, s->y);
		}
	}
	free(f);
	free(s);
}
