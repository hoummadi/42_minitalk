# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/09 19:08:19 by hhoummad          #+#    #+#              #
#    Updated: 2021/07/09 19:08:21 by hhoummad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client

NAME2 = server

HEADER = minitalk.h

FLAG = -Wall -Wextra -Werror -c

SRCS_C = ft_client.c ft_tools.c ft_tools_2.c

SRCS_S = ft_server.c ft_tools.c ft_tools_2.c

OBJ_C = ft_client.o ft_tools.o ft_tools_2.o

OBJ_S = ft_server.o ft_tools.o ft_tools_2.o

SRCS_C_B = bonus/ft_client_bonus.c bonus/ft_tools_bonus.c bonus/ft_tools_2_bonus.c

SRCS_S_B = bonus/ft_server_bonus.c bonus/ft_tools_bonus.c bonus/ft_tools_2_bonus.c

OBJ_C_B = ft_client_bonus.o ft_tools_bonus.o ft_tools_2_bonus.o

OBJ_S_B = ft_server_bonus.o ft_tools_bonus.o ft_tools_2_bonus.o

all : $(NAME)

$(NAME): $(SRCS_C) $(SRCS_S) $(HEADER)
		@gcc $(FLAG) $(SRCS_S)
		@gcc $(OBJ_S) -o $(NAME2)
		@echo "make server"
		@gcc $(FLAG) $(SRCS_C)
		@gcc $(OBJ_C) -o $(NAME)
		@echo "make client"

bonus : $(SRCS_C_B) $(SRCS_S_B) $(HEADER)
		@gcc $(FLAG) $(SRCS_S_B)
		@gcc $(OBJ_S_B) -o $(NAME2)
		@echo "make server"
		@gcc $(FLAG) $(SRCS_C_B)
		@gcc $(OBJ_C_B) -o $(NAME)
		@echo "make client"

clean :
		@rm -f $(OBJ_C) $(OBJ_S) $(OBJ_C_B) $(OBJ_S_B)

fclean : clean
		@rm -rf $(NAME)
		@rm -rf $(NAME2)

re : fclean all

.PHONY: all clean fclean re bonus