#ifndef TRACER.HPP
#define TRACER.HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Tracer
{
public:

    void update(const sf::Shape& shape,const size_t& maxTrailSize, const size_t& dt);
    sf::Vertex* getData();
    size_t getSize(); 

private:

    std::vector<sf::Vertex> vertexVector; 



};

#endif

