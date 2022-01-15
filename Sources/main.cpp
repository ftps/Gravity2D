#include <iostream>
#include <body.hpp>

struct screen_atributes
{
    size_t screen_height;
    size_t screen_width;
    size_t modeBitsPerPixel = 32;

    screen_atributes(size_t width, size_t height):
        screen_height(height), screen_width(width) {};

};

int main(int argc, char* argv[])
{
    std::cout << "Hello Cringelord" << std::endl;

    // Codigo da janela. Descomentar para abrir a janela.

    // screen_atributes screen(800,800);
    // sf::RenderWindow window(sf::VideoMode(screen.screen_width,screen.screen_height,screen.modeBitsPerPixel), "Gravity2D");

    // while (window.isOpen()){
    //     // check all the window's events that were triggered since the last iteration of the loop
    //     sf::Event event;
    //     while (window.pollEvent(event)){

    //         // "close requested" event: we close the window
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //         if (event.type == sf::Event::KeyPressed)
    //             if (event.key.code == sf::Keyboard::Escape)
    //                 window.close();
    //         if (event.type == sf::Event::Resized){
    //             // update the view to the new size of the window
    //             sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
    //             window.setView(sf::View(visibleArea));
    //         }
            
    //     }

    //     //Update stuff





    
    //     // clear the window with black color
    //     window.clear(sf::Color::Black);

    //     // draw everything here...


    //     // end the current frame
    //     window.display();
    // }

    return 0;
}