#include <iostream>
#include <string>

using namespace std;

class Balde
{
  private:
    //tamanho do balde M
    int M;
    //vetor para representar o balde
    string* balde;
    //dimensão do balde
    int dLocal;

  public:
    Balde(int M);
    ~Balde();
    void setdLocal(int dGlobal);
    int getdLocal();
    void insereChave(string pseudo_chave);
    bool baldeCheio();
    void setChave(string pseudo_chave, int indice);
    string getChave(int indice);
};
