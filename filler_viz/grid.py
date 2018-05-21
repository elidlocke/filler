# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    grid.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enennige <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/20 16:30:45 by enennige          #+#    #+#              #
#    Updated: 2018/05/20 17:10:53 by enennige         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class Grid:

    def __init__(self, rows=None, cols=None, data=None):
        self.rows = rows
        self.cols = cols
        self.data = data

    def append_grid_line(self, line):
        if self.data is None:
            self.data = []
        if line[0].isdigit():
            self.data.append(line.split(' ')[1].rstrip())
        else:
            self.data.append(line.rstrip())

    def get_dims(self, line):
        line = line.replace(':', ' ')
        words = line.split(' ')
        self.rows = int(words[1])
        self.cols = int(words[2])
