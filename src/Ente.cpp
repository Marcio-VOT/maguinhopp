#include "Ente.h"
#include <iostream>

using namespace std;

Ente::Ente(const IDs::IDs ID)
    : id(ID)
{
}

Ente::~Ente()
{
}

const IDs::IDs Ente::getID() const
{
  return id;
}

const std::string Ente::salvarEnte()
{
  return std::to_string(static_cast<int>(id)) + ' ';
}
