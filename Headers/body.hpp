#ifndef BODY_HPP
#define BODY_HPP

#include <vector>
#include <SFML/Graphics.hpp>

class Body : public sf::Drawable, public sf::Transformable{
    public:
        Body(); // dps temos de pôr o constructor a receber coisas ou fazer múltiplos
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; // funçao para puder usar o window.draw() no main

    private:
        // Physics variables
        double mass;
        double radius;

        sf::Vector2f x; // position
        sf::Vector2f v; // velocity
        

        // Drawing variables
        sf::CircleShape bodyShape;
};


#endif