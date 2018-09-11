# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/04 10:34:41 by mtshisw           #+#    #+#              #
#    Updated: 2018/09/04 13:42:10 by mtshisw          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker

NAME2 = push_swap

LIB = libft

LIBA = libft/libft.a

CFLAGS = -Wall -Wextra -Werror -I $(LIB) -I .

OBJCS = ft_debug.o checker.o init_prt_cmd.o validstack.o swap_func.o push_func.o \
		rot_func.o revrot_func.o valops.o stack_len_end.o

OBJCS2 = ft_debug.o push_swap.o validstack.o init_prt_cmd.o swap_func.o push_func.o rot_func.o \
		 revrot_func.o valops.o ordercheck.o stack_len_end.o execute_op.o \
		 rethelp.o sorting.o stack_b_moves.o dif_move.o \
		 prepoprot.o rethelp2.o

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJCS) $(LIBA)
	echo "\x1B[32m\x1B[1m"
	gcc $(CFLAGS) -o $@ $^

$(NAME2): $(OBJCS2) $(LIBA)
	echo "\x1B[32m\x1B[1m"
	gcc $(CFLAGS) -o $@ $^
	@echo "\x1B[36m			Checker compiled successfully\x1B[3m"
	@echo "\x1B[31m				   and\x1B[3m"
	@echo "\x1B[35m			Push_swap compiled successfully\x1B[0m"

$(LIBA):
	cd $(LIB) && $(MAKE)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJCS)
	rm -f $(OBJCS2)
	cd $(LIB) && make fclean

fclean: clean
	rm -f $(NAME1)
	rm -f $(NAME2)

re: fclean all

.PHONY: clean re fclean
