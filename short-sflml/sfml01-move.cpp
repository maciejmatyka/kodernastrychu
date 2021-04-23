#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

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