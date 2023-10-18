#include "Ente.h"
#include <iostream>

using namespace std;

Ente::Ente()
{
  id = ++contador;
}

Ente::~Ente()
{
}

void Ente::desenhar()
{
  cout << "Desenhando Ente" << endl;
}
