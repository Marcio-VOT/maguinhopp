class Ente
{
protected:
  int id;
  static int contador;

public:
  Ente();
  ~Ente();
  virtual void executar() = 0;
  void desenhar();
  virtual void salvar() = 0;
};

int ::Ente::contador = 0;
