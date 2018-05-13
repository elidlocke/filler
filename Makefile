# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enennige <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/12 11:24:58 by enennige          #+#    #+#              #
#    Updated: 2018/05/12 11:34:11 by enennige         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = enennige.filler
CFLAGS = -Wall -Wextra -Werror
SRC_PATH = srcs/
SRC_NAME = main.c 
SRCS = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJS = $(patsubst %.c, %.o, $(SRC_NAME))
LIB_NAME = libft
LIB_OPT = -L ./libft/ -lft
LIB_HEADER = -I ./libft/includes/
INCLUDES = -I includes/ $(LIB_HEADER)
TC = $(addsuffix .check, $(NAME))
TS = $(filter-out $(SRC_PATH)main.c, $(SRCS))
TS_NAME = check.out
TEST_HEADER = $$HOME/.brew/include/
TEST_LIB = $$HOME/.brew/lib/
TEST = tests/
TEST_CHECK = $(addprefix $(TEST), $(TC))
TEST_SRC = $(addsuffix .c, $(TEST_CHECK))
TEST_OPT = $(INCLUDES) $(LIB_OPT) -I $(TEST_HEADER) -L $(TEST_LIB) -lcheck

all: $(NAME)

$(NAME):
	make -C $(LIB_NAME)/
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCS) 
	$(CC) $(CFLAGS) $(OBJS) $(LIB_OPT) -o $(NAME)

clean:
	make clean -C $(LIB_NAME)/
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIB_NAME)/
	rm -f $(NAME)

build_test: clean_test
	checkmk $(TEST_CHECK) > $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_OPT) $(TEST_SRC) $(TS) -o $(TS_NAME)

run_test: build_test
	./$(TS_NAME)

clean_test:
	rm -f $(TEST_SRC)
	rm -f $(TS_NAME)

re: fclean all

