# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 15:40:16 by cjunker           #+#    #+#              #
#    Updated: 2022/07/04 20:21:21 by cjunker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 	= 	src/operation/op1.c \
			src/operation/op2.c \
			src/operation/op3.c \
			src/utils/ft_printf.c \
			src/utils/ft_split.c \
			src/utils/push_swap_utils.c \
			src/utils_algo/save_rotations.c \
			src/utils_algo/save_rotations1.c \
			src/utils_algo/set_top.c \
			src/little_algo.c \
			src/main.c \
		 	src/lst.c \
			src/sort.c \
			src/parcing.c \

OBJS 	=	${SRC:.c=.o}

NAME	=	push_swap

CC		=	gcc

CFLAGS 	=	-Wall -Wextra -Werror

RM	 	=	rm -f

all:		${NAME}

%.o:		%.c
			${CC} ${CFLAGS} -o $@ -c $<


$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $@ $^

install:
			git clone https://github.com/lmalki-h/push_swap_tester.git
	
visu:		
			python3 pyviz.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`

tester5:
			bash push_swap_tester/tester.sh ../push_swap 5 100

tester500:
			bash push_swap_tester/tester.sh ../push_swap 500 100

tester100:
			bash push_swap_tester/tester.sh ../push_swap 100 100

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}
                                                                   
re:			fclean $(NAME)

.PHONY:		all clean fclean
