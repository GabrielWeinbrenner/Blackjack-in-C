#ifndef DECK_H
#define DECK_H

#include <string>
#include <SDL2/SDL.h>
#include <vector>
#include <Blackjack/Card.h>

class Deck {
public:
    Deck(int amountOfDecks, SDL_Renderer* renderer);
    void shuffleDeck();
    Card dealCard();
    // ~Deck();
private:
    std::vector<Card> deck;
    std::vector<Card> discard;
};
#endif // DECK_H