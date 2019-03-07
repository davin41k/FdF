# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/27 18:49:39 by dshereme          #+#    #+#              #
#    Updated: 2019/03/07 17:58:58 by dshereme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	fdf

LIB		:= ./libft/libft.a

GNL		:=	./get_next_line

CC		:=	gcc

FLAGS	:=	-g -Wall -Werror -Wextra

MLX_CC	:=	-lmlx -framework OpenGL -framework AppKit

SRC		:=	main.c \
			read_figure.c \
			norminate.c \
			initialization.c \
			dda.c \
			$(GNL)/get_next_line.c

OBJ		:=	$(SRC:%.c=%.o)

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) $(FLAGS) -o $(NAME) $(SRC) -I fdf.h $(LIB) -L ./minilibx $(MLX_CC)


all: $(NAME)

clean:
	@rm -f $(OBJ)
	@rm -f $(GNL)/*.o
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all
