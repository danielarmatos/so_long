# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 18:49:16 by dreis-ma          #+#    #+#              #
#    Updated: 2023/02/16 18:49:22 by dreis-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L ./minilibx -lm -lmlx -Ilmlx -lXext -lX11
DEPS = minilibx/mlx.h libft/libft.a

NAME = so_long
SRC = $(filter-out $(shell find src -type f -name '*_test.c'), $(shell find src -type f -name '*.c'))
OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

all: deps $(NAME)
	
deps:
	$(MAKE) -C ./libft
	$(MAKE) -C ./minilibx
$(NAME): $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)

clean:
	$(MAKE) $@ -C ./libft
	$(MAKE) $@ -C ./minilibx
	@rm -rf $(OBJ)

fclean: clean
	$(MAKE) $@ -C ./libft
	@rm -rf $(NAME)

re: fclean all
	$(MAKE) re -C ./libft
	$(MAKE) re -C ./minilibx
