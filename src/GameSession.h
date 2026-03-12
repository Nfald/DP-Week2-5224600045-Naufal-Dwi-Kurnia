#ifndef GAME_SESSION_H
#define GAME_SESSION_H

#include <vector>
#include <string>

struct DominoTile {
    int left;
    int right;
};

struct Player {
    std::string name;
    std::vector<DominoTile> hand;
};

class GameSession {
private:
    std::vector<Player> players;
    std::vector<DominoTile> board;
    int currentPlayerIndex;
    int round;
    int maxRounds;
    bool gameOver;

    void setupGame();
    void playTurn();
    bool canPlayTile(const DominoTile& tile) const;
    bool tryPlayTile(Player& player);
    void passTurn(const Player& player) const;
    void updateBoard(const DominoTile& tile);
    bool checkWinCondition() const;
    void advanceTurn();
    void printBoard() const;
    void printPlayerHand(const Player& player) const;

public:
    GameSession();
    void run();
};

#endif