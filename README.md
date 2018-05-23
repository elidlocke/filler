# Filler: Battle of the Tetris Shapes

Filler is a game, similar to Blockus, where two players take turns placing tetrimino shapes on a board. In this version, a virtual machine organizes the game by giving each player a random piece at the start of each turn. The player who places the most tetrimino shapes wins.

This repository contains two parts:
* My filler player, written in C
* A GUI, written in Python using Tkinter

## Game Strategy

my Filler player has two stages:

1) Seed Stage: Fill towards the opposite corner, to cover an appropriate starting amount of the board.

[Insert Seed Image]

2) Battle Stage: Balancing offence and defence, my filler places a weighting on growing away from itself and growing towards the enemy, then chooses the location with the most optimal score.

[Insert Heatmap Enemy]
[Insert Heatmap Growth]
[Insert Heatmap Combined]


## Getting Started

Clone this repo and make the player using `make`. Then choose from:

Basic Mode:
`sh play_basic.sh [player1] [player2] [map]`

Visual Mode:
`sh play_visual.sh [player1] [player2] [map]`

Battle All:
`sh play_opponents.sh [player1] [player2] [map]`

## UI Usage and Navigation

`[UI Screenshot Start] [UI Screenshot Mid] [UI Screenshot End]`

The UI can be used to analyze a game and determine effective strategies for beating other players. The UI will load the game at the starting point, and can be navigated using the keystrokes:

right ->: Move forward a turn 
left  <-: Move backwards a turn
x		: Close the window

## Battle Stats

`[Battle Stats Map00] [Battle Stats Map01] [Battle Stats Map02]`

## Built With

* [TKinter](https://wiki.python.org/moin/TkInter) - Python's built in GUI package
