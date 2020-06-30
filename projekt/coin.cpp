#include "coin.h"
#include <iostream>
#include <SFML/Graphics.hpp>
Coin::Coin(sf::Texture &tekstura, float pozycja_x, float pozycja_y)
{
    setTexture(tekstura);
    setPosition(pozycja_x, pozycja_y);
}
void Coin::animuj(){}
