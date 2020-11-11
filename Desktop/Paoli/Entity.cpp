#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.hpp> 
#include "AnimatedSprite.cpp"

using namespace sf;
using namespace std;

class Entity : public AnimatedSprite
{
public:
    string name; 
    float atk; 
    float life;
    Sprite sprite;

    Entity(string name, float life, float attack, string file) : AnimatedSprite(file)
    {
        this->name = name; 
        this->life = life; 
        this->atk  = atk; 
    } 

    // For future custom update function (every frame or tick)
    // void update()
    // {
        
    // } 
}; 