# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    filler_viz.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enennige <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/20 10:16:43 by enennige          #+#    #+#              #
#    Updated: 2018/05/21 13:13:04 by enennige         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from tkinter import Tk, Canvas, Frame, BOTH
from game import Game
from grid import Grid
from turn import Turn
from read_input import read_game
import time

x_color = '#3AC43A'
x_highlight = '#D8D826'
o_color = '#3A3AC4'
o_highlight = '#26D8D8'
background_color = "#1C1C1C"
default_color = '#232323'
game = read_game()

class filler_viz(Frame):

    turn = 0

    def __init__(self, turn=0):
        super().__init__()   
        self.turn = turn
        self.initUI()
    
    def initUI(self):
      
        self.master.title("Filler Viz")        
        self.pack(fill=BOTH, expand=1)
        canvas = Canvas(self, bg=background_color)
        canvas.focus_set()
        canvas.bind("<Left>", lambda event,
                    arg=canvas: self.prev_turn(event, arg))
        canvas.bind("<Right>", lambda event,
                    arg=canvas: self.next_turn(event, arg))
        canvas.pack(fill=BOTH, expand=1)
        current_turn = game.turns[self.turn]
        draw_turn(canvas, game.turns[self.turn])

    def prev_turn(self, event, canvas):
        print ("PREV")
        if self.turn > 0:
            self.turn -=1
        current_turn = game.turns[self.turn]
        draw_turn(canvas, game.turns[self.turn])

    def next_turn(self, event, canvas):
        print ("NEXT")
        if (self.turn < len(game.turns)):
            self.turn += 1
        draw_turn(canvas, game.turns[self.turn])

def draw_turn(canvas, turn):
    x_origin = 30
    y_origin = 30
    size = 15
    border = 5
    offset = size + border
    draw_grid(canvas, turn.board, x_origin, y_origin, size, offset)
    px_origin = (x_origin * 2) + (turn.board.cols * offset)
    draw_grid(canvas, turn.piece, px_origin, y_origin, size, offset)

def draw_grid(canvas, grid, x_origin, y_origin, size, offset):
    xl = x_origin
    yt = y_origin
    xr = xl + size
    yb = yt + size
    offset = size + 5

    for row in grid.data:
        for col in row:
            color = get_cell_color(col)
            canvas.create_rectangle(xl, yt, xr, yb,
                                    outline=color,
                                    fill=color)
            xl += offset
            xr += offset
        xl = x_origin
        xr = x_origin + size
        yt += offset
        yb += offset

def get_cell_color(cell):
    if cell == 'x':
        return (x_highlight)
    elif cell == 'X':
        return (x_color)
    elif cell == 'o':
        return (o_highlight)
    elif cell == 'O':
        return (o_color)
    elif cell == '*':
        return(o_highlight)
    return (default_color)


def main():
  
    root = Tk()
    viz = filler_viz()
    root.geometry("1000x1000+300+300")
    root.mainloop()  


if __name__ == '__main__':
    main()   
