#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otiniako <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/02 22:00:54 by otiniako          #+#    #+#              #
#    Updated: 2018/06/02 22:00:55 by otiniako         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = push_swap
NAME2 = checker

HEADER = pushswap.h

FLAGS = -Wall -Wextra -Werror -I includes/

SRC = push_swap.c\
		push.c\
		swap.c\
		rotate.c\
		rev_rotate.c\
		ft_sort.c\
		tools.c\
		ft_sort_hard.c\
		qsort_a.c\
		qsort_b.c\

CHK = check.c\
		tools.c\
		get_next_line.c\
		push.c\
		rev_rotate.c\
		rotate.c\
		swap.c\

LIB = libft/libft.a

RM = rm -f

PUSHSRCS = $(addprefix src/, $(SRC))
CHECKSRCS = $(addprefix chk/, $(CHK))

OBJ = $(PUSHSRCS:.c=.o)
CHKOBJ = $(CHECKSRCS:.c=.o)

all: $(LIB) $(NAME) $(NAME2)

$(LIB):
	@make -C libft/

$(OBJ): %.o: %.c
	@gcc -c $(FLAGS) $< -o $@

$(CHKOBJ): %.o: %.c
	@gcc -c $(FLAGS) $< -o $@

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(LIB)

$(NAME2): $(CHKOBJ)
	@gcc -o $(NAME2) $(CHKOBJ) $(LIB)
	@echo "\033[1;92mpush_swap and checker are created!\033[1;92m"

clean: 
	@make -C libft/ clean
	@rm -f $(OBJ) $(CHKOBJ)

fclean: clean
	@rm -rf $(NAME) $(NAME2)
	@make -C libft/ fclean

re: fclean all
