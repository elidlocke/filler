# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    read_input.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enennige <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/20 11:20:31 by enennige          #+#    #+#              #
#    Updated: 2018/05/21 11:36:24 by enennige         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import fileinput
import sys
from termcolor import colored, cprint
import re
from game import Game
from grid import Grid
from turn import Turn

def read_game():
    game = Game()
    game.turns = []
    board = Grid()
    piece = Grid()
    stdin = fileinput.input()
    for line in stdin:
        #cprint (line, 'green')
        if "p1" in line:
            game.set_player_name(line, 1)
        elif "p2" in line:
            game.set_player_name(line, 2)
        #start of board
        if "Plateau" in line:
            board.get_dims(line)
        elif line[0].isdigit():
            board.append_grid_line(line)
        elif "Piece" in line:
            piece.get_dims(line)
        elif line[0] == '.' or line[0] == '*':
            piece.append_grid_line(line)
        elif "got" in line:
            game.increment_score(line)
            turn = Turn(board, piece, game.po_totalscore, game.px_totalscore)
            game.turns.append(turn)
            board = Grid()
            piece = Grid()
        elif "error" in line:
            turn = Turn(board, piece, game.po_totalscore,
                        game.px_totalscore, False)
            game.turns.append(turn)
            piece = Grid()

    game.set_last_turn_score()
    return (game)

def print_game(game):
    cprint ("PLAYER 1: " + game.po, "green")
    if game.num_players == 2: 
        cprint ("PLAYER 2: " + game.px, "green")
    for turn in game.turns:
        cprint ("GAME rows: " + str(turn.board.rows) + \
                " cols: " + str(turn.board.cols), "red")
        for line in turn.board.data:
            cprint (line, "red")
        cprint ("PIECE rows: " + str(turn.piece.rows) + \
                " cols: " + str(turn.piece.cols), "blue")
        for line in turn.piece.data:
            cprint (line, "blue")
        cprint ("O Score: " + str(turn.po_score), "green")
        if game.num_players == 2:
            cprint ("X Score: " + str(turn.px_score), "green")

if __name__ == "__main__":
    game = read_game()
    print_game(game)
