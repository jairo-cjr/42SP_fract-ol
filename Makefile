# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 14:32:11 by jcaetano          #+#    #+#              #
#    Updated: 2021/12/22 06:43:24 by jcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fractol

SRC				=	./src
SRCS			=	main.c \
					ft_create_image.c \
					ft_create_window.c \
					ft_encode_rgb.c \
					ft_handle_keypress.c \
					ft_img_pixel_put.c \
					ft_init_mlx.c \
					ft_render_background.c \
					ft_render_rectangle.c \
					ft_render.c

OBJ				=	./bin
OBJS			=	$(addprefix $(OBJ)/,$(SRCS:.c=.o))

INC_DIR			=	./includes

SYS_CAL			=	-l Xext -l X11 -l m -l bsd

MLX_DIR			=	./mlx_linux

MLX_LIB			=	mlx

MLX_CAL			=	-L $(MLX_DIR) -l $(MLX_LIB)

LIBFT_DIR		=	./libft

LIBFT_LIB			=	ft

FT_CAL			=	-L $(LIBFT_DIR) -l $(LIBFT_LIB)

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror -O3 -g

LIBS			=	$(MLX_CAL) $(FT_CAL) $(SYS_CAL)

INCS			=	-I $(MLX_DIR) -I $(INC_DIR) -I $(LIBFT_DIR)/$(INC_DIR)

SAN				=	-g3 -fsanitize=address

RM				=	rm -rf

DIR_GUARD		=	mkdir -p $(@D)

$(OBJ)/%.o:	$(SRC)/%.c
				$(DIR_GUARD)
				$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME):		$(OBJS)
				make all -C $(LIBFT_DIR)
				make all -C $(MLX_DIR)
				$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(INCS) -o $(NAME)

all:			$(NAME)

bonus:			$(NAME)

fsan:			$(OBJS)
				make all -C $(LIBFT_DIR)
				make all -C $(MLX_DIR)
				$(CC) $(SAN) $(CFLAGS) $(OBJS) $(LIBS) $(INCS) -o $(NAME)

clean:
				$(RM) $(OBJ)
				make $@ -C $(MLX_DIR)
				make $@ -C $(LIBFT_DIR)

fclean: 		clean
				$(RM) $(NAME)
				make $@ -C $(LIBFT_DIR)

re:				fclean all

man:			all
				./fractol mandelbrot

run:			all
				reset
				./fractol

norm:
	norminette $(SRC) $(LIBFT_DIR) $(INC_DIR)

.PHONY:			all bonus fsan clean fclean re man run
