# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/31 04:02:58 by idemchen          #+#    #+#              #
#    Updated: 2017/04/02 01:25:40 by idemchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FLAGS = -Wall -Werror -Wextra -O3
MLX_PATH = ./miniLibX
MLX_LIB = $(MLX_PATH)/libmlx.a
MLX_INC = -I $(MLX_PATH)
MLX_FLAGS = -framework OpenGL -framework AppKit

SRC = fractol.c ft_keys.c ft_initializers.c ft_calculations.c \
		ft_algorithms.c ft_algorithms_two.c
OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(MLX_LIB) $(NAME)

$(NAME): $(OBJ)
	clang $(FLAGS) $(OBJ) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	clang -c $(FLAGS) $(MLX_INC) -o $@ $<

$(MLX_LIB):
	$(MAKE) -C $(MLX_PATH)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)

re: fclean all
