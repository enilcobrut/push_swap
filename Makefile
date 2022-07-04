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

SRC 	= 	lst.c \
			main.c \
			op1.c \
			op2.c \
			op3.c \
			push_swap_utils.c \
			set_top.c \
			sort.c \
			ft_printf.c \
			save_rotations.c \
			save_rotations1.c \
			ft_split.c \
			parcing.c \
			little_algo.c \

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
