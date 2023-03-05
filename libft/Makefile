# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 19:12:50 by dreis-ma          #+#    #+#              #
#    Updated: 2022/11/24 17:20:00 by dreis-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror -I.
DEPS = libft.h

SRC = $(filter-out $(shell find -type f -name '*_bonus.c'), $(shell find -type f -name '*.c'))

OBJ = $(SRC:.c=.o)

BONUS = $(shell find -type f -name '*_bonus.c')

BONUS_OBJ = $(BONUS:.c=.o)

NAME = libft.a

all: $(NAME)
$(NAME): $(OBJ) $(DEPS)
	@ar rcs $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ) $(BONUS_OBJ)

fclean: clean
	@rm -rf $(NAME)

bonus: $(OBJ) $(BONUS_OBJ) $(DEPS)
	@ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

re: fclean all
