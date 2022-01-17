#include <tracer.hpp>
#include <SFML/Graphics.hpp>


void Tracer::update(const sf::Shape& shape, const size_t& maxTrailSize)
{

    sf::FloatRect shapeBounds;
    shapeBounds = shape.getGlobalBounds();

    vertexVector.push_back(sf::Vertex(sf::Vector2f(shape.getPosition().x + shapeBounds.width/2,shape.getPosition().y + shapeBounds.height/2), shape.getFillColor()));

    if(vertexVector.size() == maxTrailSize)
        vertexVector.erase(vertexVector.begin());

}

sf::Vertex* Tracer::getData() 
{ 
    return vertexVector.data(); 
}

size_t Tracer::getSize() 
{ 
    return vertexVector.size(); 
}