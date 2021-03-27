#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.cc"
#include "tutorial.cc"

#define WIDTH 960
#define HEIGHT 640
#define TITLE "Carcadia"

// g++ main.cc -lsfml-graphics -lsfml-window -lsfml-system

using namespace sf;
using namespace std;

RenderWindow window(VideoMode(WIDTH, HEIGHT), TITLE);;

Event event;
Player player[2];
Tutorial tutorial;
Clock c;
float dt;

void _load(){

    for (int i=0; i<2; i++){
        player[i] = Player();
        player[i].load(100*i, 39,'1'+i);
    }
    tutorial.load();
}

void _event(){
    while (window.pollEvent(event)){        
        switch (event.type) {
            // QUIT
            case Event::Closed:{
                window.close();
                break;
            }
            // KEYPRESSED
            case Event::KeyPressed:{
                switch (event.key.code) {
                    // Escape
                    case  Keyboard::Escape:
                        window.close(); break;
                    // Arrow
                    case Keyboard::Up:
                        player[0].dy = -1; break;
                    case Keyboard::Down:
                        player[0].dy = 1; break;
                    case Keyboard::Left:
                        player[0].dx = -1; break;
                    case Keyboard::Right:
                        player[0].dx = 1; break;
                    // Space
                    case Keyboard::Space:
                        player[0].action();
                }
                break;
            }
            // KEYRELEASED
            case Event::KeyReleased:{
                switch (event.key.code) {
                    // Arrow
                    case Keyboard::Up:
                    case Keyboard::Down:
                        player[0].dy = 0; break;
                    case Keyboard::Left:
                    case Keyboard::Right:
                        player[0].dx = 0; break;
                }
                break;
            }
        }
    }
}

void _update(float dt){
    for (int i=0; i<2; i++)
        player[i].update(dt);
}

void _draw(){
    window.clear();
    for (int i=1; i>=0; i--)
        window.draw(player[i].sprite);
    window.draw(tutorial.sprite);
    window.display();
}

int main(int argc, char** argv){
    _load();
    while (window.isOpen()){
        if (c.getElapsedTime().asSeconds() >= 1.0f / 60){
            dt = c.getElapsedTime().asSeconds();
            c.restart();
        } else continue;
        _event();
        _update(dt);
        _draw();
    }
    return 0;
}
