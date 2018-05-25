# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    read_input.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enennige <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/20 11:20:31 by enennige          #+#    #+#              #
#    Updated: 2018/05/23 16:32:31 by enennige         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import fileinput
from termcolor import cprint
from game import Game
from grid import Grid

def get_nextline(stdin):
    for line in stdin:
        return (line)

def get_nextline_containing(stdin, search_string):
    for line in stdin:
        if search_string in line:
            return (line)
    return None

def get_ngridlines(stdin, num):
    i = 0
    arr = []
    while (i < num):
        line = get_nextline(stdin)
        if line[0] == ' ':
            i -= 1
        if line[0].isdigit():
            arr.append(line.split(' ')[1].rstrip())
        elif line[0] == '.' or line[0] == '*':
            arr.append(line.rstrip())
        i += 1
    return (arr)

def get_turn(game, line, stdin):
    if "error" in line or "[0, 0]" in line:
        game.set_dead(line)
    elif "got" in line:
        game.increment_score(line)
    if "error" in line or "got" in line:
        game.set_current_player(line)
    line = get_nextline_containing(stdin, "Plateau")
    if (line):
        board = Grid(line)
        board.set_data(get_ngridlines(stdin, board.rows))
        piece = Grid(get_nextline_containing(stdin, "Piece"))
        piece.set_data(get_ngridlines(stdin, piece.rows))
        turn = dict(board=board,
                    piece=piece,
                    po_score=game.po_score,
                    px_score=game.px_score,
                    current_player=game.current_player)
        return (turn)

def read_game():
    game = Game()
    stdin = fileinput.input()
    game.set_player_name(get_nextline_containing(stdin, "p1"), 1)
    game.set_player_name(get_nextline_containing(stdin, "p2"), 2)
    game.turns = []
    line = "start game"
    while (line != None):
        turn = get_turn(game, line, stdin)
        if turn:
            game.turns.append(turn)
        line = get_nextline(stdin)
    return (game)

def print_game(game):
    cprint("PLAYER 1: " + game.po, "green")
    if game.num_players == 2:
        cprint("PLAYER 2: " + game.px, "green")
    for turn in game.turns:
        print("\n\n")
        cprint("Current Player: " + str(turn['current_player']), "cyan")
        cprint("GAME rows: " + str(turn['board'].rows) +
               " cols: " + str(turn['board'].cols), "red")
        for line in turn['board'].data:
            cprint(line, "red")
        cprint("PIECE rows: " + str(turn['piece'].rows) +
               " cols: " + str(turn['piece'].cols), "blue")
        for line in turn['piece'].data:
            cprint(line, "blue")
        cprint("O Score: " + str(turn['po_score']), "green")
        if game.num_players == 2:
            cprint("X Score: " + str(turn['px_score']), "green")

if __name__ == "__main__":
    game = read_game()
    #print_game(game)
