#ifndef BODY_HPP
#define BODY_HPP

#include <vector>
#include <SFML/Graphics.hpp>

class Body : public sf::Drawable, public sf::Transformable{     // Ele tem de ter estas heranças senão não dá pra brincar com o corpo graficamente aka metodos como setPosition, setRotation etc. Apaga o comentario depois de ler se quiseres.
    public:
        Body();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; // funçao para puder usar o window.draw() no main

    private:
        // Physics variables
        double mass;
        double radius;
        

        // Drawing variables
        sf::CircleShape bodyShape;
};


#endif