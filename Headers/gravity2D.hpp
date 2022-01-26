#ifndef GRAVITY2D_HPP
#define GRAVITY2D_HPP

#include "utils.hpp"
#include "body.hpp"
#include <list>

struct screen_atributes
{
    size_t screen_height = 800;
    size_t screen_width = 800;
    size_t modeBitsPerPixel = 32;

    //screen_atributes(size_t width, size_t height):
    //    screen_height(height), screen_width(width) {};

};

class Gravity2D : sf::RenderWindow { // meter aqui as herenças para a main window
    public:
        Gravity2D(const std::string& filename, const screen_atributes& screen = {});

    private:
        void main_loop();
        // function to generate the acceleration vector
        std::vector<double> genA(const std::vector<double>& pos);
        // function to convert between vectors
        void VectoSF();
        void SFtoVec();
        void calcNdt();

        // simulation parameters
        double G, dt_max, dt, dT;
        int N, fps;

        // energy and momentum
        double E;
        sf::Vector2<double> P;

        // vector with all bodies
        std::vector<Body> bodies;
        // de forma ao integrador simplético funcionar, temos de ter um vetor com todas as posições e velocidades e acelerações (ultimo para eficiencia)
        // as in, com dois corpos x = {x1,y1,x2,y2}; v = {vx1,vy1, vx2, vy2}; etc...
        std::vector<double> x, v, a;

        // pan and zoom
        void moveWorld(const sf::Event& event, bool& dragging,sf::Vector2i& previous_mouse_position);
        void zoomWorld(const sf::Event& event);
        void speedWorld(const sf::Event& event);

        // collision detection
        void simpleCol();
        void collideElastic(Body& l, Body& r);

};

template<typename T>
T operator*(const sf::Vector2<T>& l, const sf::Vector2<T>& r)
{
    return l.x*r.x + l.y*r.y;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const sf::Vector2<T>& r)
{
    os << "[ " << r.x << " " << r.y << " ]";
    return os;
}

#endif