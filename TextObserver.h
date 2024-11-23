#ifndef TEXTOBSERVER_H
#define TEXTOBSERVER_H

#include <memory>
#include "Observer.h"

class GameState;
class Player;

class TextObserver : public Observer {
public:
    void notify(Subject* whoFrom) override;

private:
    std::shared_ptr<GameState> subject;
    std::shared_ptr<Player> Viewer;
    int height;
    int width;
};

#endif // TEXTOBSERVER_H
