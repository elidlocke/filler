# Filler: Battle of the Tetris SHapes

Filler is a game, similar to Blockus, where two players take turns placing tetrimino shapes on a board. In this version, a virtual machine organizes the game by giving each player a random piece at the start of each turn. The player who places the most tetrimino shapes wins.

This repository contains two parts:
- My filler player, written in C
- A UI, written in Python

## Game Strategy

my Filler player has two stages:

1) Seed Stage: Fill towards the opposite corner, to cover an appropriate starting amount of the board.

[Insert Seed Image]

2) Battle Stage: Balancing offence and defence, my filler places a weighting on growing away from itself and growing towards the enemy, then chooses the location with the most optimal score.

[Insert Heatmap 01]
[Insert Heatmap 02]

## UI Usage

## Getting Started

download the 

### Prerequisites

What things you need to install the software and how to install them

```
Give examples
```

### Installing

A step by step series of examples that tell you have to get a development env running

Say what the step will be

```
Give the example
```

And repeat

```
until finished
```

End with an example of getting some data out of the system or using it for a little demo

## Built With

* [Dropwizard](http://www.dropwizard.io/1.0.2/docs/) - The web framework used
* [Maven](https://maven.apache.org/) - Dependency Management
* [ROME](https://rometools.github.io/rome/) - Used to generate RSS Feeds

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags). 

## Authors

* **Billie Thompson** - *Initial work* - [PurpleBooth](https://github.com/PurpleBooth)

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Hat tip to anyone who's code was used
* Inspiration
* etc

