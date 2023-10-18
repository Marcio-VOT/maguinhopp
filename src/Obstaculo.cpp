#include "Obstaculo.h"

Obstaculo::Obstaculo(const bool d = false) : Entidade()
{
  danoso = d;
}

Obstaculo::~Obstaculo()
{
}

const bool Obstaculo::get_danoso() const
{
  return danoso;
}

bool Obstaculo::set_danoso(const bool d)
{
  danoso = d;
}
