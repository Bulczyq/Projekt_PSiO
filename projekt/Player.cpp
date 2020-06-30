#include <iostream>
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <coin.h>
#include <Friendly_postac.h>
#include <Enemy.h>
#include <platforma.h>
Player::Player(sf::Texture &text)
{
    setTexture(text);
}

void Player::run(sf::Texture &text1, sf::Texture &text2){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    velocity_x = -2;
    velocity_y = 0;
    move(velocity_x,velocity_y);
    setTexture(text1);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
    velocity_x = 2;
    velocity_y = 0;
    move(velocity_x ,velocity_y);
    setTexture(text2);
    }
}
bool Player::polka_collision(platforma &poleczka){
    if(getGlobalBounds().top + getGlobalBounds().height == poleczka.getGlobalBounds().top && getGlobalBounds().left == poleczka.getGlobalBounds().left){
        return true;
    }
    else return false;
}

void Player::jump(sf::Texture &text3){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
    move(0, -10);
    setTexture(text3);
    }
    if(getPosition().y < 425){
       move(0, 5);
    }
}
void Player::bounds_collision(){
    if(getPosition().y <=0){
        setPosition(32,425);
    }
}
void Player::change_camera(sf::View &camera){
    if(getPosition().x <800){
        camera.setCenter(400,300);
    }
    if(getPosition().x >=800 && getPosition().x <= 1600){
        camera.move(800,0);
    }
}
void Player::stoi(sf::Texture &text4){
    if(getPosition().y >= 425){
        setTexture(text4);
    }

}
bool Player::coin_collision(Coin &coin){
    if(getGlobalBounds().intersects(coin.getGlobalBounds())){
        return true;
    }
    else return false;
}
bool Player::grzyb_collision(Friendly_postac &grzyb){
    if(getGlobalBounds().intersects(grzyb.getGlobalBounds())){
        return true;
    }
    else return false;
}
bool Player::enemy_collision(Enemy &enemy){
    if(getGlobalBounds().intersects(enemy.getGlobalBounds())){
        return true;
    }
    else return false;
}
/*bool Player::polka_collision(platforma &poleczka){
    if(getGlobalBounds().top + getGlobalBounds().height == poleczka.getGlobalBounds().top && getGlobalBounds().left == poleczka.getGlobalBounds().left){
        return true;
    }
    else return false;
}*/
void Player::animuj(){}
