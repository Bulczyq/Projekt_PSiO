#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include <klasa_abstrakcyjna.h>

class Enemy : public klasa_abstrakcyjna
{
public:
    Enemy(sf::Texture &tekstura_enemy, float pozycja_x, float pozycja_y);
    void move_enemy(int &liczba2);
    void animuj() override;
};

#endif // ENEMY_H
