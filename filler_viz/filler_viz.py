# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    filler_viz.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enennige <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/20 10:16:43 by enennige          #+#    #+#              #
#    Updated: 2018/05/21 18:05:08 by enennige         ###   ########.fr        #
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
    canvas.create_text(x_origin, y_origin - 50, fill="white", anchor="nw",
                       font=("Courier", 20),
                        text="Filler")
    textx_origin = (x_origin) + (turn.board.cols * offset)
    canvas.create_text(textx_origin - 100, 50, fill=o_color, anchor="ne", font=("Courier", 15),
                        text=game.po)
    canvas.create_text(textx_origin, 50, fill=x_color, anchor="ne", font=("Courier", 15),
                        text=game.px)
def draw_turn(canvas, turn):
    x_origin = 30
    y_origin = 80
    size = 15
    border = 5
    offset = size + border
    canvas.delete("all") #want to have some things that we keep ?
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
  
    root = Tk()
    viz = filler_viz()
    root.geometry("1000x1000+300+300")
    root.mainloop()  


if __name__ == '__main__':
    main()   
