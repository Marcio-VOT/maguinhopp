#pragma once

#include <list>
#include <map>
#include <SFML/Graphics.hpp>
#include <string>

namespace Controladores {
    class Observer;
} // namespace Control

namespace Gerenciadores {

    class Entrada {
    private:
        std::list<Controladores::Observer*> observers;
        std::list<Controladores::Observer*>::iterator it;
        std::map<sf::Keyboard::Key, std::string> keyMap;
        static Entrada* Instancia;

        Entrada();

    public:
        ~Entrada();

        static Entrada* getInstancia();

        void Anexar(Controladores::Observer* pObserver);

        void Desanexar(Controladores::Observer* pObserver);

        void handleKeyPressed(sf::Keyboard::Key key);

        void handleKeyReleased(sf::Keyboard::Key key);

        std::string getKeyasString(sf::Keyboard::Key key);
    };

} // namespace Managers