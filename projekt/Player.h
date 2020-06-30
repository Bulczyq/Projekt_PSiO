#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <klasa_abstrakcyjna.h>
#include <coin.h>
#include <Friendly_postac.h>
#include <Enemy.h>
#include <platforma.h>
class Player : public klasa_abstrakcyjna
{
public:
    int health_points = 3;
    float velocity_x;
    float velocity_y;
    void animuj() override;
    void stoi(sf::Texture &text4);
    bool polka_collision(platforma &poleczka);
    void jump(sf::Texture &text3);
    void run(sf::Texture &text1, sf::Texture &text2);
    void bounds_collision();
    bool coin_collision(Coin &coin);
    bool grzyb_collision(Friendly_postac &grzyb);
    bool enemy_collision(Enemy &enemy);

    void change_camera(sf::View &camera);
    void win();
    void lose();
    Player(sf::Texture &text);
};

#endif // PLAYER_H
