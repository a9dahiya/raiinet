#ifndef TEXTOBSERVER_H
#define TEXTOBSERVER_H

#include <memory>
#include "Observer.h"
#include "GameState.h"
#include "Player.h"

class TextObserver : public Observer {
public:
    void notify() override;
    TextObserver(shared_ptr<GameState> subject, shared_ptr<Player> Viewer);
private:
    std::shared_ptr<GameState> subject;
    std::shared_ptr<Player> Viewer;
    int height = 8;
    int width = 8;
};

#endif // TEXTOBSERVER_H
