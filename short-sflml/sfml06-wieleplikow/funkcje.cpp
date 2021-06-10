
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "stale.h"

//przesun(4.1, 0, shape);
void przesun(float PX, float PY, sf::CircleShape &obiektdoprzes ) 
{
    // przesuniecie
    obiektdoprzes.move(PX,PY);
    if(obiektdoprzes.getPosition().x > W) 
        obiektdoprzes.setPosition(0,H/2-R);
}
