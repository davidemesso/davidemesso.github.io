// g++ Game.cpp -lsfml-graphics -lsfml-window -lsfml-system
#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.hpp> 
#include "Entity.cpp"

using namespace sf;
using namespace std;

class Player : public Entity
{
public:
    // INHERITED ENTITY FIELDS 
    // Inventory inventory

    Player(string name, float life, float attack, string file) : Entity(name, life, attack, file)
    {
        // SOME PLAYER STUFF
    } 


    // For future custom drawing function
    // void draw(sf::RenderTarget &window, sf::RenderStates state) const 
    // {
    //     window.draw(sprite);
    // }

    // For future custom update function (every frame or tick)
    // void update()
    // {
        
    // } 
}; 