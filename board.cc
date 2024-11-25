#include "Position.h"
#include "Cell.h"
#include "board.h"
#include "GameState.h"
using namespace std;

Board::Board(std::vector<std::shared_ptr<Player>> players) : board(height, std::vector<std::shared_ptr<Cell>>(width, nullptr)) {
    serverPorts = {
        Position(0, width / 2 - 1),
        Position(0, width / 2),
        Position(height - 1, width / 2 - 1),
        Position(height - 1, width / 2)
    };

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            board[y][x] = std::make_shared<Cell>(Position{x, y}, nullptr);
        }
    }

    for (size_t index = 0; index < players.size(); ++index) {
        auto player = players[index];
        auto links = player->getAllLinks();

        int portrow = (index == 0) ? height - 1 : 0;
        int belowrow = (index == 0) ? height - 2 : 1;

        int linkindex = 0;
        for (int x = 0; x < width; ++x) {
            Position currentPos(portrow, x);
            bool isServerPort = false;

            for (size_t i = 0; i < serverPorts.size(); ++i) {
                if (serverPorts[i] == currentPos) {
                    isServerPort = true;
                    break;
                }
            }

            if (isServerPort) {
                board[belowrow][x]->setLink(links[linkindex]);
                linkindex++;
            } else {
                board[portrow][x]->setLink(links[linkindex++]);
                linkindex++;
            }

            if (linkindex >= links.size()) {
                break;
            }
        }
    }
}

bool Board::hasOppLink(Position pos, std::shared_ptr<Player> player) {
   
    auto cell = board[pos.getRow()][pos.getCol()];
    
    return cell->getLink() && !player->isOwnLink(cell->getLink());
}

void Board::tatake(std::shared_ptr<Link> attacker, std::shared_ptr<Link> defender) {
    attacker->setRevealed();
    defender->setRevealed();

    bool attackerIsBattleGod = attacker->getIsBattleGod();
    bool defenderIsBattleGod = defender->getIsBattleGod();
    std::shared_ptr<Link> loser;
    std::shared_ptr<Link> winner;

    if (attackerIsBattleGod) {
        loser = defender;
        winner = attacker;
    } else if (defenderIsBattleGod) {
        loser = attacker;
        winner = defender;
    } else {
        int attackerStrength = attacker->getStrength();
        int defenderStrength = defender->getStrength();

        if (attackerStrength > defenderStrength) {
            loser = defender;
            winner = attacker;
        } else if (attackerStrength < defenderStrength) {
            loser = attacker;
            winner = defender;
        } else {
            loser = defender;
            winner = attacker;
        }
    }

    winner->getOwner()->downloadLink(loser);

    Position loserPos = loser->getPos();
    removeLink(loserPos);
}


void Board::moveLink(std::shared_ptr<Link> link, Position from, Position to, shared_ptr<GameState> game) {
    if (!link) return;

    shared_ptr<Cell> cellFrom = getCell(from);
    shared_ptr<Cell> cellTo = getCell(to);
    
    if(offEdge(from, game->GetCurrentPlayer())){
        game->GetCurrentPlayer()->downloadLink(link);
    }else if( isOppServer(game->GetCurrentPlayer()) ){
        game->GetOtherPlayer()->downloadLink(link);
    }else if(cellTo->getLink){
        gam
    }else {
        cellFrom->removeLink();
        cellTo->setLink(link);
        link->setPos(to);
    }

}

std::shared_ptr<Cell> Board::getCell(Position pos) {
    return board[pos.getRow()][pos.getCol()];
}


void Board::removeLink(Position pos) {
    auto cell = getCell(pos);
    if (cell->getLink()) {
        cell->removeLink();
    } else {
        // shoot the error out daddy
    }
}