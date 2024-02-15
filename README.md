# Pikachu Matching Game
## Overview
This repository contains the source code for a simple Pikachu matching game implemented in C++. The game offers a standard mode where the player matches pairs of Pikachu icons on a board.

## Features
- **Standard Mode**: The main feature of the game where players match pairs of Pikachu icons on a dynamically generated board.

## Getting Started
To run the game, simply compile the source code using a C++ compiler and execute the generated executable. Follow the on-screen prompts to navigate through the game.

```bash
g++ main.cpp algorithm.cpp board.cpp textAnimation.cpp -o pikachu_game
./pikachu_game
```

## Dependencies
 - **Windows API**: The game utilizes the Windows API for handling console output and colors.

## How to Play

1. Choose option 1 to enter the Standard Mode.
2. Enter the coordinates (X Y) for the points of the first and second Pikachu.
3. If the Pikachu icons match, they will be removed from the board. Otherwise, the player can try again.
4. Continue matching Pikachu icons until all pairs are matched.
5. The game ends when all pairs are successfully matched.

## Color Codes

The game uses different color codes for console text output:

- 1: Blue
- 2: Green
- 3: Cyan
- 4: Red
- 5: Purple
- 6: Yellow (Dark)
- 7: Default white
- 8: Gray / Grey
- 9: Bright blue
- 10: Bright green
- 11: Bright cyan
- 12: Bright red
- 13: Pink / Magenta
- 14: Yellow
- 15: Bright white

## Notes

- The game clears the console screen frequently to provide a better user experience.
- The game includes colorful text animations to enhance the visual appeal.

## Contributions

Contributions to the codebase or improvements to the game are welcome.
