#ifndef CARD_H
#define CARD_H

#include <string>
#include <SDL2/SDL.h>
enum Suit {
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES
};
static const char * SuitStrings[] = { "Hearts", "Diamonds", "Clubs", "Spades" };


class Card {
public:
    Card(int value, Suit suit, SDL_Texture* texture);
    // ~Card();
    SDL_Texture* getTexture();
    void setTexture(SDL_Texture* texture);
    std::string getCardName();

    bool getFaceDown() { return this->faceDown; }
    void setFaceDown(bool faceDown) { this->faceDown = faceDown; }
private:
    int value;
    // int isAce;
    bool faceDown;
    Suit suit;
    SDL_Texture* texture;
};
#endif // CARD_H