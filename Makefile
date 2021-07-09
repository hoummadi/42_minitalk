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

SRCS_C = ft_client.c

SRCS_S = ft_server.c

OBJ_C = ft_client.o

OBJ_S = ft_server.o

SRCS_C_B = bonus/ft_client_bonus.c

SRCS_S_B = bonus/ft_server_bonus.c

OBJ_C_B = bonus/ft_client_bonus.o

OBJ_S_B = bonus/ft_server_bonus.o

all : $(NAME)

$(NAME): $(SRCS_C) $(SRCS_S)
		@echo ok

bonus : $(SRCS_C_B) $(SRCS_S_B)
		@echo ok_b

clean :
		@rm -f $(OBJ_C) $(OBJ_S) $(OBJ_C_B) $(OBJ_S_B)

fclean : clean
		@rm -rf $(NAME)
		@rm -rf $(NAME2)

re : fclean all

.PHONY: all clean fclean re bonus