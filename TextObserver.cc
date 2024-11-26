#include "TextObserver.h"
using namespace std;

TextObserver::TextObserver(shared_ptr<GameState> subject, shared_ptr<Player> Viewer): subject{subject}, Viewer{Viewer}{}