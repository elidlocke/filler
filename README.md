# Filler: Battle of the Tetris Shapes

Filler is a game, similar to Blockus, where two players take turns placing tetrimino shapes on a board. In this version, a virtual machine organizes the game by giving each player a random piece at the start of each turn. The player who places the most tetrimino shapes wins.

This repository contains two parts:
* My filler player, written in C
* A GUI, written in Python using Tkinter

## Game Strategy

my Filler player has two stages:

1) Seed Stage: Fill towards the opposite corner, to cover an appropriate starting amount of the board.

2) Battle Stage: Balancing offence and defence, my filler places a weighting on growing away from itself and growing towards the enemy, then chooses the location with the most optimal score.

## Getting Started

Clone this repo and make the player using `make`. Then choose from:

Basic Mode:
`sh play_basic.sh [player1] [player2] [map]`

Visual Mode:
`sh play_visual.sh [player1] [player2] [map]`

Battle All:
`sh play_opponents.sh [player1] [player2] [map]`

## UI Usage and Navigation

![Filler Battle: Start](https://raw.githubusercontent.com/elidlocke/filler/master/images/map01-start-battle-filler.png)
![Filler Battle: Middle](https://raw.githubusercontent.com/elidlocke/filler/master/images/map01-mid-battle-filler.png)
![Filler Battle: End](https://raw.githubusercontent.com/elidlocke/filler/master/images/map01-end-battle-filler.png)

The UI can be used to analyze a game and determine effective strategies for beating other players. The UI will load the game at the starting point, and can be navigated using the keystrokes:

* right ->: Move forward a turn 
* left  <-: Move backwards a turn
* x		: Close the window

## Battle Stats

![Map 00](https://github.com/elidlocke/filler/blob/master/images/battle-stats-maps00.png) ![Map 01](https://github.com/elidlocke/filler/blob/master/images/battle-stats-maps01.png) ![Map 02](https://github.com/elidlocke/filler/blob/master/images/battle-stats-maps02.png)

## Built With

* [TKinter](https://wiki.python.org/moin/TkInter) - Python's built in GUI package
