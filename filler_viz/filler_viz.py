# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    filler_viz.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enennige <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/20 10:16:43 by enennige          #+#    #+#              #
#    Updated: 2018/05/20 11:13:50 by enennige         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from tkinter import Tk, Canvas, Frame, BOTH

self_color = '#3AC43A'
enemy_color = '#3A3AC4'
background_color = "#1C1C1C"
default_color = '#232323'

class filler_viz(Frame):
  
    def __init__(self):
        super().__init__()   
        self.initUI()
        
    def initUI(self):
      
        self.master.title("Colours")        
        self.pack(fill=BOTH, expand=1)
        canvas = Canvas(self, bg=background_color)
        draw_board(canvas, 16, 16);
        '''
        canvas.create_rectangle(30, 10, 120, 80, 
            outline="#fb0", fill="#fb0")
        canvas.create_rectangle(150, 10, 240, 80, 
            outline="#f50", fill="#f50")
        canvas.create_rectangle(270, 10, 370, 80, 
            outline="#05f", fill="#05f")            
        '''
        canvas.pack(fill=BOTH, expand=1)


#read input from the terminal



#get board dimensions and draw board

def draw_board(canvas, width, height):
    
    x_origin = 30
    x_start = 30
    y_start = 30
    size = 15
    x_end = x_start + size
    y_end = y_start + size
    offset = size + 5
 
    row = 0
    while (row < width):
        col = 0
        while (col < width):
            canvas.create_rectangle(x_start, y_start, x_end, y_end, outline=default_color, fill=default_color)
            x_start += offset
            x_end += offset
            col += 1
        x_start = x_origin
        x_end = x_origin + size
        y_start += offset
        y_end += offset
        row += 1

#get piece dimensions and draw piece
#get score and draw score

def main():
  
    root = Tk()
    viz = filler_viz()
    root.geometry("1000x1000+300+300")
    root.mainloop()  


if __name__ == '__main__':
    main()   
