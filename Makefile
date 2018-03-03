# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbryon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/13 08:42:33 by gbryon            #+#    #+#              #
#    Updated: 2018/03/02 21:29:34 by gbryon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = Fractol

END=\033[0m
OKC=\033[32m
KOC=\033[31m

FLAG = -Wall -Wextra -Werror
FRAM = -lmlx -framework OpenGL -framework AppKit

OBJ_PATH = ./obj/
LFT_PATH = ./libft/
INC_PATH = ./include/
SRC_PATH = ./src/

OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = fractol.h
SRC_NAME = main.c

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
		@echo
		@make -C $(LFT_PATH)
		@gcc -o $(NAME) $(FRAM) -L $(LFT_PATH) -lft $^ -o $@
		@echo "$(OKC)$(NAME) CREATED & READY$(END)"
		@echo "                    ...\n                                          .....\n                                          ......\n                                          .......\n                                          ........\n                                          ........\n                                     ..   .........\n                                    ....  ..........\n                                   ...... ...........\n                                   ...................\n                                   ....................\n                                   ....................\n                                   .....................\n                                   ......................\n                                   ......................\n                                    .......................\n                                    ........................\n                                     .......................\n                                      .......................\n                                       ......................\n                                        .....................\n                                         ....................\n                                          ...................\n                                ....       ...................\n                              ........     ...................\n                             ...........    ..................\n                           ...............  ..................\n                         .....................................\n                       .......................................\n                    ..........................................\n                 .............................................\n                ..............................................\n               ................................................\n               ................................................\n                ...............................................\n                ...............   .............................\n                 ..........        ............................\n               ......               ...........................\n              ........                .........................\n             .........                 ........................\n             ..........                  ......................\n             ..........                     ...................\n             ..........                     ...................\n             ...........                    ...................\n             ...........                    ...................\n             ...........                    ...................\n             ...........                    ...................\n             ...........                     ..................\n             ...........                   ....................\n             ...........                  .....................\n            ..............              .......................\n            ...............           ........................\n            .................        .........................\n            ..................      ..........................\n             ...................  ...........................\n             ................................................\n              ..............................................\n               .............................................\n               ............................................\n                ...........................................\n                 .........................................\n                  .......................................\n                   ......................................\n                    ....................................\n                     ..................................\n                       ...............................\n                        .............................\n                          ..........................\n                             ......................\n                                ..............."


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		@mkdir -p $(OBJ_PATH)
		@gcc $(FLAG) $(INC) -o $@ -c $<
		@echo -n =

clean:
		@make -C $(LFT_PATH) clean
		@rm -rf $(OBJ_PATH)
		@echo "$(KOC)$(NAME)'s OBJS REMOVED$(END)"

fclean: clean
		@make -C $(LFT_PATH) fclean
		@rm -f $(NAME)
		@echo "$(KOCC)$(NAME) REMOVED$(END)"

re: fclean all