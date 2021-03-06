# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enennige <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/12 11:24:58 by enennige          #+#    #+#              #
#    Updated: 2018/06/04 14:09:33 by enennige         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = enennige.filler
CFLAGS = -Wall -Wextra -Werror
SRC_PATH = srcs/
SRC_NAME = main.c init_game.c init_turn.c init_heatmaps.c
SRC_NAME += corner_heatmap.c battle_heatmap.c place_piece.c
SRC_NAME += clear_turn.c utils.c
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
	rm -f filler.trace

re: fclean all

