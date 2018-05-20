# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    read_input.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enennige <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/20 11:20:31 by enennige          #+#    #+#              #
#    Updated: 2018/05/20 13:02:09 by enennige         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import fileinput
import sys
from termcolor import colored, cprint
import re

#init board object
class Board:

    def __init__(self):
        self.rows = None
        self.cols = None
        self.data = []


#init piece object
class Piece:

    def __init__(self):
        self.rows = None
        self.cols = None
        self.data = []


#init piece object
class Game:

    def __init__(self, board, piece):
        self.board = board
        self.piece = piece

def get_dims(line, game_object):
    line = line.replace(':', ' ')
    words = line.split(' ')
    #print ("row: " + words[1] + " col: " + words[2])
    game_object.rows = int(words[1])
    game_object.cols = int(words[2])

def append_board_line(line, board):
    board.data.append(line.split(' ')[1].rstrip())

def set_game_info():
    board = Board()
    piece = Piece()
    for line in fileinput.input():
        #cprint (line, 'green')
        if "Plateau" in line:
            get_dims(line, board)
        elif line[0].isdigit():
            append_board_line(line, board)
        elif "Piece" in line:
            get_dims(line, piece)
        elif line[0] == '.' or line[0] == '*':
            piece.data.append(line.rstrip())
    cprint (board.rows, 'red')
    cprint (board.cols, 'red')
    cprint (board.data, 'green')
    cprint (piece.rows, 'red')
    cprint (piece.cols, 'red')
    cprint (piece.data, 'green')

#get board rows
#get board cols
#get board data

#get board rows
#get board cols
#get board data

#init game object
#put in board
#put in piece

#make an array of game states
#pass to viz to move forward and back through

if __name__ == "__main__":
    set_game_info()
