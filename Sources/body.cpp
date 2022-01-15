#include "body.hpp"



body::body()
{

    // Random color of body
    sf::Color color(rand() % 255 + 1,rand() % 255 + 1,rand() % 255 + 1, 255);
    bodyShape.setFillColor(color);




}