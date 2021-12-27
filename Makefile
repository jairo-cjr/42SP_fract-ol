# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 14:32:11 by jcaetano          #+#    #+#              #
#    Updated: 2021/12/27 12:08:20 by jcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fractol

SRC				=	./src
SRCS			=	main.c \
					ft_clear_memory.c \
					ft_create_image.c \
					ft_create_window.c \
					ft_encode_rgb.c \
					ft_handle_keypress.c \
					ft_img_pixel_put.c \
					ft_init.c \
					ft_init_complex.c \
					ft_init_mlx.c \
					ft_init_pointers.c \
					ft_mandelbrot.c \
					ft_render.c

OBJ				=	./bin
OBJS			=	$(addprefix $(OBJ)/,$(SRCS:.c=.o))

INC_DIR			=	./includes

SYS_CAL			=	-lmlx -Ilmlx -lXext -lX11

LIBFT_DIR		=	./libft

LIBFT_LIB			=	ft

FT_CAL			=	-L $(LIBFT_DIR) -l $(LIBFT_LIB)

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror -O3 -g

LIBS			=	$(FT_CAL) $(SYS_CAL)

INCS			=	-I $(INC_DIR) -I $(LIBFT_DIR)/$(INC_DIR)

SAN				=	-g3 -fsanitize=address

RM				=	rm -rf

DIR_GUARD		=	mkdir -p $(@D)

$(OBJ)/%.o:	$(SRC)/%.c
				$(DIR_GUARD)
				$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME):		$(OBJS)
				make all -C $(LIBFT_DIR)
				$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(INCS) -o $(NAME)

all:			$(NAME)

bonus:			$(NAME)

fsan:			$(OBJS)
				make all -C $(LIBFT_DIR)
				$(CC) $(SAN) $(CFLAGS) $(OBJS) $(LIBS) $(INCS) -o $(NAME)

clean:
				$(RM) $(OBJ)
				make $@ -C $(LIBFT_DIR)

fclean: 		clean
				$(RM) $(NAME)
				make $@ -C $(LIBFT_DIR)

re:				fclean all

m:
				reset
				./fractol mandelbrot

run:			all
				reset
				./fractol

val:			all
				reset
				valgrind ./fractol --leak-check=full

norm:
				norminette $(SRC) $(LIBFT_DIR) $(INC_DIR)

.PHONY:			all bonus fsan clean fclean re m run
