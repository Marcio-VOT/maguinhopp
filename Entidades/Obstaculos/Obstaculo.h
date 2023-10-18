#include "Entidade.h"

class Obstaculo : public Entidade
{
protected:
  bool danoso;

public:
  Obstaculo(const bool d = false);
  ~Obstaculo();
  virtual void executar() = 0;
  virtual void obstacular() = 0;
  const bool get_danoso() const;
  bool set_danoso(const bool d);
};
