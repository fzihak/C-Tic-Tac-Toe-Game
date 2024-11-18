# C++ Tic-Tac-Toe Game

A command-line implementation of the classic Tic-Tac-Toe game written in C++. 

![Screenshot](IMG_20241103_123233.jpg)

## Features

- Two game modes:
  - Player vs Player
  - Player vs AI
- Unbeatable AI using Minimax algorithm
- Game statistics tracking
- Clear and intuitive interface
- Input validation
- Cross-platform compatibility

## Requirements

- C++ compiler with C++11 support or higher
- Standard C++ libraries

### Gameplay Instructions
> The game board uses numbers 0-8 for positions:

```cpp
 0 | 1 | 2 
---+---+---
 3 | 4 | 5 
---+---+---
 6 | 7 | 8
```
> Main Menu Options:

1: Play against another player
2: Play against AI
3: View game statistics
4: Exit

> During gameplay:

- Enter a number (0-8) to place your mark
- X always goes first
- In AI mode, player is X and AI is O

> Game Rules
- Players take turns placing their marks (X or O)
- First player to get three marks in a row (horizontal, vertical, or diagonal) wins
- If all positions are filled and no winner, the game is a draw

### Contributing
Feel free to fork this project and submit pull requests for any improvements:

- UI enhancements
- Additional features
- Bug fixes
- Performance optimizations

### License
This project is open source and available under the [MIT License](License)
