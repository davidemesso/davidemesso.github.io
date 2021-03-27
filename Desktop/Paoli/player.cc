#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Player {

    private:
        Texture texture;
        int frame = 0;

        void animate(){
            frame = (frame+1)%3;
            int x=0, y=0;
            if (dx == dy || dx == -dy){
                if (dx == 0){
                    frame = 0;
                    y = (lx+1)/2;
                } 
                else {
                    x = 1;
                    y = (1 == dx);
                }
            } else if (dy == 0){
                x = 1;
                if (dx == -1) y=0;
                else if (dx == 1) y=1;
            } else if (dx == 0){
                x = 7;
                if (dy == 1) y = 0;
                else if (dy == -1) y = 1;
            }
            if (cick){
                sprite.setTextureRect(IntRect((9)*48, (2+((lx+1)/2))*48, 48, 48));
                cick--;
            } else
                sprite.setTextureRect(IntRect((x+frame)*48, y*48, 48, 48));
        }

    public:
        Sprite sprite;
        int dx = 0;
        int dy = 0;
        int lx = -1;
        int speed = 5;
        int cick = 0;

        void load(int x, int y, char img){
            animate();
            char path[] = "img/character/1.png";
            path[14] = img;
            if (!texture.loadFromFile(path));
                texture.setSmooth(true);
            sprite.setTexture(texture);
            sprite.setScale(Vector2f(2, 2));
            sprite.setPosition(Vector2f(x, y));
        }

        float t = 0;
        void update(float dt){
            t += dt;
            if (t > 0.1){
                
                animate();
                t = 0;
                if (dx != 0)
                    lx = dx;
            }
            sprite.move(dx*speed, dy*speed);
        }

        void action(){
            cick = 1;
        }

};
