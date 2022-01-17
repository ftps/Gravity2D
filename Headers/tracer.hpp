#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Tracer
{
private:

    std::vector<sf::Vertex> vertexVector; 

public:

    void update(const sf::Shape& shape,const size_t& maxTrailSize, const size_t& dt);
    sf::Vertex* getData();
    size_t getSize(); 


};



