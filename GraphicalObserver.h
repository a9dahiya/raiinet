#ifndef GRAPHICALOBSERVER_H
#define GRAPHICALOBSERVER_H

#include <memory>
#include "Observer.h"
#include "XWindow.h"
#include "GameState.h"
#include "Player.h"

class GraphicalObserver : public Observer {
public:
    void notify() override;
    GraphicalObserver(std::shared_ptr<GameState> subject, std::shared_ptr<Player> Viewer);
    ~GraphicalObserver(); 

private:
    std::shared_ptr<GameState> subject;
    std::shared_ptr<Player> Viewer;
    int height; // Board height
    int width;  // Board width
    std::shared_ptr<Xwindow> window; 
    const int PixelSize = 50; // Size of each cell in pixels
    const int InfoHeight = 150; // Height reserved for player info

    // Colors (extend if needed)
    enum Color {
        White = 0,
        Black,
        Red,
        Green,
        Blue,
        Yellow,
        Cyan,
        Magenta
    };

    // Helpers
    void drawBoard();
    void drawPlayerInfo(std::shared_ptr<Player> player, int yOffset, bool isViewer);
    void clearWindow();
};

#endif // GRAPHICALOBSERVER_H
