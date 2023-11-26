#include "../ElementosGraficos/Elemento.h"

namespace ElementosGraficos {
    
    Elemento::Elemento(): body(), pGG(Gerenciadores::Gerenciador_Grafico::get_instancia()) {
        body = sf::RectangleShape(sf::Vector2f(0, 0));
    }

    Elemento::~Elemento() {
    }

    void Elemento::render() {
        pGG->desenhar(&body);
    }

}