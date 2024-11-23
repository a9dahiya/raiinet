#ifndef GRAPHICALOBSERVER_H
#define GRAPHICALOBSERVER_H

#include <memory>
#include "Observer.h"
#include "XWindow.h"


class GameState;
class Player;
class XWindow;

class GraphicalObserver : public Observer {
public:
    void notify(Subject* whoFrom) override;

private:
    std::shared_ptr<GameState> subject;
    std::shared_ptr<Player> Viewer;
    int height;
    int width;
    XWindow *window; //added ptr here cuz some error was happening, might have to change in the future
    int PixelSize;
};

#endif // GRAPHICALOBSERVER_H
