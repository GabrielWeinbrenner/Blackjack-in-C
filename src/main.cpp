#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Button.h>
#include <Blackjack/Blackjack.h>

// Constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(int argc, char* argv[]) {
    // Seed random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
        std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Initialize SDL_image
    if (IMG_Init(IMG_INIT_PNG) == 0) {
        std::cerr << "Error initializing SDL_image: " << IMG_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create window
    SDL_Window* win = SDL_CreateWindow("Blackjack Game",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!win) {
        std::cerr << "Error creating window: " << SDL_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    // Create renderer
    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    if (!rend) {
        std::cerr << "Error creating renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(win);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    // Initialize Blackjack game
    Blackjack blackjack(rend);

    // Create buttons
    std::vector<Button> buttons;
    buttons.emplace_back(400, 400, 200, 100, SDL_Color{255, 0, 0, 255}, [&blackjack]() { blackjack.reset(); });
    buttons.emplace_back(400, 250, 200, 100, SDL_Color{0, 255, 0, 255}, []() { std::cout << "Button 2 clicked!" << std::endl; });

    // Event loop
    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            // Handle button events
            for (auto& button : buttons) {
                button.handleEvent(&e);
            }
        }

        // Clear the window
        SDL_SetRenderDrawColor(rend, 0, 128, 0, 255);  // Green background
        SDL_RenderClear(rend);

        // Render game state
        blackjack.render(rend);

        // Render buttons
        for (auto& button : buttons) {
            button.render(rend);
        }

        // Update the window
        SDL_RenderPresent(rend);
    }

    // Clean up resources before exiting
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
