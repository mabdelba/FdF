/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converthexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:48:57 by mabdelba          #+#    #+#             */
/*   Updated: 2022/02/11 18:50:57 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	val(char c)
{
	if (c == 'a' || c == 'A')
		return (10);
	else if (c == 'b' || c == 'B')
		return (11);
	else if (c == 'c' || c == 'C')
		return (12);
	else if (c == 'd' || c == 'D')
		return (13);
	else if (c == 'e' || c == 'E')
		return (14);
	else if (c == 'f' || c == 'F')
		return (15);
	return (c - 48);
}

int	ft_convert(char *str)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	if (!str)
		return (0x00FFFFFF);
	while (str[i] == '0' || str[i] == 'x')
		i++;
	while (str[i])
	{
		result *= 16;
		result = result + val(str[i]);
		i++;
	}
	return (result);
}
