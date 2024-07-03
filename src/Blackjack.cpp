#include <Blackjack/Blackjack.h>
#include <SDL2/SDL.h>
#include <iostream>

Blackjack::Blackjack(SDL_Renderer* renderer) : deck(1, renderer) {
    this->playerHand = std::vector<Card>();
    this->dealerHand = std::vector<Card>();
    playerHand.push_back(deck.dealCard());
    playerHand.push_back(deck.dealCard());
    dealerHand.push_back(deck.dealCard());
}

void Blackjack::reset() {
    this->playerHand.clear();
    this->dealerHand.clear();
    playerHand.push_back(deck.dealCard());
    playerHand.push_back(deck.dealCard());
    dealerHand.push_back(deck.dealCard());
} 

void Blackjack::render(SDL_Renderer* renderer) {
    renderHand(playerHand, renderer, 400);
    renderHand(dealerHand, renderer, 50);
}

void Blackjack::renderHand(std::vector<Card> hand, SDL_Renderer* renderer, int y) const {
    int x = 50;
    for(int i = 0; i < hand.size(); i++) {
        SDL_Rect dest;
        dest.x = x;
        dest.y = y;
        dest.w = 100;
        dest.h = 150;
        SDL_RenderCopy(renderer, hand[i].getTexture(), NULL, &dest);
        x += 120;
    }
}

