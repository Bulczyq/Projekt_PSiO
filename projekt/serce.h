#ifndef SERCE_H
#define SERCE_H
#include <SFML/Graphics.hpp>
#include <klasa_abstrakcyjna.h>
#include <Player.h>
class Serce : public klasa_abstrakcyjna
{
public:
    Serce(sf::Texture &tekstura_serce, float pozycja_x, float pozycja_y);
    void ruszaj_sercem(Player &player, int i);
    void animuj() override;;
};

#endif // SERCE_H
