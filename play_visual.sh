#!/bin/bash
player_one=$1
player_two=$2
map=$3
[ $# -eq 0 ] && { echo "Usage: $0 player_one player_two map"; exit 1; }

./resources/filler_vm -p1 resources/players/$player_one.filler -p2 resources/players/$player_two.filler -v -f resources/maps/$map | python3 filler_viz/filler_viz.py
