#include "body.hpp"
#include <time.h>


Body::Body(const double& mass, const double& radius) : mass(mass), radius(radius)
{
    // Random color of body
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