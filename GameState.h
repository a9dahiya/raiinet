#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>
#include <memory>
#include <string>
#include "board.h"
#include "subject.h"

class Player;
class Board;

class GameState : public Subject {
    std::vector<std::shared_ptr<Player>> players;
    std::shared_ptr<Board> board;
    std::shared_ptr<Player> winner = nullptr;
    bool GameOver = false;
    int PlayerTurn = 0;
    bool abilityUsed = false;
public:
    GameState(const vector<std::shared_ptr<Player>>& players);
    bool HasWon();
    void NextTurn();
    std::shared_ptr<Player> GetCurrentPlayer();
    std::shared_ptr<Player> GetNextPlayer();
    shared_ptr<Board> GetBoard();
    bool isAbilityUsed();
    void ExecuteAbility(int AbilityId, istream& in);
    void moveLink(char linkId, const std::string& Dir);
    void setWinner(std::shared_ptr<Player> player);
    std::shared_ptr<Player> GetWinner();
};

#endif 
