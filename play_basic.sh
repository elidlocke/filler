# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    play_visual.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enennige <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/21 17:18:55 by enennige          #+#    #+#              #
#    Updated: 2018/05/22 14:13:36 by enennige         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash
player_one=$1
player_two=$2
map=$3
[ $# -eq 0 ] && { echo "Usage: $0 player_one player_two map"; exit 1; }

./resources/filler_vm -p1 resources/players/$player_one.filler -p2 resources/players/$player_two.filler -v -f resources/maps/$map
