# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    game.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enennige <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/20 16:17:34 by enennige          #+#    #+#              #
#    Updated: 2018/05/22 21:53:03 by enennige         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


class Game:

    def __init__(self, turns=None, num_players=1, po=None, px=None,
                 po_isalive=1, px_isalive=1, po_score=0, px_score=0,
                 current_player='O'):
        self.turns = turns
        self.num_players = num_players
        self.po = po
        self.px = px
        self.po_isalive = po_isalive
        self.px_isalive = px_isalive
        self.po_score = po_score
        self.px_score = px_score
        self.current_player = current_player

    def set_player_name(self, line, player_number):
        line = line.replace('/', ' ')
        line = line.replace('.', ' ')
        words = line.split(' ')
        if player_number == 1:
            self.po = words[-2]
        if player_number == 2:
            self.num_players = 2
            self.px = words[-2]

    def increment_score(self, line):
        if "O" in line:
            self.po_score += 1
        elif "X" in line:
            self.px_score += 1
    
    def set_dead(self, line):
        if "O" in line:
            self.po_isalive = 0
        elif "X" in line:
            self.px_isalive = 0
    
    def set_current_player(self, line):
        if 'O' in line and self.px_isalive == 1:
            self.current_player = "X"
        elif "X" in line and self.po_isalive == 1:
            self.current_player = "O"
