#include "body.hpp"
#include <time.h>


Body::Body()
{
    // Random color of body --> Tem um erro, está sempre a far as mesmas cores para corpos diferentes. Será o codigo demasiado rapido para a seed??
    srand(time(0));
    sf::Color color(rand() % 256,rand() % 256,rand() % 256, 255);
    bodyShape.setFillColor(color);


    // Set body graphical atributes
    bodyShape.setRadius(radius);
    bodyShape.setPointCount(radius * 30);

}

void Body::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // apply the transform
    states.transform *= getTransform();

    // Apply Textures
    states.texture = NULL;

    // Draw the things
    target.draw(bodyShape, states);

}