# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enennige <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/12 11:24:58 by enennige          #+#    #+#              #
#    Updated: 2018/05/16 11:41:00 by enennige         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = enennige.filler
CFLAGS = -Wall -Wextra -Werror
SRC_PATH = srcs/
SRC_NAME = main.c init_game.c init_turn.c create_num_heatmaps.c
SRCS = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJS = $(patsubst %.c, %.o, $(SRC_NAME))
LIB_NAME = libft
LIB_OPT = -L ./libft/ -lft
LIB_HEADER = -I ./libft/includes/
INCLUDES = -I includes/ $(LIB_HEADER)

all: $(NAME)

$(NAME):
	make -C $(LIB_NAME)/
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCS) 
	$(CC) $(CFLAGS) $(OBJS) $(LIB_OPT) -o $(NAME)
	cp $(NAME) resources/players/. 

player:
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCS) -g
	$(CC) $(CFLAGS) $(OBJS) $(LIB_OPT) -o $(NAME)
	cp $(NAME) resources/players/. 

clean:
	make clean -C $(LIB_NAME)/
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIB_NAME)/
	rm -f $(NAME)

re: fclean all

