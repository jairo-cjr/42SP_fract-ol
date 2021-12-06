# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcaetano <jcaetanostudent.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/05 13:39:23 by vbrazhni          #+#    #+#              #
#    Updated: 2021/11/19 08:03:45 by jcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
FLAGS = -Wall -Werror -Wextra -fsanitize=address
LFLAGS = -L.. -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd

LIBFT_DIRECTORY = ../libft/
LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/

SRC = main.c
OBJ = $(SRC:%.c=%.o)

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME):
	gcc main.c $(LFLAGS) -o $(NAME)

# $(NAME): $(OBJ)
# 	$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(LFLAGS)

clean:
	@rm -rf *.o
	@echo "$(RED)$(O_DIR)directory was deleted$(RESET)"
	@echo "$(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f *.a
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

r: re
	./fractol

.PHONY: all clean fclean re r
