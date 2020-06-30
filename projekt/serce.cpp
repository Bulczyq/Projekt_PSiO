#include "serce.h"
#include <SFML/Graphics.hpp>
#include <Player.h>
Serce::Serce(sf::Texture &tekstura_serce, float pozycja_x, float pozycja_y)
{
    setTexture(tekstura_serce);
    setPosition(pozycja_x, pozycja_y);
}
void Serce::ruszaj_sercem(Player &player, int i){
    setPosition(player.getPosition().x + 30*i, 0);
}
void Serce::animuj(){};
