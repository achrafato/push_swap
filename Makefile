# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 17:17:30 by aibn-che          #+#    #+#              #
#    Updated: 2024/01/31 15:24:02 by aibn-che         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


MSRCS = ./instructions_1.c ./instructions_2.c ./instructions_3.c ./push_swap.c	./quick_sort_chuncks.c	./sort_three.c	./utils_1.c	./utils_2.c	./utils_3.c ./utils_4.c ./utils_5.c ./utils_6.c ./utils_7.c ./utils_8.c ./utils_9.c

BSRCS = ./checker_bonus/checker.c ./checker_bonus/get_next_line.c ./checker_bonus/get_next_line_utils.c ./instructions_1.c ./instructions_2.c ./instructions_3.c ./sort_three.c ./utils_1.c ./utils_2.c ./utils_3.c ./utils_4.c ./utils_5.c ./utils_6.c ./utils_7.c ./utils_8.c ./utils_9.c

NAME = push_swap
CHECKER = checker

HEADER = ./push_swap.h

HEADER_B = ./checker_bonus/checker.h ./checker_bonus/get_next_line.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(MSRCS) $(HEADER)
	$(CC) $(CFLAGS) $(MSRCS) -o $@

bonus: $(CHECKER)

$(CHECKER): $(BSRCS) $(HEADER) $(HEADER_B)
	$(CC) $(CFLAGS) $(BSRCS) -o $@

clean:
	@rm -f $(NAME) $(CHECKER)

fclean: clean

re: fclean all
