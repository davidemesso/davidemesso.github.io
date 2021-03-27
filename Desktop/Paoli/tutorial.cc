#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Tutorial {
    private:
        Texture texture;

    public:
        Sprite sprite;
        
        void load(){
            if (!texture.loadFromFile("img/arrows.png"));
                texture.setSmooth(true);
            sprite.setTexture(texture);
            sprite.setScale(Vector2f(.5f, .5f));

            sprite.setPosition(Vector2f(0, 400));

        }
};
