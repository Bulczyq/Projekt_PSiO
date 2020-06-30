#ifndef PLATFORMA_H
#define PLATFORMA_H
#include <SFML/Graphics.hpp>
#include <klasa_abstrakcyjna.h>
class platforma : public klasa_abstrakcyjna
{
public:
    platforma(sf::Texture &tekstura_polka, float pozycja_x, float pozycja_y);
    void animuj() override;
};

#endif // PLATFORMA_H
