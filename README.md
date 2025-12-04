# 🎲 421 Dice Game

A classic French dice game developed in C, offering a complete experience with console interface, solo mode against AI, and local multiplayer.

## 📋 Description

421 is a traditional dice game where two players compete by rolling three dice. The objective is to obtain the most powerful combination to win tokens and eliminate your opponent.

## ✨ Features

- 🎮 **Two game modes**
  - Player vs Player (local)
  - Player vs AI
  
- 🎯 **Complete game system**
  - Power system based on dice combinations
  - Token mechanism with central pot (21 tokens)
  - Game phases: Charge (C) and Discharge (D)
  - Up to 3 re-rolls per turn
  
- 🤖 **Intelligent AI**
  - Adaptive strategy based on dice power
  - Automatic re-rolling of weak dice
  
- 🎨 **Polished console interface**
  - ASCII art dice display
  - Clear and intuitive interface
  - Windows and Linux compatible

## 🏗️ Project Structure

```
421/
├── main.c          # Program entry point
├── game.c/h        # Main game logic
├── rules.c/h       # Rules and power calculations
├── dice.c/h        # Dice management and display
├── ai.c/h          # Artificial intelligence
└── utils.c/h       # Utility functions
```

## 📊 Combination Hierarchy

| Rank | Combination | Power | Tokens |
|------|-------------|-------|--------|
| 1 | 4-2-1 | 1 | 10 |
| 2 | 1-1-1 | 2 | 7 |
| 3 | 1-1-6 | 3 | 6 |
| 4 | 6-6-6 | 4 | 6 |
| 5 | 1-1-5 | 5 | 5 |
| 6 | 5-5-5 | 6 | 5 |
| 7 | 1-1-4 | 7 | 4 |
| 8 | 4-4-4 | 8 | 4 |
| 9 | 1-1-3 | 9 | 3 |
| 10 | 3-3-3 | 10 | 3 |
| 11 | 1-1-2 | 11 | 2 |
| 12 | 2-2-2 | 12 | 2 |
| 13 | 6-5-4 | 13 | 2 |
| 14 | 5-4-3 | 14 | 2 |
| 15 | 4-3-2 | 15 | 2 |
| 16 | 3-2-1 | 16 | 2 |
| 17 | 2-2-1 (Nenette) | 17 | Automatic win |
| 18 | Other | 18 | 1 |

*Note: For combinations with power 18, the winner is determined by the sum of the dice.*

## 🎮 Game Rules

### Game Flow

1. **Initial phase**: Determination round to decide who starts
2. **Charge phase** (C): Players accumulate tokens from the pot (21 tokens)
3. **Discharge phase** (D): Once the pot is empty, players exchange their tokens
4. **Victory**: The first player to reach 0 tokens wins the game

### Turn Structure

- Each player rolls 3 dice
- Option to re-roll selected dice (up to 3 rolls maximum)
- The second player cannot make more rolls than the first
- Power comparison to determine the loser
- The loser collects tokens based on the winner's power

## 🚀 Compilation and Execution

### With Code::Blocks

1. Open Code::Blocks
2. Add an existing project
3. Open the folder containing the project

### Command Line

#### Windows (MinGW)
```bash
gcc main.c game.c rules.c dice.c ai.c utils.c -o 421.exe
421.exe
```

#### Linux/Mac
```bash
gcc main.c game.c rules.c dice.c ai.c utils.c -o 421
./421
```

## 🎯 Usage

1. Launch the program
2. Choose your game mode (1 or 2)
3. Follow the on-screen instructions
4. To re-roll dice, enter their numbers (e.g., "13" to re-roll dice 1 and 3)
5. Press Enter to continue between turns

## 🛠️ Prerequisites

- C compiler (GCC, MinGW, or other)
- Code::Blocks (recommended) or any other C IDE
- Operating system: Windows, Linux, or macOS

## 📝 License

Educational project, free to use.

## 👨‍💻 Contribution

This project is a complete and functional game. Possible improvements:
- SDL graphics integration
- Game save functionality
- Network multiplayer mode
- Statistics and game history
- AI difficulty levels

---

**Enjoy the game! 🎲🎲🎲**