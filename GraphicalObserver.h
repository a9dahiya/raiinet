#ifndef GRAPHICALOBSERVER_H
#define GRAPHICALOBSERVER_H

#include <memory>
#include "Observer.h"
#include "XWindow.h"
#include "GameState.h"
#include "Player.h"
using namespace std;

class GraphicalObserver : public Observer {
public:
    void notify() override;
    GraphicalObserver(shared_ptr<GameState> subject, shared_ptr<Player> Viewer);
private:
    std::shared_ptr<GameState> subject;
    std::shared_ptr<Player> Viewer;
    int height = 8;
    int width = 8;
    Xwindow *window; //added ptr here cuz some error was happening, might have to change in the future
    int PixelSize = 10;
};

#endif // GRAPHICALOBSERVER_H
