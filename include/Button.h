#pragma once

#include <SDL2/SDL.h>
#include <functional>
#include <GameText.h>

class Button {
public:
    Button(int x, int y, int w, int h, SDL_Color color, std::function<void()> callback);
    Button(GameText* text, int x, int y, int w, int h, SDL_Color color, std::function<void()> callback);
    void render(SDL_Renderer* renderer);
    void handleEvent(SDL_Event* event);

private:
    SDL_Rect rect;
    SDL_Color color;
    std::function<void()> callback;
    GameText* text;
};
