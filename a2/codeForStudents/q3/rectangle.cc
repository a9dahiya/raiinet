#include "rectangle.h"

Colour translateColour( char c ) {
    switch( c ) {
        case 'r' : return Colour::Red;
        case 'g' : return Colour::Green;
        case 'b' : return Colour::Blue;
        case 'y' : return Colour::Yellow;
        case 'o' : return Colour::Orange;
        case 'a' : return Colour::Black;
        case 'w' : return Colour::White;
    }
    return Colour::Red;
} // translate
