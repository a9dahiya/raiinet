#include "board.h"
#include "Cell.h"
#include "Link.h"
#include "Player.h"
#include "Position.h"
#include "GameState.h"
#include "Firewall.h" 
#include <iostream>
using namespace std;


// Initializes the game board (constructor)
// - Creates a 2D grid of cells.
// - Assigns server ports to players based on their roles.
// - Positions links for each player near their server ports.
// Inputs:
//   - std::vector<std::shared_ptr<Player>> players: List of players in the game.
// Outputs: Initializes the board with all components set up.
// Time Complexity: O(height * width + players.size() * width)
Board::Board(std::vector<std::shared_ptr<Player>> players)
    : board(height, std::vector<std::shared_ptr<Cell>>(width, nullptr)) 
{
    // Initialize server ports
    serverPorts = {
        Position(0, width / 2 - 1),
        Position(0, width / 2),
        Position(height - 1, width / 2 - 1),
        Position(height - 1, width / 2)
    };

    // Assign server ports to players
    if (players.size() >= 2) {
        players[0]->setServerPort(serverPorts[0]);  
        players[0]->setServerPort(serverPorts[1]); 
        players[1]->setServerPort(serverPorts[2]); 
        players[1]->setServerPort(serverPorts[3]);   
    } else {
    }

    // Initialize cells and mark server ports
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            Position pos(y, x); // Assuming Position is (row, col)
            bool isServerPort = false;

            // Check if current position is a server port
            for (size_t sp = 0; sp < serverPorts.size(); ++sp) {
                if (serverPorts[sp] == pos) {
                    isServerPort = true;
                    break;
                }
            }

            // Create cell with or without server port
            board[y][x] = std::make_shared<Cell>(pos, nullptr, isServerPort);
        }
    }

    // Assign links to cells
    for (size_t index = 0; index < players.size(); ++index) {
        auto player = players[index];
        auto links = player->getAllLinks();

        // Determine rows based on player index
        int portrow = (index == 0) ? 0 : height - 1;
        int belowrow = (index == 0) ? 1 : height - 2;

        int linkindex = 0;
        int link_size = links.size();

        for (int x = 0; x < width && linkindex < link_size; ++x) {
            Position currentPos(portrow, x);
            bool isServerPort = false;

            // Check if current position is a server port
            for (size_t sp = 0; sp < serverPorts.size(); ++sp) {
                if (serverPorts[sp] == currentPos) {
                    isServerPort = true;
                    break;
                }
            }

            if (isServerPort) {
                // Assign link to the cell below the server port
                if (belowrow >= 0 && belowrow < height) { // Safety check
                    board[belowrow][x]->setLink(links[linkindex]);
                    links[linkindex]->setPos(Position(belowrow, x));
                    linkindex++;
                } else {
                    std::cerr << "Error: belowrow " << belowrow << " out of bounds.\n";
                }
            } else {
                // Assign link to the server port cell
                board[portrow][x]->setLink(links[linkindex]);
                links[linkindex]->setPos(Position(portrow, x));
                linkindex++;
            }

            // Break if all links are assigned
            if (linkindex >= link_size) {
                break;
            }
        }
       
    }
}

// Checks if a cell at a given position contains an opponent's link.
// Inputs: Position pos: The position to check,  std::shared_ptr<Player> player: The current player.
// Outputs: Returns true if the cell contains an opponent's link; otherwise, false.
// Time Complexity: O(1)
bool Board::hasOppLink(Position pos, std::shared_ptr<Player> player) {
   
    shared_ptr<Cell> cell = board[pos.getRow()][pos.getCol()];
    
    return cell->getLink() && !player->isOwnLink(cell->getLink());
}


