#ifndef COIN_H
#define COIN_H
#include <SFML/Graphics.hpp>
#include <klasa_abstrakcyjna.h>
class Coin : public klasa_abstrakcyjna
{
public:
    Coin(sf::Texture &tekstura, float pozycja_x, float pozycja_y);
    void animuj() override;
};

#endif // COIN_H
