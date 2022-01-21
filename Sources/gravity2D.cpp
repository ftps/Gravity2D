#include "gravity2D.hpp"
#include "f_maths.hpp"
#include <fstream>


Gravity2D::Gravity2D(const std::string& filename, const screen_atributes& screen)
: sf::RenderWindow(sf::VideoMode(screen.screen_width, screen.screen_height, screen.modeBitsPerPixel), "Gravity 2D")
{

    std::fstream fs;
    fs.open(filename, std::fstream::in);

    srand(time(0)); // Seeder for random color

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
    
    for (const std::vector<double>& v : MainVec){
        if(v.size() < 9){
            G = v.at(0);
            dt_max = v.at(1);
            dT = v.at(2);
            fps = v.at(3);
        }
        else bodies.emplace_back(v);
    }
    
    SFtoVec();
    calcNdt();
    a = genA(x);
    
    main_loop();
}

void Gravity2D::VectoSF()
{
    P = {0,0};

    for(uint i = 0; i < bodies.size(); ++i){
        bodies[i].x = {x[2*i], x[2*i+1]};
        bodies[i].v = {v[2*i], v[2*i+1]};
        bodies[i].bodyShape.setPosition(bodies[i].x.x - bodies[i].radius, bodies[i].x.y - bodies[i].radius);
    
        // Energy and momentum
        E += 0.5*bodies[i].mass*(bodies[i].v*bodies[i].v);
        P += bodies[i].v*bodies[i].mass;
    }
}

void Gravity2D::SFtoVec()
{
    x.resize(2*bodies.size());
    v.resize(2*bodies.size());

    for(uint i = 0; i < bodies.size(); ++i){
        x[2*i] = bodies[i].x.x;
        x[2*i+1] = bodies[i].x.y;
        v[2*i] = bodies[i].v.x;
        v[2*i+1] = bodies[i].v.y;
    }
}

void Gravity2D::calcNdt()
{
    double dtf = dT/fps;

    N = std::ceil(dtf/dt_max);
    dt = dtf/N;
}

std::vector<double> Gravity2D::genA(const std::vector<double>& pos)
{
    std::vector<double> a_res(pos.size(), 0);
    double aux;
    fm::Vector2D as;

    E = 0;

    for(uint i = 0; i < bodies.size(); ++i){
        for(uint j = i+1; j < bodies.size(); ++j){
            as = {pos[2*i] - pos[2*j], pos[2*i+1] - pos[2*j+1]};
            aux = fm::modV(as);
            E -= G*bodies[i].mass*bodies[j].mass/aux;
            aux = std::pow(aux, 3.0);
            as = as*(G/aux);
            a_res[2*i] -= as[0]*bodies[j].mass;
            a_res[2*i+1] -= as[1]*bodies[j].mass;
            a_res[2*j] += as[0]*bodies[i].mass;
            a_res[2*j+1] += as[1]*bodies[i].mass;
        }
    }

    return a_res;
}

void Gravity2D::moveWorld(const sf::Event& event, bool& dragging, sf::Vector2i& previous_mouse_position)
{
    
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        dragging = true;
    }
    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
    {
        dragging = false;
    }
    if (event.type == sf::Event::MouseMoved)
    {
        sf::Vector2i startPan = {event.mouseMove.x,event.mouseMove.y};

        if(dragging)
        {   
            sf::Vector2f delta = mapPixelToCoords(startPan) - mapPixelToCoords(previous_mouse_position);
                    
            // apply negatively to view
            sf::View view = getView();
            view.move(-delta);
            setView(view);     
        }

        // update previous mouse position
        previous_mouse_position = startPan;
    }

}

void Gravity2D::zoomWorld(const sf::Event& event)
{
    sf::View view;

    if (event.type == sf::Event::MouseWheelScrolled || (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Q || event.key.code == sf::Keyboard::A)))
    {
        if(event.mouseWheelScroll.delta > 0 || event.key.code == sf::Keyboard::Q)
        {
            view = getView();
            view.zoom(0.95f);
            setView(view);
        }
        else if(event.mouseWheelScroll.delta < 0 || event.key.code == sf::Keyboard::A)
        {
            view = getView();
            view.zoom(1.05f);
            setView(view);
        }
    }
}



void Gravity2D::main_loop()
{
    sf::Event event;
    bool dragging = false;
    sf::Vector2i previous_mouse_position;    


    setFramerateLimit(fps);

    while(isOpen()){
        // check all the window's events that were triggered since the last iteration of the loop
        while (pollEvent(event)){
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                close();
            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Escape)
                    close();
            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Q)
                    //close();
            if (event.type == sf::Event::Resized){
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                setView(sf::View(visibleArea));
            }
            moveWorld(event,dragging,previous_mouse_position);
            zoomWorld(event);
        }

        //Update stuff
        for(int i = 0; i < N; ++i){
            fm::ode::Leapfrog(x, v, [this](const std::vector<double>& x){ return this->genA(x); }, dt, a);
        }
        VectoSF();
        for(Body& b : bodies){
            b.tracer.update(b.bodyShape, 300);
        }
        std::cout << "Energy: " << E << "\n";
        std::cout << "Momentum: " << P << "\n" << std::endl;


        // clear the window with black color
        clear(sf::Color::Black);

        // draw everything here...
        for(Body& b : bodies){
            draw(b.tracer.getData(), b.tracer.getSize(), sf::PrimitiveType::LineStrip);
        }
        for(const Body& b : bodies){
            draw(b);
        }

        // end the current frame
        display();
    }
}