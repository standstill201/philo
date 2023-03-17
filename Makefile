# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 16:43:52 by seokjyoo          #+#    #+#              #
#    Updated: 2023/03/17 20:36:54 by seokjyoo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS =# -Wall -Wextra -Werror

RM = rm -rf

SRC =	./main.c \
		./parse/check_arg.c \
		./ft_tools/ft_atoi.c \
		./philo_action/philo_action.c \
		./setting/set_common_philo.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re :	fclean
		$(MAKE) all

.PHONY: all clean fclean re
