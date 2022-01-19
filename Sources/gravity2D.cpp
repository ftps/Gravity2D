#include "gravity2D.hpp"
#include "f_maths.hpp"
#include <fstream>

Gravity2D::Gravity2D(const double& G) : G(G) { }

std::vector<double> Gravity2D::genA(const std::vector<double>& pos)
{
    std::vector<double> a_res(pos.size(), 0);
    double aux;
    fm::Vector2D as;

    for(uint i = 0; i < bodies.size(); ++i){
        for(uint j = i+1; j < bodies.size(); ++i){
            as = {pos[2*i] - pos[2*j], pos[2*i+1] - pos[2*j+1]};
            aux = std::pow(fm::mod2V(as), 3.0/2.0);
            as = as*(G/aux);
            a_res[2*i] -= as[0]*bodies[i].mass;
            a_res[2*i+1] -= as[1]*bodies[i].mass;
            a_res[2*j] += as[0]*bodies[j].mass;
            a_res[2*j+1] += as[1]*bodies[j].mass;
        }
    }

    return a_res;
}

Gravity2D::Gravity2D(const std::string& filename)
{

    std::fstream fs;
    fs.open(filename, std::fstream::in);

    if(!fs.is_open())
        std::cout<<"Unable to open file"<<"\n";


    std::vector<std::vector<double>> MainVec;
	std::vector<double> SubVec;
	std::string sFileRow,sFileCell;
	double dFileCell;
	size_t commaPos;
    

    while (std::getline(fs, sFileRow)) // extract line
	{
        if (sFileRow.find('/') != std::string::npos)
        {
            continue;
        }

		while (!sFileRow.empty())
		{
			commaPos = sFileRow.find(",");

			if (commaPos != std::string::npos)				// Process the Line
			{
				sFileCell = sFileRow.substr(0, commaPos);
				sFileRow.erase(0, commaPos + 1);
				dFileCell = std::stod(sFileCell);
				SubVec.push_back(dFileCell);
			}
			else
			{												// Process end of line ,pass to main vector, clear variables for loop
				dFileCell = std::stod(sFileRow);
				SubVec.push_back(dFileCell);
				MainVec.push_back(SubVec);
				SubVec.clear();
				sFileRow.clear();
			}
		}
	}

    fs.close();
    
    for (size_t i = 0; i < MainVec.size(); i++)
        bodies.emplace_back(MainVec.at(i));
    
}

void Gravity2D::VectoSF()
{
    for(uint i = 0; i < bodies.size(); ++i){
        bodies[i].x = {x[2*i], x[2*i+1]};
        bodies[i].v = {v[2*i], v[2*i+1]};
    }
}

void Gravity2D::SFtoVec()
{
    for(uint i = 0; i < bodies.size(); ++i){
        x[2*i] = bodies[i].x.x;
        x[2*i+1] = bodies[i].x.y;
        v[2*i] = bodies[i].v.x;
        v[2*i+1] = bodies[i].v.y;
    }
}