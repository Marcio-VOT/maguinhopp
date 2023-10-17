#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
class Jogo
{
private:
    // Janela do Jogo
    RenderWindow window;
    // figura
    RectangleShape shape;
    Texture texture;
public:
    Jogo();
    ~Jogo();

    void Executar();
};

