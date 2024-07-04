# 🃏 Blackjack in C++ 🃏

This project is a simple blackjack game implemented using SDL2, SDL2_image, and SDL2_ttf libraries. Test your luck and strategy against the dealer!
## Screenshots
![2024-07-04 at 00 28 30](https://github.com/GabrielWeinbrenner/Blackjack/assets/13935725/af1b3fff-6b01-4d62-a7df-81478155cf50)

## Features 🌟

- Classic Blackjack gameplay
- Smooth rendering with SDL2
- User-friendly interface with buttons for Hit and Stand
- Animated dealer actions with delay
- Displays game results with a timer

## Getting Started 🚀

### Prerequisites 📋

- C++ compiler (g++)
- SDL2 library
- SDL2_image library
- SDL2_ttf library

### Installation 🔧

1. **Clone the repository**
```sh
   git clone https://github.com/your-username/blackjack-game.git
   cd blackjack-game
```
2. **Install dependencies**
Make sure you have SDL2, SDL2_image, and SDL2_ttf installed on your system.

#### For Debian-based systems:
```sh
sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev
```

#### For macOS using Homebrew:
```sh
brew install sdl2 sdl2_image sdl2_ttf
```

### Building the Game 🛠️
1. **Compile the source code**
```sh
g++ src/*.cpp -o play -std=c++11 -Wall -g -I include -L lib -l SDL2 -l SDL2_image -l SDL2_ttf -lm
./play
```

## Gameplay Instructions 🎮

1. **Hit**: Draw another card to increase your hand's value.
2. **Stand**: Keep your current hand and let the dealer draw cards.
3. **Goal**: Get a hand value as close to 21 as possible without exceeding it.

### Example
- Player hand: 10♠, 7♥
- Dealer hand: 8♣, (hidden card)

After the player decides to **Hit** or **Stand**, the game will show the result based on the hand values.

## Code Overview 🧩

- `main.cpp`: Initializes SDL, creates the game window, and handles the main game loop.
- `Blackjack/Blackjack.cpp`: Contains the game logic, including dealing cards, calculating hand values, and rendering the game state.
- `GameText.cpp`: Handles rendering text on the screen.
- `Button.cpp`: Implements interactive buttons for the game interface.

## License 📄

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---
