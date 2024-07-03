#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

class GameText {
public:
    GameText(int x, int y, std::string text, SDL_Color color, SDL_Renderer* renderer);
    ~GameText();
    void render(SDL_Renderer* renderer);
    std::string getText() const;
    void generateTexture(SDL_Renderer* renderer);
    void setText(std::string text, SDL_Renderer* renderer); 
    void setPosition(int x, int y);
    SDL_Rect getRect() const;

private:
    SDL_Rect rect;
    SDL_Color color;
    TTF_Font* font;
    SDL_Texture* texture;
    std::string text;
};
