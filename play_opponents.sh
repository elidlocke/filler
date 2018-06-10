#!/bin/bash
intra_name=$1

[ $# -eq 0 ] && { echo "Usage: $0 intra_name"; exit 1; }

red='\e[1;31m%s\e[0m'
green='\e[1;32m%s\e[0m'
blue='\e[1;34m%s\e[0m'

compete() {
	./resources/filler_vm -p$2 resources/players/$1.filler -p$3 resources/players/$intra_name.filler -v -f resources/maps/$4 -q > competition_results.txt

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

loop_all_players_all_maps(){
	for i in "map00" "map01" "map02"
	do
		:
		printf "\n\n$blue\n\n" "$i"
		for j in "abanlin" "champely" "hcao" "carli" "grati" "superjeannot"
		do
			:
			run_trials $j $i
		done
	done
}

loop_all_players_all_maps
