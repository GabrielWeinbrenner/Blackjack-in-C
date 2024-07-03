#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL.h>
#include <functional>

class Button {
public:
    Button(int x, int y, int w, int h, SDL_Color color, std::function<void()> callback);
    void render(SDL_Renderer* renderer);
    void handleEvent(SDL_Event* event);

private:
    SDL_Rect rect;
    SDL_Color color;
    std::function<void()> callback;
};

#endif // BUTTON_H
