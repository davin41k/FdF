# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/27 18:49:39 by dshereme          #+#    #+#              #
#    Updated: 2019/03/09 18:25:15 by dshereme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	fdf

LIB		:= ./libft/libft.a

OBJ_DIR	:=	objs

C_OBJ	:=	mkdir $(OBJ_DIR)

GNL		:=	./get_next_line

CC		:=	gcc

FLAGS	:=	-Wall -Werror -Wextra

MLX_CC	:=	-lmlx -framework OpenGL -framework AppKit

SRC		:=	main.c \
			read_figure.c \
			norminate.c \
			initialization.c \
			draw_func.c \
			hotkeys.c \
			rotate_figure.c \
			$(GNL)/get_next_line.c

			### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

OBJ		:= $(SRC:.c=.o)

$(NAME): $(OBJ)
	@echo "$(GREEN)compiling libft$(CYAN)"
	@make -C ./libft
	@echo "$(YELLOW)libft was compilid"
	@echo "$(GREEN)compiling FdF$(CYAN)"
	@$(CC) $(FLAGS) -o $(NAME) $(SRC) -I fdf.h $(LIB) -L ./minilibx $(MLX_CC)
	@ mv -f *.o $(OBJ_DIR) 
	@echo "$(YELLOW)FdF is ready to use"

all: $(NAME)

clean:
	@echo "$(VIOLET)cleaning..."
	@rm -f $(OBJ)
	@echo "$(RED) project's object files were deleted"
	@rm -f $(GNL)/*.o
	@echo "$(RED) get_next_line.o was deleted"
	@make clean -C ./libft
	@echo "$(VIOLET) libft's object files was deleted"

fclean: clean
	@echo "$(VIOLET)fcleaning..."
	@rm -f $(NAME)
	@make fclean -C ./libft
	@echo "$(RED)bin was deleted"

re: fclean all
