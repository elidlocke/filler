# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    filler_viz.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enennige <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/20 10:16:43 by enennige          #+#    #+#              #
#    Updated: 2018/05/22 11:25:28 by enennige         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from tkinter import Tk, Canvas, Frame, BOTH, PhotoImage
from game import Game
from grid import Grid
from turn import Turn
from read_input import read_game
import time

x_color = '#3AC43A'
x_highlight = '#9DE29D'
o_color = '#3A3AC4'
o_highlight = '#9D9DE2'
background_color = "#1C1C1C"
title_color = "#C0C0C0"
default_color = '#232323'


class filler_viz(Frame):

    def __init__(self, game, turncount=0):
        super().__init__()
        self.game = game
        self.turncount = turncount
        self.initUI()

    def initUI(self):

        self.master.title("Filler Viz")
        self.pack(fill=BOTH, expand=1)
        self.canvas = Canvas(self, bg=background_color)
        self.canvas.focus_set()
        current_turn = self.game.turns[self.turncount]
        self.draw_turn(self.game.turns[self.turncount])
        self.canvas.bind("<Left>", self.prev_turn)
        self.canvas.bind("<Right>", self.next_turn)
        self.canvas.pack(fill=BOTH, expand=1)

    def prev_turn(self, event):
        if self.turncount > 0:
            self.turncount -= 1
        current_turn = self.game.turns[self.turncount]
        self.draw_turn(self.game.turns[self.turncount])

    def next_turn(self, event):
        if (self.turncount < len(self.game.turns) - 1):
            self.turncount += 1
        self.draw_turn(self.game.turns[self.turncount])

    def draw_turn(self, turn):
        x_origin = 30
        y_origin = 80
        size = 15
        border = 5
        offset = size + border
        self.canvas.delete("all")
        self.write_text(turn, x_origin, y_origin, offset)
        self.draw_grid(turn, turn.board, x_origin, y_origin, size, offset)
        px_origin = (x_origin * 2) + (turn.board.cols * offset)
        self.draw_grid(turn, turn.piece, px_origin, y_origin, size, offset)

    def draw_grid(self, turn, grid, x_origin, y_origin, size, offset):
        xl = x_origin
        yt = y_origin
        xr = xl + size
        yb = yt + size
        offset = size + 5

        for row in grid.data:
            for col in row:
                color = self.get_cell_color(col, turn.current_player)
                self.canvas.create_rectangle(xl, yt, xr, yb,
                                             outline=color,
                                             fill=color)
                xl += offset
                xr += offset
            xl = x_origin
            xr = x_origin + size
            yt += offset
            yb += offset

    def get_cell_color(self, cell, current_player):
        if cell == 'x':
            return (x_highlight)
        elif cell == 'X':
            return (x_color)
        elif cell == 'o':
            return (o_highlight)
        elif cell == 'O':
            return (o_color)
        elif cell == '*' and current_player == 'O':
            return(o_color)
        elif cell == '*' and current_player == 'X':
            return(x_color)
        return (default_color)

    def write_text(self, turn, x_origin, y_origin, offset):
        textx_origin = (x_origin) + (turn.board.cols * offset)
        self.canvas.create_text(x_origin,
                                y_origin - 50,
                                fill=title_color,
                                anchor="nw",
                                font=("Courier", 20),
                                text="Filler")
        self.canvas.create_text(textx_origin - 100,
                                y_origin - 25,
                                fill=o_color,
                                anchor="ne",
                                font=("Courier", 15),
                                text=self.game.po)
        self.canvas.create_text(textx_origin,
                                y_origin - 25,
                                fill=x_color,
                                anchor="ne",
                                font=("Courier", 15),
                                text=self.game.px)
        if turn.po_score == self.game.po_totalscore and \
           self.game.po_totalscore > self.game.px_totalscore:
            self.canvas.create_text(textx_origin - 100,
                                    y_origin - 50,
                                    fill=o_color,
                                    anchor="ne",
                                    font=("Courier", 20),
                                    text="WIN:" + str(turn.po_score))
        else:
            self.canvas.create_text(textx_origin - 100,
                                    y_origin - 50,
                                    fill=o_color,
                                    anchor="ne",
                                    font=("Courier", 20),
                                    text=turn.po_score)

        if turn.px_score == self.game.px_totalscore and \
           self.game.px_totalscore > self.game.po_totalscore:
            self.canvas.create_text(textx_origin,
                                    y_origin - 50,
                                    fill=x_color,
                                    anchor="ne",
                                    font=("Courier", 20),
                                    text="WIN:" + str(turn.px_score))
        else:
            self.canvas.create_text(textx_origin,
                                    y_origin - 50,
                                    fill=x_color,
                                    anchor="ne",
                                    font=("Courier", 20),
                                    text=turn.px_score)

def main():

    print("LOADING ...\n")
    try:
        root = Tk()
        game = read_game()
        viz = filler_viz(game)  # pass game in here and init on line above
        x_tk = game.turns[0].board.cols * 25 + (300)
        y_tk = game.turns[0].board.rows * 20 + (130)
        root.geometry("{0}x{1}+300+300".format(x_tk, y_tk))
        root.mainloop()
    except:
        print ("Oops, did you spell the input correctly?")

if __name__ == '__main__':
    main()
