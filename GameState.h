#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>
#include <memory>
#include <string>

class Player;
class Board;

class GameState : public Subject {
public:
    bool HasWon();
    void NextTurn();
    std::shared_ptr<Player> GetCurrentPlayer();
    std::shared_ptr<Player> GetOtherPlayer();
    Board* GetBoard();
    void ExecuteAbility(int AbilityId, const std::vector<std::string>& param);
    void moveLink(char Link, const std::string& Dir);
    void setWinner(std::shared_ptr<Player>);
    std::shared_ptr<Player> GetWinner(Player*);

private:
    std::vector<std::shared_ptr<Player>> players;
    std::shared_ptr<Board> board;
    bool GameOver;
    int PlayerTurn;
    bool abilityUsed;
};

#endif 
