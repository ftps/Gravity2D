#ifndef BODY_HPP
#define BODY_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "tracer.hpp"

class Body : public sf::Drawable, public sf::Transformable{
    public:
        Body(const double& mass, const double& radius); // dps temos de pôr o constructor a receber coisas ou fazer múltiplos
        Body(const double& mass, const double& radius, const sf::Vector2<double> x, sf::Vector2<double> v);
        Body(const std::vector<double>& dataVec);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; // funçao para puder usar o window.draw() no main

    public:
        // Physics variables
        const double mass;
        const double radius;

        sf::Vector2<double> x; // position
        sf::Vector2<double> v; // velocity
        

        // Drawing variables
        sf::CircleShape bodyShape;
        Tracer tracer;
};


#endif