# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prippa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/25 14:07:09 by prippa            #+#    #+#              #
#    Updated: 2017/11/25 14:07:13 by prippa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	get_next_line
LFT_PATH	=	./libft/

all: $(NAME)

$(NAME):
	@make -C $(LFT_PATH)
	@clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	@clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	@clang -o $(NAME) main.o get_next_line.o -I libft/includes -L libft/ -lft
	@echo "Compiling" [ $(NAME) ]

clean:
	@rm -f *.o
	@echo "Cleaning .o files"

fclean: clean
	@rm -f $(NAME)
	@echo "Remove" [ $(NAME) ]

re: fclean all

.PHONY: all clean fclean re
