#include "platforma.h"
#include <SFML/Graphics.hpp>
platforma::platforma(sf::Texture &tekstura_polka, float pozycja_x, float pozycja_y)
{
    setTexture(tekstura_polka);
    setPosition(pozycja_x, pozycja_y);
}
void platforma::animuj(){}
