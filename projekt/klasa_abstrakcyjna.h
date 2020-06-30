#ifndef KLASA_ABSTRAKCYJNA_H
#define KLASA_ABSTRAKCYJNA_H
#include <SFML/Graphics.hpp>

class klasa_abstrakcyjna : public sf::Sprite
{
public:
    klasa_abstrakcyjna();
    virtual void animuj() = 0;
    virtual ~klasa_abstrakcyjna() = default;
};

#endif // KLASA_ABSTRAKCYJNA_H
