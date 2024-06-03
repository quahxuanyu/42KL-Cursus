# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 11:32:43 by rteoh             #+#    #+#              #
#    Updated: 2024/05/27 16:23:42 by rteoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
NAME_BNS	= checker
CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror
INCLUDE		= -I ./includes

OBJ_DIR		= obj/
SRC_DIR		= src/push_swap

OBJ_BNS_DIR = obj_bns/
SRC_BNS_DIR	= src/checker

SRC			= cost.c\
				sort.c\
				do_move.c\
				sort_position.c\
				input_check.c\
				stack_utils.c\
				input_check_utils.c\
				stack_values_initialization.c\
				main.c\
				swap.c\
				push.c\
				tiny_sort.c\
				reverse_rotate.c\
				utils.c\
				rotate.c\

SRC_BNS		= checker.c \
				rotate.c \
				input_check.c \
				stack_utils.c \
				input_check_utils.c \
				stack_values_initialization.c \
				push.c \
				swap.c \
				reverse_rotate.c \
				utils.c \

SRCS		= $(addprefix ${SRC_DIR}, ${SRC})
OBJ 		= ${SRC:.c=.o}
OBJS		= ${addprefix ${OBJ_DIR}, ${OBJ}}

SRCS_BNS	= $(addprefix ${SRC_BNS_DIR}, ${SRC_BNS})
OBJ_BNS		= ${SRC_BNS:.c=.o}
OBJS_BNS	= ${addprefix ${OBJ_BNS_DIR}, ${OBJ_BNS}}


all: ${OBJ_DIR} ${NAME}

${OBJ_DIR}%.o: ${SRC_DIR}/%.c
	${CC} ${CFLAGS} -c $< -o $@ ${INCLUDE}

${OBJ_DIR}:
	mkdir -p ${OBJ_DIR}

${NAME}: ${OBJS}
	${MAKE} -C ./libft
	${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

bonus: all ${OBJ_BNS_DIR} ${NAME_BNS}

${OBJ_BNS_DIR}%.o: ${SRC_BNS_DIR}/%.c
	${CC} ${CFLAGS} -c $< -o $@ ${INCLUDE}

${OBJ_BNS_DIR}:
	mkdir -p ${OBJ_BNS_DIR}

${NAME_BNS}: ${OBJS_BNS}
	${CC} ${CFLAGS} ${OBJS_BNS} ./libft/libft.a -o ${NAME_BNS}

clean:
		@${MAKE} -C ./libft fclean
		@${RM} ${OBJ_DIR}
		@${RM} ${OBJ_BNS_DIR}

fclean: clean
		@rm -f ${NAME}
		@rm -f ${NAME_BNS}

re:	fclean bonus

test1:		${NAME}
					${eval ARG = ${shell shuf -i 0-100 -n 2}}
					./push_swap ${ARG} | ./checker_Mac ${ARG}
					@echo -n "Instructions: "
					@./push_swap ${ARG} | wc -l