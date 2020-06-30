#ifndef FRIENDLY_POSTAC_H
#define FRIENDLY_POSTAC_H
#include <klasa_abstrakcyjna.h>
#include <SFML/Graphics.hpp>
class Friendly_postac : public klasa_abstrakcyjna
{
public:
    int kierunek;
    void move_grzybkiem(int &liczba);
    Friendly_postac(sf::Texture &tekstura_grzybek, float pozycja_x, float pozycja_y);
    void animuj() override;
};

#endif // FRIENDLY_POSTAC_H
