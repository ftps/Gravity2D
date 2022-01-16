#ifndef GRAVITY2D_HPP
#define GRAVITY2D_HPP

#include "utils.hpp"
#include "f_maths.hpp"
#include "body.hpp"
#include <list>

class Gravity2D { // meter aqui as herenças para a main window
    public:
        Gravity2D();

    private:


        // simulation variables (list em vez de vector pq quando quisermos fazer inserção/eliminação é mais eficiente)
        std::list<Body> bodies;
        // de forma ao integrador simplético funcionar, temos de ter um vetor com todas as posições e velocidades e acelerações (ultimo para eficiencia)
        // as in, com dois corpos x = {x1,y1,x2,y2}; v = {vx1,vy1, vx2, vy2}; etc...
        std::vector<double> x, v, a;
};

#endif