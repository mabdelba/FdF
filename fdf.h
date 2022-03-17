/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:53:15 by mabdelba          #+#    #+#             */
/*   Updated: 2022/02/11 22:49:26 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
int		ft_strchr(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char	*str);
int		ft_convert(char *str);
int		nbr_ligne(char *path);
int		nbr_colonne(char *str);
typedef struct s_matr {
	int	hg;
	int	clr;
}				t_matr;
t_matr	**ft_matrice(char *path);
t_matr	*ft_line(char *str);
void	iso(int *x, int *y, int z);
typedef struct s_point {
	int	x;
	int	y;
}				t_point;
void	bham(t_point *f, t_point *s, t_data *img, int color);
void	draw_map(int zoom, char *path, t_data *img, t_matr **matrice);
typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;
typedef struct s_fdf {
	void	*mlx;
	void	*mlx_win;
}				t_fdf;

#endif
