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
    SDL_Texture* getTexture() const;
    void setTexture(SDL_Texture* texture);
    std::string getCardName();

    void setFaceDown(bool faceDown) { this->faceDown = faceDown; }
    void reveal() { this->faceDown = false; }

    bool getFaceDown() const { return this->faceDown; }
    int getCardIndex() const { return this->cardIndex; }
    Suit getSuit() const { return this->suit; }

    int getValue() const {
        if (cardIndex > 10) {
            return 10;
        }
        
        return cardIndex;
    }
private:
    int cardIndex;
    // int isAce;
    bool faceDown;
    Suit suit;
    SDL_Texture* texture;
};
#endif // CARD_H