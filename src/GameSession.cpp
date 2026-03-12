#include "GameSession.h"
#include <iostream>

GameSession::GameSession()
    : currentPlayerIndex(0), round(1), maxRounds(20), gameOver(false) {}

void GameSession::setupGame() {
    Player p1;
    p1.name = "Player 1";
    p1.hand = {
        {6, 6}, {6, 5}, {4, 2}
    };

    Player p2;
    p2.name = "Player 2";
    p2.hand = {
        {5, 3}, {2, 1}, {1, 1}
    };

    players.push_back(p1);
    players.push_back(p2);

    DominoTile startingTile = {6, 1};
    board.push_back(startingTile);

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

    std::cout << "Current player: " << currentPlayer.name << std::endl;
    printBoard();
    printPlayerHand(currentPlayer);

    bool played = tryPlayTile(currentPlayer);

    if (!played) {
        passTurn(currentPlayer);
    }
}

bool GameSession::canPlayTile(const DominoTile& tile) const {
    if (board.empty()) {
        return true;
    }

    int leftEnd = board.front().left;
    int rightEnd = board.back().right;

    return tile.left == leftEnd || tile.right == leftEnd ||
           tile.left == rightEnd || tile.right == rightEnd;
}

bool GameSession::tryPlayTile(Player& player) {
    for (size_t i = 0; i < player.hand.size(); i++) {
        if (canPlayTile(player.hand[i])) {
            DominoTile chosenTile = player.hand[i];

            std::cout << player.name << " plays ["
                      << chosenTile.left << "|" << chosenTile.right << "]" << std::endl;

            updateBoard(chosenTile);
            player.hand.erase(player.hand.begin() + i);
            return true;
        }
    }

    return false;
}

void GameSession::passTurn(const Player& player) const {
    std::cout << player.name << " cannot play and passes." << std::endl;
}

void GameSession::updateBoard(const DominoTile& tile) {
    if (board.empty()) {
        board.push_back(tile);
        return;
    }

    int leftEnd = board.front().left;
    int rightEnd = board.back().right;

    if (tile.right == leftEnd) {
        board.insert(board.begin(), tile);
    } else if (tile.left == leftEnd) {
        DominoTile flipped = {tile.right, tile.left};
        board.insert(board.begin(), flipped);
    } else if (tile.left == rightEnd) {
        board.push_back(tile);
    } else if (tile.right == rightEnd) {
        DominoTile flipped = {tile.right, tile.left};
        board.push_back(flipped);
    }
}

bool GameSession::checkWinCondition() const {
    for (const Player& player : players) {
        if (player.hand.empty()) {
            std::cout << player.name << " wins because all tiles are used." << std::endl;
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
    for (const DominoTile& tile : board) {
        std::cout << "[" << tile.left << "|" << tile.right << "] ";
    }
    std::cout << std::endl;
}

void GameSession::printPlayerHand(const Player& player) const {
    std::cout << player.name << " hand: ";
    for (const DominoTile& tile : player.hand) {
        std::cout << "[" << tile.left << "|" << tile.right << "] ";
    }
    std::cout << std::endl;
}