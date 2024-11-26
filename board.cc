#include "board.h"
#include "Cell.h"
#include "Link.h"
#include "Player.h"
#include "Position.h"
#include "GameState.h"
using namespace std;

Board::Board(std::vector<std::shared_ptr<Player>> players) : board(height, std::vector<std::shared_ptr<Cell>>(width, nullptr)) {
    serverPorts = {
        Position(0, width / 2 - 1),
        Position(0, width / 2),
        Position(height - 1, width / 2 - 1),
        Position(height - 1, width / 2)
    };

    players[0]->setServerPort(serverPorts[0]);  
    players[0]->setServerPort(serverPorts[1]); 
    players[1]->setServerPort(serverPorts[2]); 
    players[1]->setServerPort(serverPorts[3]);   


    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            board[y][x] = std::make_shared<Cell>(Position{x, y}, nullptr); 
            //meoww hahah
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
                links[linkindex]->setPos(Position(belowrow, x));
                linkindex++;
            } else {
                board[portrow][x]->setLink(links[linkindex++]);
                links[linkindex]->setPos(Position(portrow, x));
                linkindex++;
            }

            if (linkindex >= links.size()) {
                break;
            }
        }
    }
}

bool Board::hasOppLink(Position pos, std::shared_ptr<Player> player) {
   
    shared_ptr<Cell> cell = board[pos.getRow()][pos.getCol()];
    
    return cell->getLink() && !player->isOwnLink(cell->getLink());
}

std::shared_ptr<Link> Board::tatake(std::shared_ptr<Link> attacker, std::shared_ptr<Link> defender) {
    attacker->setRevealed();
    defender->setRevealed();

    bool attackerIsBattleGod = attacker->isBattleGod();
    bool defenderIsBattleGod = defender->isBattleGod();
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

    return winner;
}


void Board::moveLink(std::shared_ptr<Link> link, Position from, Position to, shared_ptr<GameState> game) {
    if (!link) return;

    shared_ptr<Cell> cellFrom = getCell(from);
    shared_ptr<Cell> cellTo = getCell(to);
    
    if(offEdge(from, game->GetCurrentPlayer())){
        game->GetCurrentPlayer()->downloadLink(link);
    }else if( isOppServer(to , game->GetCurrentPlayer()) ){
        game->GetNextPlayer()->downloadLink(link);
    }else if( cellTo->isFirewall() ){
        if(link->getOwner() != game->GetCurrentPlayer() ){
            link->isRevealed();
        }
        if(!link->isData()){
            shared_ptr<Player> player = link->getOwner();
            player->downloadLink(link);
            cellFrom->removeLink();
        }else if( hasOppLink(to, game->GetCurrentPlayer()) ){
            shared_ptr<Link> defender = cellTo->getLink();
            shared_ptr<Link> winner = tatake(link, defender);
            cellFrom->removeLink();
            cellTo->setLink(winner);
            winner->setPos(to);
        }else{
            cellFrom->removeLink();
            cellTo->setLink(link);
            link->setPos(to);
        }
    }else if(hasOppLink(to, game->GetCurrentPlayer()) ){
        shared_ptr<Link> defender = cellTo->getLink();
        shared_ptr<Link> winner = tatake(link, defender);
        cellFrom->removeLink();
        cellTo->setLink(winner);
        winner->setPos(to);
    }else {
        cellFrom->removeLink();
        cellTo->setLink(link);
        link->setPos(to);
    }

}

std::shared_ptr<Cell> Board::getCell(Position pos) const {
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

int Board::getHeight() const {
    return height;
}

int Board::getWidth() const {
    return width;
}

bool Board::offEdge(Position pos, std::shared_ptr<Player> player) {
    int row = pos.getRow();
    int col = pos.getCol();

    if (player->getName() == "Player2" && row < 0) {
        return true;
    } else if (player->getName() == "Player1" && row >= height) {
        return true;
    }

    return false;
}




bool Board::isOppServer(Position pos, std::shared_ptr<Player> player) {
    for (const auto& serverPort : serverPorts) {
        if (pos == serverPort && !player->isOwnServerPort(pos)) {
            return true;
        }
    }
    return false;
}

bool Board::ValidMove(Position from, Position to, std::shared_ptr<Player> player) {
    if (to.getCol() < 0 || to.getCol() >= width || to.getRow() < 0 || to.getRow() >= height) {
        return false;
    }

    if (offEdge(to, player)) {
        return false;
    }

    if (player->isOwnServerPort(to)) {
        return false;
    }

    auto fromCell = getCell(from);
    auto link = fromCell->getLink();
    if (!link || !player->isOwnLink(link)) {
        return false;
    }

    auto toCell = getCell(to);
    auto targetLink = toCell->getLink();
    if (targetLink && player->isOwnLink(targetLink)) {
        return false;
    }

    return true;
}


std::ostream& operator<<(std::ostream& out, const Board& board) {
    for (int row = 0; row < board.getHeight(); ++row) {
        for (int col = 0; col < board.getWidth(); ++col) {
            auto cell = board.getCell(Position(row, col));
            auto link = cell->getLink();

            if (link) {
                out << link->getLetter();  
            } else if (cell->isFirewall()) {
                auto firewallOwner = cell->getFirewall()->getOwner();  
                if (firewallOwner->getName() == "Player1") {
                    out << "m";  
                } else if (firewallOwner->getName() == "Player2") {
                    out << "w";  
                }
            } else {
                out << ".";  
            }
        }
        out << "\n";
    }
    return out;
}
