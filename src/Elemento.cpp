#include "../ElementosGraficos/Elemento.h"

namespace ElementosGraficos {

    Gerenciadores::Gerenciador_Grafico* Elemento::pGG(Gerenciadores::Gerenciador_Grafico::get_instancia());

    Elemento::Elemento() {
        body = sf::RectangleShape(sf::Vector2f(0, 0));
    }

    Elemento::~Elemento() {
    }

    void Elemento::render() {
        pGG->desenhar(&body);
    }

}