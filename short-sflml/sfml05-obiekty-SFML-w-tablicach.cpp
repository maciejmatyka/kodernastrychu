#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
const int R = 30;
const int W = 600;
const int H = 600;
const int N = 40;
sf::CircleShape naszekolka[N];

//przesun(4.1, 0, shape);
void przesun(float PX, float PY, sf::CircleShape &obiektdoprzes ) 
{
    // przesuniecie
    obiektdoprzes.move(PX,PY);
    if(obiektdoprzes.getPosition().x > W) 
        obiektdoprzes.setPosition( 0,obiektdoprzes.getPosition().y );
}

void init()
{
    for(int i=0; i<N; i++)
    {
        naszekolka[i] = sf::CircleShape(R*(rand()/(float)RAND_MAX));
        naszekolka[i].setPosition(  W/2+W/2*(rand()/(float)RAND_MAX-0.5),
                                    H/2+H/2*(rand()/(float)RAND_MAX-0.5));
        naszekolka[i].setFillColor(sf::Color::Green);
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(W, H), "SFML works!");
    //sf::CircleShape shape(R);
    init();
    //shape.setPosition(W/2-R, H/2-R);
    //shape.setFillColor(sf::Color::Green);

    sf::Clock zegar;
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        sf::Time czas = zegar.restart();
        std::cout << (1.0/czas.asSeconds()) << " FPS " << std::endl;

        for(int i=0; i<N; i++)
            przesun(4.1, 0, naszekolka[i]); 

        
        // spr myszy
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        for(int i=0; i<N; i++)
        {
            int px = naszekolka[i].getPosition().x + R/2;
            int py = naszekolka[i].getPosition().y + R/2; 
            int mx = sf::Mouse::getPosition(window).x;
            int my = sf::Mouse::getPosition(window).y;

            if( (px-mx)*(px-mx) + (py-my)*(py-my) < R*R )
            {
                std::cout << px << " " << py << " , " << mx << " " << my << std::endl;
            }
            //else
            //    std::cout << "nie trafiles" << std::endl;

        }
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for(int i=0; i<N; i++)
            window.draw(naszekolka[i]);
        window.display();
    }
    return 0;
}