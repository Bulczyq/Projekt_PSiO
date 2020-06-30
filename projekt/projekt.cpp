#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <Player.h>
#include <coin.h>
#include <platforma.h>
#include <memory>
#include <klasa_abstrakcyjna.h>
#include <Friendly_postac.h>
#include <serce.h>
#include <SFML/Audio.hpp>

int main()
{

//zmienne
    sf::Music winsound;
    winsound.openFromFile("victory.ogg");
    sf::Music crashsound;
    crashsound.openFromFile("crash.ogg");
    sf::Music coinsound;
    coinsound.openFromFile("coin_drop.ogg");
    sf::Clock zegar;
    sf::Time czas;
    sf::View camera1;
    bool porazka = false;
    bool wygrana = false;
    int kierunek_grzyb, kierunek_enemy;
    int punkty=0;
    int gra=1;

//okno
    sf::RenderWindow window(sf::VideoMode(800,600),"Podrobka Mario");
    window.setActive(true);
    window.setFramerateLimit(90);

//tekstury
    sf::Texture background;
    background.loadFromFile("teksturki/mario1x9.png");
    sf::Sprite bckgrnd;
    bckgrnd.setTexture(background);
    bckgrnd.setPosition(0,0);

    sf::Texture przegrana;
    przegrana.loadFromFile("teksturki/przegrana.png");
    sf::Sprite przgrn;
    przgrn.setTexture(przegrana);

    sf::Texture ekran_startowy;
    ekran_startowy.loadFromFile("teksturki/ekran_startowy.png");
    sf::Sprite ekran_start;
    ekran_start.setTexture(ekran_startowy);
    ekran_start.setPosition(0,0);

    sf::Texture serduszko;
    serduszko.loadFromFile("teksturki/serce.png");

    sf::Texture zwyciestwo;
    zwyciestwo.loadFromFile("teksturki/wygrana.png");
    sf::Sprite zwcstw;
    zwcstw.setTexture(zwyciestwo);

    sf::Texture gracz;
    gracz.loadFromFile("teksturki/gracz_stoi.png");

    sf::Texture gracz_bieg_lewo;
    gracz_bieg_lewo.loadFromFile("teksturki/gracz_w_biegu_lewo.png");

    sf::Texture gracz_bieg_prawo;
    gracz_bieg_prawo.loadFromFile("teksturki/gracz_w_biegu_prawo.png");

    sf::Texture gracz_w_skoku;
    gracz_w_skoku.loadFromFile("teksturki/gracz_w_skoku.png");

    sf::Texture platform;
    platform.loadFromFile("teksturki/platforma.png");

    sf::Texture coin;
    coin.loadFromFile("teksturki/Coin.png");

    sf::Texture grzybek;
    grzybek.loadFromFile("teksturki/grzybek.png");

    sf::Texture przeciwnik;
    przeciwnik.loadFromFile("teksturki/enemy.png");

//kontenery
    std::vector<std::unique_ptr<Coin>> pieniadze;
    std::vector<std::unique_ptr<platforma>> polki;
    std::vector<std::unique_ptr<Friendly_postac>> grzybki;
    std::vector<std::unique_ptr<Enemy>> enemy;
    std::vector<std::unique_ptr<Serce>> serca;

//tworzenie obiektow/////////////////////////////////////////////////////
    Player player(gracz);
    player.setPosition(32,425);

//tworzenie serduszek
    for(int i=0; i<3; i++){
        serca.emplace_back(std::make_unique<Serce>(serduszko, 0 + i*30, 0));
    }

//tworzenie półek
    for(int i=0; i<27; i++){
        polki.emplace_back(std::make_unique<platforma>(platform, 200+i*200, rand()%100+300));
    }

//tworzenie coinow
    for(unsigned int i=0; i<polki.size(); i++){
        pieniadze.emplace_back(std::make_unique<Coin>(coin, polki[i]->getGlobalBounds().left + (platform.getSize().x/4), polki[i]->getGlobalBounds().top - coin.getSize().y));
    }

//tworzenie grzybow
    for(int i=0; i<18; i++){
        grzybki.emplace_back(std::make_unique<Friendly_postac>(grzybek, rand()%6500+300, 533));
    }
//tworzenie przeciwnikow
    for(int i=0; i<18; i++){
        enemy.emplace_back(std::make_unique<Enemy>(przeciwnik, rand()%6000+400, rand()%300+200));
    }

    while (window.isOpen()) {
        sf::Event event;
        czas = zegar.getElapsedTime();
        for(unsigned int i=0; i<serca.size(); i++ ){
            serca[i]->ruszaj_sercem(player, i);
        }
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        if(gra==1){
            window.draw(ekran_start);
            window.display();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                gra=2;
            }
        }
        if(gra==2){
//kamera
        camera1.setSize(window.getSize().x,window.getSize().y);
        camera1.setCenter(player.getPosition().x + window.getSize().x/2, window.getSize().y/2);
//kolizja z coinami
        for(unsigned int i=0; i<pieniadze.size();){
            if(player.coin_collision(*pieniadze[i])){
                pieniadze.erase(pieniadze.begin() + i);
                punkty +=100;
                std::cout<<"Punkty: "<<punkty<<std::endl;
                coinsound.play();
            }
            else {i++;}
        }
//kolizja z grzybkami
        for(unsigned int i=0; i<grzybki.size();){
            if(player.grzyb_collision(*grzybki[i])){
                grzybki.erase(grzybki.begin() + i);
            }
            else{i++;}
        }
//kolizja z enemy
        for(unsigned int i=0; i<enemy.size();){
            if(player.enemy_collision(*enemy[i])){
                enemy.erase(enemy.begin() + i);
                serca.erase(serca.begin() +i);
                player.health_points -=1;
                std::cout<<"zycie: "<<player.health_points<<std::endl;
                crashsound.play();
            }
            else{i++;}
        }

//kolizja z polkami
        for(unsigned int i=0; i<polki.size();){
            if(player.polka_collision(*polki[i])){
               player.setPosition(polki[i]->getPosition().x, polki[i]->getPosition().y - player.getGlobalBounds().height);
            }
            else{i++;}
    }

//zwyciestwo i porazka
        if(player.health_points <= 0){
            porazka = true;
        }
        if(punkty == 2700){
            wygrana = true;
        }
//losowy ruch obiektów
        if(czas.asSeconds()>2){
            kierunek_grzyb = rand()%2;
            kierunek_enemy = rand()%2;
            zegar.restart();
        }
        for(unsigned int i=0; i<grzybki.size(); i++){
            grzybki[i]->move_grzybkiem(kierunek_grzyb);
        }
        for(unsigned int i=0; i<enemy.size(); i++){
            enemy[i]->move_enemy(kierunek_enemy);
        }
        player.stoi(gracz);
        player.run(gracz_bieg_lewo, gracz_bieg_prawo);
        player.jump(gracz_w_skoku);
        player.bounds_collision();

//rysowanie wszystkiego////////////////////////////////
        window.setView(camera1);
        window.draw(bckgrnd);
        for( auto &polka : polki){
            window.draw(*polka);
        }
        for( auto &coin : pieniadze){
            window.draw(*coin);
        }
        for( auto &grzybek : grzybki){
            window.draw(*grzybek);
        }
        for( auto &przeciwnik : enemy){
            window.draw(*przeciwnik);
        }
        for( auto &serce : serca){
            window.draw(*serce);
        }
        window.draw(player);
        if(porazka){
        przgrn.setPosition(player.getPosition().x, 0);
        window.draw(przgrn);
        }
        if(wygrana){
        winsound.play();
        zwcstw.setPosition(player.getPosition().x, 0);
        window.draw(zwcstw);
        }
        window.display();
        }
    }
    return 0;
}