// Resolves a battle between two links (attacker and defender).
// Inputs:std::shared_ptr<Link> attacker: The attacking link, std::shared_ptr<Link> defender: The defending link.
// Outputs: Returns the winning link after the battle.
// Time Complexity: O(1)
std::shared_ptr<Link> Board::tatakae(std::shared_ptr<Link> attacker, std::shared_ptr<Link> defender) {
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

// Moves a link from one cell to another.
// Inputs:
//   - std::shared_ptr<Link> link: The link to move.
//   - Position from: The starting position of the link.
//   - Position to: The destination position.
//   - std::shared_ptr<GameState> game: Current game state.
// Outputs: Moves the link and handles special conditions like firewalls and server ports.
// Time Complexity: O(1) per move, additional checks included.
void Board::moveLink(std::shared_ptr<Link> link, Position from, Position to, shared_ptr<GameState> game) {
    if (!link) return;

    if (offEdge(to, game->GetCurrentPlayer())){ 
        game->GetCurrentPlayer()->downloadLink(link);
        removeLink(link->getPos());
        return;
    }

    shared_ptr<Cell> cellFrom = getCell(from);
    shared_ptr<Cell> cellTo = getCell(to);

    if (cellFrom == nullptr || cellTo == nullptr) {
        std::cerr << "Error: Invalid cell in moveLink.\n";
        return;
    }

    
    
    if( isOppServer(to , game->GetCurrentPlayer()) ){
        game->GetNextPlayer()->downloadLink(link);
        removeLink(link->getPos());
    }else if( cellTo->isFirewall() ){
        if(link->getOwner() != cellTo->getFirewall()->getOwner() ){
            link->setRevealed();
        }
        if(link->getOwner() != cellTo->getFirewall()->getOwner() && !link->isData()){
            shared_ptr<Player> player = link->getOwner();
            player->downloadLink(link);
            cellFrom->removeLink();
        }else if( hasOppLink(to, game->GetCurrentPlayer()) ){
            shared_ptr<Link> defender = cellTo->getLink();
            shared_ptr<Link> winner = tatakae(link, defender);
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
        shared_ptr<Link> winner = tatakae(link, defender);
        cellFrom->removeLink();
        cellTo->setLink(winner);
        winner->setPos(to);
    }else {
        cellFrom->removeLink();
        cellTo->setLink(link);
        link->setPos(to);
    }

}

// Retrieves a cell at a specific position.
// Inputs: Position pos: The position of the cell to retrieve.
// Outputs: Returns the cell at the given position or nullptr if out of bounds.
// Time Complexity: O(1)
shared_ptr<Cell> Board::getCell(Position pos) const {
    if (pos.getRow() < 0 || pos.getRow() >= height || pos.getCol() < 0 || pos.getCol() >= width) {
        cerr << "Error: Position (" << pos.getRow() << ", " << pos.getCol() << ") is out of bounds.\n";
        return static_cast<shared_ptr<Cell>>(nullptr);
    }
    return board[pos.getRow()][pos.getCol()];
}


// Removes a link from a cell at a specific position.
// Inputs: Position pos: The position of the link to remove.
// Outputs: Removes the link from the specified cell.
// Time Complexity: O(1)
void Board::removeLink(Position pos) {
    auto cell = getCell(pos);
    if (cell->getLink()) {
        cell->removeLink();
    } else {
        // shoot the error out daddy
    }
}

// Gets the height of the board.
// Outputs: Returns the height of the board.
// Time Complexity: O(1)
int Board::getHeight() const {
    return height;
}

// Gets the width of the board.
// Outputs: Returns the width of the board.
// Time Complexity: O(1)
int Board::getWidth() const {
    return width;
}

// Checks if a position is off the edge of the board for a given player.
// Inputs: Position pos: The position to check, std::shared_ptr<Player> player: The current player.
// Outputs: Returns true if the position is off the edge; otherwise, false.
// Time Complexity: O(1)
bool Board::offEdge(Position pos, std::shared_ptr<Player> player) {
    int row = pos.getRow();

    if (player->getName() == "Player 2" && row < 0) {
        return true;
    } else if (player->getName() == "Player 1" && row >= height) {
        return true;
    }

    return false;
}



// Checks if a position belongs to the opponent's server port.
// Inputs: Position pos: The position to check, std::shared_ptr<Player> player: The current player.
// Outputs: Returns true if the position is an opponent's server port else false.
// Time Complexity: O(1)
bool Board::isOppServer(Position pos, std::shared_ptr<Player> player) {
    for (const auto& serverPort : serverPorts) {
        if (pos == serverPort && !player->isOwnServerPort(pos)) {
            return true;
        }
    }
    return false;
}

// Validates a move from one position to another for a given player.
// Inputs: Position from: The starting position, Position to: The destination position, 
// std::shared_ptr<Player> player: The current player.
// Outputs: Returns true if the move is valid; otherwise, false.
// Time Complexity: O(1)
bool Board::ValidMove(Position from, Position to, std::shared_ptr<Player> player) { // Have to check this properly
    if (to.getCol() < 0 || to.getCol() >= width) {
        return false;
    }

    if (offEdge(to, player)) {
        return true;
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
    if(!toCell) return false;
    auto targetLink = toCell->getLink();
    if (targetLink && player->isOwnLink(targetLink)) {
        return false;
    }

    return true;
}

// Overloads the output stream operator to print the board's current state.
// Time Complexity: O(height * width)
std::ostream& operator<<(std::ostream& out, const Board& board) {
    // Print top border
    out << "========\n";

    for (int row = 0; row < board.getHeight(); ++row) {
        for (int col = 0; col < board.getWidth(); ++col) {
            auto cell = board.getCell(Position(row, col));
            auto link = cell->getLink();

            if (link) {
                out << link->getLetter();
            }
            else if (cell->isFirewall()) {
                auto firewallOwner = cell->getFirewall()->getOwner();  
                if (firewallOwner->getName() == "Player 1") {
                    out << "m";  // Firewall by Player1
                }
                else if (firewallOwner->getName() == "Player 2") {
                    out << "w";  // Firewall by Player2
                }
            }
            else if (cell->isServerPort()) {
                out << "S"; // Represent server ports
            }
            else {
                out << ".";  // Empty cell
            }
        }
        out << "\n";
    }

    // Print bottom border
    out << "========\n";

    return out;
}
