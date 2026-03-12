#include "GameSession.h"
#include <iostream>

GameSession::GameSession()
    : currentPlayerIndex(0), round(1), maxRounds(20), gameOver(false) {}

void GameSession::setupGame() {
    Player p1("Player 1");
    p1.addTile({6, 6});
    p1.addTile({6, 5});
    p1.addTile({4, 2});

    Player p2("Player 2");
    p2.addTile({5, 3});
    p2.addTile({2, 1});
    p2.addTile({1, 1});

    players.push_back(p1);
    players.push_back(p2);

    DominoTile startingTile = {6, 1};
    board.setStartingTile(startingTile);

    std::cout << "=== GAME SETUP ===" << std::endl;
    std::cout << "Starting tile: [" << startingTile.left << "|" << startingTile.right << "]" << std::endl;
    std::cout << std::endl;
}

void GameSession::run() {
    setupGame();

    std::cout << "=== GAME START ===" << std::endl;

    while (!gameOver && round <= maxRounds) {
        std::cout << "\n--- Round " << round << " ---" << std::endl;
        playTurn();

        if (checkWinCondition()) {
            gameOver = true;
            break;
        }

        advanceTurn();
        round++;
    }

    std::cout << "\n=== GAME END ===" << std::endl;
}

void GameSession::playTurn() {
    Player& currentPlayer = players[currentPlayerIndex];

    std::cout << "Current player: " << currentPlayer.getName() << std::endl;
    printBoard();
    printPlayerHand(currentPlayer);

    bool played = tryPlayTile(currentPlayer);

    if (!played) {
        passTurn(currentPlayer);
    }
}

bool GameSession::tryPlayTile(Player& player) {
    std::vector<DominoTile>& hand = player.getHand();

    for (int i = 0; i < static_cast<int>(hand.size()); i++) {
        if (validator.canPlay(hand[i], board)) {
            DominoTile chosenTile = hand[i];

            std::cout << player.getName() << " plays ["
                      << chosenTile.left << "|" << chosenTile.right << "]" << std::endl;

            board.placeTile(chosenTile);
            player.removeTile(i);
            return true;
        }
    }

    return false;
}

void GameSession::passTurn(const Player& player) const {
    std::cout << player.getName() << " cannot play and passes." << std::endl;
}

bool GameSession::checkWinCondition() const {
    for (const Player& player : players) {
        if (player.hasNoTiles()) {
            std::cout << player.getName() << " wins because all tiles are used." << std::endl;
            return true;
        }
    }
    return false;
}

void GameSession::advanceTurn() {
    currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
}

void GameSession::printBoard() const {
    std::cout << "Board: ";
    for (const DominoTile& tile : board.getTiles()) {
        std::cout << "[" << tile.left << "|" << tile.right << "] ";
    }
    std::cout << std::endl;
}

void GameSession::printPlayerHand(const Player& player) const {
    std::cout << player.getName() << " hand: ";
    for (const DominoTile& tile : player.getHand()) {
        std::cout << "[" << tile.left << "|" << tile.right << "] ";
    }
    std::cout << std::endl;
}