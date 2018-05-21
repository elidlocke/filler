# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    turn.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enennige <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/20 16:25:17 by enennige          #+#    #+#              #
#    Updated: 2018/05/20 18:30:11 by enennige         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class Turn:

    def __init__(self, board=None, piece=None, po_score=0, px_score=0,
                 is_valid=True):
        self.board = board
        self.piece = piece
        self.po_score = po_score
        self.px_score = px_score
        self.is_valid = is_valid

    def set_score(self, po_score, px_score):
        self.po_score = po_score
        self.px_score = px_score

