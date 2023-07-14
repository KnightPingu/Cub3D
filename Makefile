# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/09 12:45:03 by dopeyrat          #+#    #+#              #
#    Updated: 2023/07/14 15:36:34 by mprofett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c \
			free.c \
			INIT/args.c \
			INIT/check_map.c \
			INIT/display.c \
			INIT/init.c \
			INIT/map_id.c \
			INIT/remalloc.c \
			image.c \
			keyboard_hooks.c \
			loop.c \
			minimap.c \

OBJS	=	${SRCS:.c=.o}

NAME	= cub3D

LIBFT	= LIBFT/libft.a

MLX		= libmlx.a

MLXFLAGS	= -Lmlx -framework OpenGL -framework Appkit

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -O3 -O2 -Os -O1 #-fsanitize=address -g

all:	${NAME}

$(LIBFT):
	make -C LIBFT/

%.o:	%.c
	${CC} ${CFLAGS} -Imlx -c $< -o $@

${NAME}:	$(LIBFT) ${OBJS}
	make -C mlx
	cp mlx/libmlx.a ./
	${CC} ${CFLAGS} ${MLXFLAGS} -o ${NAME} ${LIBFT} ${OBJS} ${MLX}

clean:
	rm -rf ${OBJS}
	make -C LIBFT/ clean

fclean:	clean
	rm -rf ${NAME}
	rm -rf ${MLX}
	make -C LIBFT/ fclean
	make clean -C mlx

re:	fclean all

.PHONY:	re clean fclean all
