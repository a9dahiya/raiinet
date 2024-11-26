#include "GraphicalObserver.h"
using namespace std;

GraphicalObserver::GraphicalObserver(shared_ptr<GameState> subject, shared_ptr<Player> Viewer): subject{subject}, Viewer{Viewer}{}