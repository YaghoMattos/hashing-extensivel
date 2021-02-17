#include "Balde.h"

using namespace std;

Balde::Balde(int M)
{
  this->M = M;
  balde = new string[this->M];
  dLocal = 0;
}

Balde::~Balde()
{
  delete [] balde;
}

int Balde::getdLocal() {
  return dLocal;
}

void Balde::setdLocal(int dGlobal) {
  dLocal = dGlobal;
}

void Balde::insereChave(string pseudo_chave)
{
  for(int i = 0;  i < M; i++)
  {
    if(balde[i].empty()) {
      balde[i] = pseudo_chave;
      break;
    }
  }
}

bool Balde::baldeCheio()
{
  for(int i = 0;  i < M; i++)
  {
    if(balde[i].empty())
      return false;
  }
  return true;
}

void Balde::setChave(string pseudo_chave, int indice) {
  balde[indice] = pseudo_chave;
}

string Balde::getChave(int indice) {
  return balde[indice];
}