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

        double G, dt_max, dt, dT;
        int N, fps;
        // simulation variables (list em vez de vector pq quando quisermos fazer inserção/eliminação é mais eficiente)
        std::vector<Body> bodies;
        // de forma ao integrador simplético funcionar, temos de ter um vetor com todas as posições e velocidades e acelerações (ultimo para eficiencia)
        // as in, com dois corpos x = {x1,y1,x2,y2}; v = {vx1,vy1, vx2, vy2}; etc...
        std::vector<double> x, v, a;

        void moveWorld(const sf::Event& event, bool& dragging,sf::Vector2i& previous_mouse_position);
        void zoomWorld(const sf::Event& event);

};

#endif