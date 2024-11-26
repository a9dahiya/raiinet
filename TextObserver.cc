#include "TextObserver.h"
#include <iostream>
using namespace std;

TextObserver::TextObserver(shared_ptr<GameState> subject, shared_ptr<Player> Viewer): subject{subject}, Viewer{Viewer}{}

void TextObserver::notify() {
    cout << subject->GetBoard();
}
