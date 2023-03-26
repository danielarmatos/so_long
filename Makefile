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
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
#CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L ./minilibx -lm -lmlx -Ilmlx -lXext -lX11
DEPS = minilibx/mlx.h libft/libft.a

NAME = so_long
BONUS_NAME = so_long_bonus

SRC = src/so_long.c src/destroy_map.c src/display_map.c src/validate_map.c src/display_map02.c src/move_player.c src/validate_path.c src/display_map03.c src/render_map.c src/validate_map02.c
OBJ = $(SRC:.c=.o)

BONUS = src_bonus/so_long.c src_bonus/destroy_map.c src_bonus/display_map.c src_bonus/validate_map.c src_bonus/display_map02.c src_bonus/move_player.c src_bonus/validate_path.c src_bonus/display_map03.c src_bonus/render_map.c src_bonus/validate_map02.c src_bonus/setup_sprites.c
BONUS_OBJ = $(BONUS:.c=.o)

LIBFT = libft/libft.a

all: deps $(NAME)
	
deps:
	$(MAKE) -C ./libft
	$(MAKE) -C ./minilibx
$(NAME): $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME) -g

clean:
	$(MAKE) $@ -C ./libft
	$(MAKE) $@ -C ./minilibx
	@rm -rf $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(MAKE) $@ -C ./libft
	@rm -rf $(NAME) $(BONUS_NAME)

bonus: bonus_deps $(BONUS_NAME)

bonus_deps:
	$(MAKE) -C ./libft
	$(MAKE) -C ./minilibx
$(BONUS_NAME): $(BONUS_OBJ) $(DEPS)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) $(MLXFLAGS) -o $(BONUS_NAME) -g

re: fclean all
	$(MAKE) re -C ./libft
	$(MAKE) re -C ./minilibx
