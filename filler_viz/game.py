# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    game.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enennige <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/20 16:17:34 by enennige          #+#    #+#              #
#    Updated: 2018/05/22 11:12:06 by enennige         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


class Game:

    def __init__(self, turns=None, num_players=1, po=None, px=None,
                 po_totalscore=0, px_totalscore=0):
        self.turns = turns
        self.num_players = num_players
        self.po = po
        self.px = px
        self.po_totalscore = po_totalscore
        self.px_totalscore = px_totalscore

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
            self.po_totalscore += 1
        elif "X" in line:
            self.px_totalscore += 1
