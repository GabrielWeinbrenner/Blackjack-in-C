#ifndef DECK_H
#define DECK_H

#include <string>
#include <SDL2/SDL.h>
#include <vector>
#include <Blackjack/Card.h>
#include <SDL2/SDL_image.h>

class Deck {
public:
    Deck(int amountOfDecks, SDL_Renderer* renderer);
    void shuffleDeck();
    Card dealCard(bool faceDown = false);
    // ~Deck();
    SDL_Texture* back_texture;
private:
    std::vector<Card> deck;
    std::vector<Card> discard;
};
#endif // DECK_H