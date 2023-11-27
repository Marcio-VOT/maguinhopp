/*
    CÓDIGO FORTEMENTE INSPIRADO NO CÓDIGO DO TUTOR Matheus Burda - https://github.com/MatheusBurda
    CÓDIGO ORIGINAL: https://github.com/MatheusBurda/Desert
    CÓDIGO FORTEMENTE INSPIRADO NO CÓDIGO DOS TUTORES  "Os petequeiros Jean e Murilo" - https://github.com/Nixxye -  https://utfpr.curitiba.br/peteco/
    Canal: https://www.youtube.com/@PETECOUTFPR
    CÓDIGO ORIGINAL: https://github.com/Nixxye/peteco-tegprog
*/
#pragma once

#include <list>
#include <SFML/Graphics.hpp>
#include <string>
#include <map>

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

        std::string getKeyComoString(sf::Keyboard::Key key);
    };

} // namespace Managers