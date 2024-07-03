#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <string>
#include <SDL2/SDL.h>
#include <Blackjack/Deck.h>

class Blackjack {
public:
    Blackjack(SDL_Renderer* renderer);
    void render(SDL_Renderer* renderer);
    void reset();
    // ~Blackjack();
private:
    Deck deck;
    std::vector<Card> playerHand;
    std::vector<Card> dealerHand;
    void renderHand(const std::vector<Card> hand, SDL_Renderer* renderer, int y) const;
};
#endif // BLACKJACK_H