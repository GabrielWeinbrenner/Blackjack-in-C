#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include <Blackjack/Card.h>
#include <Blackjack/Deck.h>
#include <SDL2/SDL_ttf.h>

class Blackjack {
public:
    Blackjack(SDL_Renderer* renderer);
    void reset();
    void render(SDL_Renderer* renderer);
    void hit();
    void stand();
    void renderHand(const std::vector<Card>& hand, SDL_Renderer* renderer, int y) const;
    bool isGameOver() const;

private:
    Deck deck;
    std::vector<Card> playerHand;
    std::vector<Card> dealerHand;
    bool gameOver;
    void dealerPlay();
    int getHandValue(const std::vector<Card>& hand) const;
    
    bool timerActive;
    Uint32 endTime;
};

