# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    grid.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enennige <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/20 16:30:45 by enennige          #+#    #+#              #
#    Updated: 2018/05/22 17:53:44 by enennige         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class Grid:

    def __init__(self, line, rows=None, cols=None, data=None):
        self.rows = rows
        self.cols = cols
        self.data = data
        self.set_dims(line)
    
    def set_data(self, data):
        self.data = data

    def set_dims(self, line):
        line = line.replace(':', ' ')
        words = line.split(' ')
        self.rows = int(words[1])
        self.cols = int(words[2])
