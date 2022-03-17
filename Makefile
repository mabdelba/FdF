# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 23:06:33 by mabdelba          #+#    #+#              #
#    Updated: 2022/02/12 23:24:03 by mabdelba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	bresenham.c draw_map.c fdf.c ft_atoi.c ft_converthexa.c \
		ft_split.c ft_substr.c isometrie.c get_next_line_utils.c \
		line.c matrice.c get_next_line.c
		
OBJS = $(SRCS:.c=.o)



NAME = fdf

CFLAGS = -Wall -Wextra -Werror
CC = gcc

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
	
$(NAME) : $(OBJS)
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all 
