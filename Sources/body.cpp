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

Body::Body(const double& mass, const double& radius, const sf::Vector2<double> x, sf::Vector2<double> v) : mass(mass), radius(radius), x(x), v(v)
{
    
    // Random color of body
    sf::Color color(rand() % 256,rand() % 256,rand() % 256, 255);
    bodyShape.setFillColor(color);


    // Set body graphical atributes
    bodyShape.setRadius(radius);
    bodyShape.setPointCount(radius * 30);
}

Body::Body(const std::vector<double>& dataVec) : mass(dataVec.at(0)), radius(dataVec.at(1))
{
    // Body Color
    sf::Color color(dataVec.at(6),dataVec.at(7),dataVec.at(8));
    bodyShape.setFillColor(color);

    // Position and Velocity atributes
    x.x = dataVec.at(2);
    x.y = dataVec.at(3);
    bodyShape.setPosition(x.x,x.y);

    v.x = dataVec.at(4);
    v.y = dataVec.at(5);

    
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