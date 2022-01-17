#ifndef GRAVITY2D_HPP
#define GRAVITY2D_HPP

#include "utils.hpp"
#include "f_maths.hpp"
#include "body.hpp"
#include <list>

class Gravity2D { // meter aqui as herenças para a main window
    public:
        Gravity2D(const double& G);
        Gravity2D(const std::string& filename);
        void main_loop();

    private:
        // function to generate the acceleration vector
        std::vector<double> genA(const std::vector<double>& pos);
        // function to convert between vectors
        void VectoSF();
        void SFtoVec();

        double G; // gravitational constant
        // simulation variables (list em vez de vector pq quando quisermos fazer inserção/eliminação é mais eficiente)
        std::vector<Body> bodies;
        // de forma ao integrador simplético funcionar, temos de ter um vetor com todas as posições e velocidades e acelerações (ultimo para eficiencia)
        // as in, com dois corpos x = {x1,y1,x2,y2}; v = {vx1,vy1, vx2, vy2}; etc...
        std::vector<double> x, v, a;
};

#endif