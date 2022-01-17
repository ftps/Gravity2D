#ifndef TRACER_HPP
#define TRACER_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Tracer
{
public:

    void update(const sf::Shape& shape,const size_t& maxTrailSize);
    sf::Vertex* getData();
    size_t getSize(); 

private:
    //sf::Vector2f
    std::vector<sf::Vertex> vertexVector; 



};

#endif

