#include <Blackjack/Deck.h>
#include <Blackjack/Card.h>
#include <SDL2/SDL.h>
#include <vector>
#include <SDL2/SDL_image.h>
#include <algorithm>
#include <random>

Deck::Deck(int amountOfDecks, SDL_Renderer* renderer) {
    for(int i = 0; i < amountOfDecks; i++ ) {
        for(int j = 1; j <= 13; j++) {
            for(int k = 0; k < 4; k++) {
                Suit suit = static_cast<Suit>(k);
                Card card(j, suit, nullptr);
                std::string cardPath = "resources/cards/" + card.getCardName() + ".png";
                SDL_Surface* cardSurface = IMG_Load(cardPath.c_str());
                SDL_Texture* cardTexture = SDL_CreateTextureFromSurface(renderer, cardSurface);
                card.setTexture(cardTexture);
                this->deck.push_back(card);
            }
        }
    }
    shuffleDeck();
}

void Deck::shuffleDeck() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
}


Card Deck::dealCard() {
    Card card = this->deck[0];
    this->deck.erase(this->deck.begin());
    return card;
}