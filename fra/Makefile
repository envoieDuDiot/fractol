# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvinogra <vvinogra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/25 16:41:32 by vvinogra          #+#    #+#              #
#    Updated: 2018/01/02 14:12:58 by vvinogra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

SRC = main.c solution_m.c image.c zoom_and_iter_move.c \
	solution_j.c hook.c colors.c colors2.c solution_b.c solution_p.c \
	solution_t.c solution_j_s.c frac_comparing.c solution_my.c solution_c.c

OBJ = $(SRC:.c=.o)

HEADER = libft/includes

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) -o $(NAME) -lmlx -framework OpenGL -framework AppKit $(OBJ) -L libft -lft

%.o: %.c
	$(CC) -c $(FLAGS) -o $@ $< -I $(HEADER)

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all
