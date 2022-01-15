#ifndef BODY_HPP
#define BODY_HPP

#include <vector>
#include <SFML/Graphics.hpp>

class Body{
    public:
        Body();
    private:
        // Physics variables
        double mass;
        double radius;
        

        // Drawing variables
        sf::CircleShape bodyShape;
};


#endif