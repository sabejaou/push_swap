# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 20:10:07 by sbejaoui          #+#    #+#              #
#    Updated: 2024/03/12 17:04:55 by sabejaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =  main.c 				\
		args.c				\
		sorting.c			\
		sorting_five.c		\
		sorting_four.c		\
		sorting_three.c		\
		stack_instruction.c	\
		circlist_utils.c	\
		debug.c

OBJS = ${SRCS:.c=.o}

CC = gcc
RM = rm -f

all: ${NAME}

%.o: %.c incl/pipex.h
	$(CC) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(VERIF) $(OBJS) -o $(NAME)

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all
         
.PHONY: all clean fclean re