#include <Blackjack/Card.h>
#include <string>
#include <SDL2/SDL.h>
#include <Blackjack/Deck.h>

Card::Card(int cardIndex, Suit suit, SDL_Texture* texture) {
    this->cardIndex = cardIndex;   
    this->suit = suit;
    this->texture = texture;
}

// Card::~Card() {

// }
const std::string getSuitString(Suit enumVal) {
  return SuitStrings[enumVal];
}

std::string Card::getCardName() {
    std::string faceString = "";
    switch(this->cardIndex) {
        case 11:
            faceString = "J";
            break;
        case 12:
            faceString = "Q";
            break;
        case 13:
            faceString = "K";
            break;
        case 1:
            faceString = "ACE";
            break;
        default:
            faceString = std::to_string(this->cardIndex);
            break;
    }
    return getSuitString(this->suit) + "_" + faceString;
}

SDL_Texture* Card::getTexture() const {
    return this->texture;
}
void Card::setTexture(SDL_Texture* texture) {
    this->texture = texture;
}
