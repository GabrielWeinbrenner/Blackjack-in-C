#include <Button.h>
#include <functional>

Button::Button(int x, int y, int w, int h, SDL_Color color, std::function<void()> callback)
    : rect{x, y, w, h}, color(color), callback(callback) {}

void Button::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
}

void Button::handleEvent(SDL_Event* event) {
    if (event->type == SDL_MOUSEBUTTONDOWN) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        bool inside = true;

        // Check if mouse is outside the button
        if (x < rect.x || x > rect.x + rect.w || y < rect.y || y > rect.y + rect.h) {
            inside = false;
        }

        // Call the callback function if the button is clicked
        if (inside) {
            callback();
        }
    }
}
