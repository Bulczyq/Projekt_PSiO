#include "Friendly_postac.h"
#include <SFML/Graphics.hpp>
Friendly_postac::Friendly_postac(sf::Texture &tekstura_grzybek, float pozycja_x, float pozycja_y)
{
    setTexture(tekstura_grzybek);
    setPosition(pozycja_x, pozycja_y);
}
void Friendly_postac::move_grzybkiem(int &liczba){
    if(liczba == 0){
        move(-0.1, 0);
    }
    if(liczba == 1){
        move(0.1, 0);
    }
}
void Friendly_postac::animuj(){}
