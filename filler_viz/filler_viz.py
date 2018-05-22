# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    filler_viz.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enennige <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/20 10:16:43 by enennige          #+#    #+#              #
#    Updated: 2018/05/22 09:40:51 by enennige         ###   ########.fr        #
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
game = read_game()

class filler_viz(Frame):

    def __init__(self, turncount=0):
        super().__init__()   
        self.turncount = turncount
        self.initUI()
    
    def initUI(self):
      
        self.master.title("Filler Viz")        
        self.pack(fill=BOTH, expand=1)
        canvas = Canvas(self, bg=background_color)
        canvas.focus_set()
        current_turn = game.turns[self.turncount]
        draw_turn(canvas, game.turns[self.turncount])
        canvas.bind("<Left>", lambda event,
                    arg=canvas: self.prev_turn(event, arg))
        canvas.bind("<Right>", lambda event,
                    arg=canvas: self.next_turn(event, arg))
        canvas.pack(fill=BOTH, expand=1)

    def prev_turn(self, event, canvas):
        if self.turncount > 0:
            self.turncount -=1
        current_turn = game.turns[self.turncount]
        draw_turn(canvas, game.turns[self.turncount])

    def next_turn(self, event, canvas):
        if (self.turncount < len(game.turns) - 1):
            self.turncount += 1
        draw_turn(canvas, game.turns[self.turncount])

def write_text(canvas, turn, x_origin, y_origin, offset):
    canvas.create_text(x_origin, y_origin - 50, fill=title_color, anchor="nw",
                       font=("Courier", 20), text="Filler")
    textx_origin = (x_origin) + (turn.board.cols * offset)
    canvas.create_text(textx_origin - 100, y_origin - 25, fill=o_color,
                       anchor="ne", font=("Courier", 15), text=game.po)
    canvas.create_text(textx_origin, y_origin - 25, fill=x_color, anchor="ne",
                       font=("Courier", 15), text=game.px)
    if turn.po_score == game.po_totalscore and \
       game.po_totalscore > game.px_totalscore:
        canvas.create_text(textx_origin - 100, y_origin - 50, fill=o_color,
                           anchor="ne", font=("Courier", 20),
                           text="WIN:" + str(turn.po_score))
    else:
        canvas.create_text(textx_origin - 100, y_origin - 50, fill=o_color,
                           anchor="ne", font=("Courier", 20), text=turn.po_score)

    if turn.px_score == game.px_totalscore and \
       game.px_totalscore > game.po_totalscore:
        canvas.create_text(textx_origin, y_origin - 50, fill=x_color,
                           anchor="ne", font=("Courier", 20),
                           text="WIN:" + str(turn.px_score))
    else:
        canvas.create_text(textx_origin, y_origin - 50, fill=x_color,
                           anchor="ne", font=("Courier", 20),
                           text=turn.px_score)

def draw_turn(canvas, turn):
    x_origin = 30
    y_origin = 80
    size = 15
    border = 5
    offset = size + border
    canvas.delete("all")
    write_text(canvas, turn, x_origin, y_origin, offset)
    draw_grid(canvas, turn, turn.board, x_origin, y_origin, size, offset)
    px_origin = (x_origin * 2) + (turn.board.cols * offset)
    draw_grid(canvas, turn, turn.piece, px_origin, y_origin, size, offset)

def draw_grid(canvas, turn, grid, x_origin, y_origin, size, offset):
    xl = x_origin
    yt = y_origin
    xr = xl + size
    yb = yt + size
    offset = size + 5

    for row in grid.data:
        for col in row:
            color = get_cell_color(col, turn.current_player)
            canvas.create_rectangle(xl, yt, xr, yb,
                                    outline=color,
                                    fill=color)
            xl += offset
            xr += offset
        xl = x_origin
        xr = x_origin + size
        yt += offset
        yb += offset

def get_cell_color(cell, current_player):
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


def main():
 
    print("LOADING ...\n")
    root = Tk()
    viz = filler_viz()
    x_tk = game.turns[0].board.cols * 20 + (300)
    y_tk = game.turns[0].board.rows * 20 + (130)
    root.geometry("{0}x{1}+300+300".format(x_tk, y_tk))
    print ("Navigation:\n
            <-left arrow key: last move\n
            ->right arrow key: next move\n")
    root.mainloop()  


if __name__ == '__main__':
    main()   
