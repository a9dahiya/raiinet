#include "Cell.h"
#include "Position.h"
#include "Link.h"
#include "Firewall.h"
#include <iostream>

// Constructs a Cell with a position, optional link, and server port status.
// Inputs: Position pos, std::shared_ptr<Link> link, bool serverPort
// Outputs: None
// Time Complexity: O(1)
Cell::Cell(Position pos, std::shared_ptr<Link> link, bool serverPort) : 
    pos{pos}, link{link}, isserverPort{serverPort} {}

// Returns the position of the cell.
// Inputs: None
// Outputs: Position - The position of the cell.
// Time Complexity: O(1)
Position Cell::getPos() {
    return pos;
}

// Returns the link stored in the cell, or nullptr if none exists.
// Inputs: None
// Outputs: std::shared_ptr<Link> - The link in the cell.
// Time Complexity: O(1)
std::shared_ptr<Link> Cell::getLink() {
    return link;
}

// Returns the firewall stored in the cell, or nullptr if none exists.
// Inputs: None
// Outputs: std::shared_ptr<Firewall> - The firewall in the cell.
// Time Complexity: O(1)
std::shared_ptr<Firewall> Cell::getFirewall() {
    return fire;
}

// Removes the link from the cell, setting it to nullptr.
// Inputs: None
// Outputs: None
// Time Complexity: O(1)
void Cell::removeLink() {
    link = nullptr;
}

// Sets the link for the cell.
// Inputs: std::shared_ptr<Link> li - The link to set.
// Outputs: None
// Time Complexity: O(1)
void Cell::setLink(std::shared_ptr<Link> li) {
    link = li;
}

// Sets the firewall for the cell and marks it as containing a firewall.
// Inputs: std::shared_ptr<Firewall> firee - The firewall to set.
// Outputs: None
// Time Complexity: O(1)
void Cell::setFirewall(std::shared_ptr<Firewall> firee) {
    isfirewall = true;
    fire = firee;
}

// Removes the firewall from the cell and marks it as no longer containing a firewall.
// Inputs: None
// Outputs: None
// Time Complexity: O(1)
void Cell::removeFirewall() {
    isfirewall = false;
    fire = nullptr;
}

// Checks if the cell is a server port.
// Inputs: None
// Outputs: bool - True if the cell is a server port, false otherwise.
// Time Complexity: O(1)
bool Cell::isServerPort() {
    return isserverPort;
}

// Checks if the cell contains a firewall.
// Inputs: None
// Outputs: bool - True if the cell contains a firewall, false otherwise.
// Time Complexity: O(1)
bool Cell::isFirewall() {
    return isfirewall;
}

// Sets whether the cell is a server port.
// Inputs: bool isServer - True to mark as server port, false otherwise.
// Outputs: None
// Time Complexity: O(1)
void Cell::setServerPort(bool isServer) {
    isserverPort = isServer;
}
