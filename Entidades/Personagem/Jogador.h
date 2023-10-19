#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
class Jogador
{
private:
    RectangleShape body;
    Vector2f vel;
    void inicializa();
public:
    Jogador(const Vector2f pos, const Vector2f tam);
    Jogador(const RectangleShape body);
    ~Jogador();

    const RectangleShape getBody();
    void move();
};

