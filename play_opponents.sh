# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    play_opponents.sh                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enennige <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/17 15:21:27 by enennige          #+#    #+#              #
#    Updated: 2018/05/18 15:39:29 by enennige         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

red='\e[1;31m%s\e[0m'
green='\e[1;32m%s\e[0m'
blue='\e[1;34m%s\e[0m'

compete() {
	./resources/filler_vm -p$2 resources/players/$1.filler -p$3 resources/players/enennige.filler -v -f resources/maps/$4 -q > competition_results.txt

	me=$(cat 'competition_results.txt' | grep -n '==' | sed -n "$3p" | awk '{print $4}')
	enemy=$(cat 'competition_results.txt' | grep -n '==' | sed -n "$2p" | awk '{print $4}')
	score=$(expr $me - $enemy)
	if [ $score \> 0 ];then
		printf "$green" "win: "
	else
		printf "$red" "lose: "
	fi;
	printf "me:${me}	vs	enemy:${enemy}\n"
}

run_trials(){
	printf "$blue vs $blue\n" $1 "ME"
	for run in {1..3}
	do
		compete $1 1 2 $2
		compete $1 2 1 $2
	done
}


printf "\n\n$blue\n\n" "MAP00"
run_trials abanlin map00
run_trials champely map00
run_trials hcao map00
run_trials carli map00
run_trials grati map00
run_trials superjeannot map00

printf "\n\n$blue\n\n" "MAP01"
run_trials abanlin map01
run_trials champely map01
run_trials hcao map01
run_trials carli map01
run_trials grati map01
run_trials superjeannot map01

printf "\n\n$blue\n\n" "MAP02"
run_trials abanlin map02
run_trials champely map02
run_trials hcao map02
run_trials carli map02
run_trials grati map02
run_trials superjeannot map02
