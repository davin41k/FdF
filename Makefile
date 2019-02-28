# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/27 18:49:39 by dshereme          #+#    #+#              #
#    Updated: 2019/02/28 18:23:52 by dshereme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	FdF

LIB		:= ./libft/libft.a

GNL		:=	./get_next_line

CC		:=	gcc

FLAGS	:=	-Wall -Werror -Wextra

MLX_CC	:=	-lmlx -framework OpenGL -framework AppKit

SRC		:=	main.c \
   			dda.c \
			coordinate_reader.c \
			figure_creator.c \
			figure_creator.c \
			$(GNL)/get_next_line.c

OBJ		:=	$(SRC:%.c=%.o)

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) $(FLAGS) -o $(NAME) $(SRC) -I . $(LIB) -L ./minilibx $(MLX_CC)


all: $(NAME)

clean:
	@rm -f $(OBJ)
	@rm -f $(GNL)/*.o
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all
