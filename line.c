/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:56:52 by mabdelba          #+#    #+#             */
/*   Updated: 2022/02/11 19:16:07 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	nbr_colonne(char *str)
{
	int	i;
	int	compt;

	i = 0;
	compt = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != '\0')
			compt++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (compt);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

t_matr	*ft_line(char *str)
{
	t_matr	*line;
	int		i;
	char	**split;
	char	**split2;
	int		nbc;

	nbc = nbr_colonne(str);
	split = ft_split(str, ' ');
	line = malloc(nbc * sizeof(t_matr));
	if (!line)
		return (NULL);
	i = 0;
	while (i < nbc)
	{
		split2 = ft_split(split[i], ',');
		line[i].hg = ft_atoi(split2[0]);
		line[i].clr = ft_convert(split2[1]);
		free_tab(split2);
		i++;
	}
	free_tab(split);
	return (line);
}
