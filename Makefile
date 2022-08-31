# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arudy <arudy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 11:24:40 by arudy             #+#    #+#              #
#    Updated: 2022/08/31 16:52:50 by arudy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_containers

SRCS	= main.cpp

OBJS	= $(SRCS:.cpp=.o)
DEPS	= $(SRCS:.cpp=.d)

CC		= c++

RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra -pedantic -MMD -MP -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
		${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS} ${DEPS}

fclean: clean
	${RM} ${NAME}

re: fclean all

rc: re
	${RM} ${OBJS} && clear

-include $(DEPS)

.PHONY: all clean fclean re rc
