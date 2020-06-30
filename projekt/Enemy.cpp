#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <iostream>
Enemy::Enemy(sf::Texture &tekstura_enemy, float pozycja_x, float pozycja_y)
{
    setTexture(tekstura_enemy);
    setPosition(pozycja_x, pozycja_y);
}
void Enemy::move_enemy(int &liczba2){
    if(liczba2 == 0){
        move(-0.5, 0);
    }
    if(liczba2 == 1){
        move(0.5, 0);
    }
}
void Enemy::animuj(){}
