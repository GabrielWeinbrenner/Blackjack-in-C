#include <Button.h>
#include <iostream>

Button::Button(int x, int y, int w, int h, SDL_Color color, std::function<void()> callback)
    : rect{x, y, w, h}, color(color), callback(callback), text(nullptr) {
    std::cout << "Button created at " << x << ", " << y << " with dimensions " << w << "x" << h << std::endl;
}

Button::Button(GameText* text, int x, int y, int w, int h, SDL_Color color, std::function<void()> callback)
    : rect{x, y, w, h}, color(color), callback(callback), text(text) {
    SDL_Rect textRect = text->getRect();
    textRect.x = x + (w - textRect.w) / 2;
    textRect.y = y + (h - textRect.h) / 2;
    text->setPosition(textRect.x, textRect.y);
    std::cout << "Button with text created at " << x << ", " << y << " with dimensions " << w << "x" << h << std::endl;
}

void Button::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
    if (this->text != nullptr) {
        this->text->render(renderer);
    }
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
