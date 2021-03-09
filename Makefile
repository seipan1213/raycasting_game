# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/09 13:31:55 by sehattor          #+#    #+#              #
#    Updated: 2021/03/09 14:14:21 by sehattor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS_DIR = srcs
SRCS = ${SRCS_DIR}/cub3d.c ${SRCS_DIR}/cub3d_exit.c ${SRCS_DIR}/cub3d_loadfile.c \
				${SRCS_DIR}/cub3d_map.c ${SRCS_DIR}/cub3d_raycast.c ${SRCS_DIR}/cub3d_readfile.c \
				${SRCS_DIR}/cub3d_sprite.c ${SRCS_DIR}/cub3d_update.c ${SRCS_DIR}/cub3d_utils.c \
				${SRCS_DIR}/cub3d_wall.c ${SRCS_DIR}/cub3d_bmp.c

LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/libft.a

MINILIBX_DIR = minilibx-linux
MINILIBX = ${MINILIBX_DIR}/libmlx.a
LIBS  = ${LIBFT} ${MINILIBX} -lXext -lX11 -lm

INCLUDE = -I./includes -I./${LIBFT_DIR} -I./${MINILIBX_DIR}

OBJS = ${SRCS:.c=.o}
all: ${NAME}
bonus: ${NAME}

${NAME}: ${OBJS} ${LIBFT} ${MINILIBX}
	${CC} ${CFLAGS} ${INCLUDE} ${OBJS} ${LIBS} -o ${NAME}

${LIBFT}: ${LIBFT_DIR}/*.c
	${MAKE} -C ${LIBFT_DIR}

${MINILIBX}:
	${MAKE} -C ${MINILIBX_DIR}

.c.o:
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

clean:
	${RM} ${OBJS}
	${MAKE} -C ${MINILIBX_DIR} clean
	${MAKE} -C ${LIBFT_DIR}	clean

fclean: clean
	${RM} ${NAME}
	${MAKE} -C ${LIBFT_DIR} fclean

re:	fclean all

.PHONY: all clean fclean re bonus
