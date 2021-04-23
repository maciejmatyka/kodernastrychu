#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
const int R = 30;
const int W = 600;
const int H = 600;

int main()
{
    sf::RenderWindow window(sf::VideoMode(W, H), "SFML works!");
    sf::CircleShape shape(R);
    shape.setPosition(W/2-R, H/2-R);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        shape.move(0.1,0);
        
        // spr myszy
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            int px = shape.getPosition().x + R/2;
            int py = shape.getPosition().y + R/2; 
            int mx = sf::Mouse::getPosition(window).x;
            int my = sf::Mouse::getPosition(window).y;

            if( (px-mx)*(px-mx) + (py-my)*(py-my) < R*R )
            {
                std::cout << px << " " << py << " , " << mx << " " << my << std::endl;
            }
            else
                std::cout << "nie trafiłeś" << std::endl;

        }
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
}