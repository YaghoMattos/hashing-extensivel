#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "Balde.h"


class Diretorio {
  private:
    //numero de baldes
    int numeroBaldes;
    //vetor de baldes
    vector<Balde*> diretorio;

    int tamanhoBalde;
    int dGlobal;
    int numeroChaves;

  public:
    Diretorio(int M);
    void insere(int k, int B);
    bool busca(string pseudo_chave);
    void divideBalde(string Nbits);
    void duplicaDiretorio();
    void imprimeDados();
    //funcao hash
    string h(int k, int Bits);
    //funcao converte string para decimal
    int binarioDecimal(string binario);
};
