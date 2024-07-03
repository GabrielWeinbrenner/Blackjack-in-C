#include <Blackjack/Card.h>
#include <string>
#include <SDL2/SDL.h>
#include <Blackjack/Deck.h>

Card::Card(int value, Suit suit, SDL_Texture* texture) {
    this->value = value;   
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
    switch(this->value) {
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
            faceString = std::to_string(this->value);
            break;
    }
    return getSuitString(this->suit) + "_" + faceString;
}

SDL_Texture* Card::getTexture() {
    return this->texture;
}
void Card::setTexture(SDL_Texture* texture) {
    this->texture = texture;
}