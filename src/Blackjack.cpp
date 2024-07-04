#include <Blackjack/Blackjack.h>
#include <GameText.h>
#include <iostream>

Blackjack::Blackjack(SDL_Renderer* renderer) : deck(1, renderer), gameOver(false) {
    reset();
}

void Blackjack::reset() {
    this->playerHand.clear();
    this->dealerHand.clear();
    this->gameOver = false;
    this->timerActive = false;
    this->endTime = 0;

    deck.shuffleDeck();
    playerHand.push_back(deck.dealCard());
    playerHand.push_back(deck.dealCard());
    dealerHand.push_back(deck.dealCard());
    dealerHand.push_back(deck.dealCard(true)); // Dealer's second card is face down
}

void Blackjack::hit() {
    if (gameOver) return;
    playerHand.push_back(deck.dealCard());
    if (getHandValue(playerHand) > 21) {
        gameOver = true;
        timerActive = true;
        endTime = SDL_GetTicks() + 2000;

    }
}

void Blackjack::stand() {
    if (gameOver) return;
    dealerPlaying = true;
    
    endTime = SDL_GetTicks() + 1000;
    dealerEndTime = SDL_GetTicks() + 1000;


}

void Blackjack::dealerPlay() {
    if (!dealerPlaying) return;
    dealerHand[1].setFaceDown(false);
    Uint32 currentTime = SDL_GetTicks();
    if (currentTime < dealerEndTime) return;

    if (getHandValue(dealerHand) < 17) {
        dealerHand.push_back(deck.dealCard());
        dealerEndTime = currentTime + 1000;
    } else {
        dealerPlaying = false;
        gameOver = true;
        timerActive = true;
        endTime = SDL_GetTicks() + 2000;
    }
}

int Blackjack::getHandValue(const std::vector<Card>& hand) const {
    int value = 0;
    int numAces = 0;
    for (auto& card : hand) {
        if(card.getFaceDown()) continue;
        value += card.getValue();
        if (card.getValue() == 1) {
            numAces++;
        }
    }
    while (value > 21 && numAces > 0) {
        value -= 10; // Convert ACE from 11 to 1
        numAces--;
    }
    return value;
}

bool Blackjack::isGameOver() const {
    return gameOver;
}

void Blackjack::render(SDL_Renderer* renderer) {
    renderHand(playerHand, renderer, 400);
    renderHand(dealerHand, renderer, 50);

    int playerHandValue = getHandValue(playerHand);
    int dealerHandValue = getHandValue(dealerHand);
    GameText playerHandText(300, 570, "Player: " + std::to_string(playerHandValue), SDL_Color{255, 255, 255, 255}, renderer);
    playerHandText.render(renderer);
    GameText dealerHandText(300, 220, "Dealer: " + std::to_string(dealerHandValue), SDL_Color{255, 255, 255, 255}, renderer);
    dealerHandText.render(renderer);
    GameText resultText(300, 300, "", SDL_Color{255, 255, 255, 255}, renderer);

    if (gameOver) {
        if (playerHandValue > 21) {
            resultText.setText("Player Busts! Dealer Wins!", renderer);
        } else if (dealerHandValue > 21) {
            resultText.setText("Dealer Busts! Player Wins!", renderer);
        } else if (playerHandValue > dealerHandValue) {
            resultText.setText("Player Wins!", renderer);
        } else if (playerHandValue < dealerHandValue) {
            resultText.setText("Dealer Wins!", renderer);
        } else {
            resultText.setText("Push!", renderer);
        }
        resultText.render(renderer);

        if (timerActive && SDL_GetTicks() >= endTime) {
            reset();
        }
    }
    dealerPlay();
}

void Blackjack::renderHand(const std::vector<Card>& hand, SDL_Renderer* renderer, int y) const {
    int x = 300;
    for (const auto& card : hand) {
        SDL_Rect dest = {x, y, 100, 150};
        SDL_RenderCopy(renderer, card.getFaceDown() ? deck.back_texture : card.getTexture(), NULL, &dest);
        x += 40;
    }
}
