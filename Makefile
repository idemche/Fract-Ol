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
MLX_FLAGS = -lmlx -framework OpenGl -framework AppKit
SRC = fractol.c ft_keys.c ft_initializers.c ft_calculations.c \
		ft_algorithms.c ft_algorithms_two.c
OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)
$(NAME): $(OBJ)
	clang $(FLAGS) $(MLX_FLAGS) -o $(NAME) $(SRC)
	rm -r $(OBJ)

%.o: %.c
	clang -c $(FLAGS) -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OBJ) $(NAME)

re: fclean all
