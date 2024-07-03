#include <GameText.h>
#include <iostream>

GameText::GameText(int x, int y, std::string text, SDL_Color color, SDL_Renderer* renderer)
    : color(color), texture(nullptr), text(text) {
    rect.x = x;
    rect.y = y;
    rect.w = 0;
    rect.h = 0;
    TTF_Font* font = TTF_OpenFont("resources/fonts/Minecraft.ttf", 24);
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    if (surface == nullptr) {
        std::cerr << "TTF_RenderText_Solid error: " << TTF_GetError() << std::endl;
        return;
    }
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == nullptr) {
        std::cerr << "SDL_CreateTextureFromSurface error: " << SDL_GetError() << std::endl;
    }
    TTF_SizeText(font, text.c_str(), &rect.w, &rect.h);
    SDL_FreeSurface(surface);
}


GameText::~GameText() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

void GameText::render(SDL_Renderer* renderer) {
    if(text.empty()) return;
    if(!texture) {
        generateTexture(renderer);
    }
    if (texture && SDL_RenderCopy(renderer, texture, NULL, &rect) != 0) {
        std::cerr << "SDL_RenderCopy error: " << SDL_GetError() << std::endl;
    }
}

void GameText::generateTexture(SDL_Renderer* renderer) {
    TTF_Font* font = TTF_OpenFont("resources/fonts/Minecraft.ttf", 24);
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    if (surface == nullptr) {
        std::cerr << "TTF_RenderText_Solid error: " << TTF_GetError() << std::endl;
        return;
    }
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == nullptr) {
        std::cerr << "SDL_CreateTextureFromSurface error: " << SDL_GetError() << std::endl;
    }
    TTF_SizeText(font, text.c_str(), &rect.w, &rect.h);
    SDL_FreeSurface(surface);

}

void GameText::setPosition(int x, int y) {
    rect.x = x;
    rect.y = y;
}  
void GameText::setText(std::string text, SDL_Renderer* renderer) {
    this->text = text;
    generateTexture(renderer);
}

std::string GameText::getText() const {
    return text;
}

SDL_Rect GameText::getRect() const {
    return rect;
}
