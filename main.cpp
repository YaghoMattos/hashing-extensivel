#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Diretorio.h"

using namespace std;

void testeA(Diretorio& diretorio, int N, int B) {
  //gerando N pseudo-chaves aleatórias por meio de números aleatórios para inserção
  int k;

  cout << endl << "Teste para N pseudo-chaves aleatorias" << endl;

  for(int i = 0; i < N; i++) {
    //N pseudo-chaves aleatórias com até tal número de Bits
    k = rand()%(int)pow(2, B);

    diretorio.insere(k, B);
  }
  diretorio.imprimeDados();

}

void testeB(Diretorio& diretorio, int N, int B) {
  //gerando N pseudo-chaves aleatórias por meio de números aleatórios para inserção
  int k;

  cout << endl << "Teste para N pseudo-chaves iniciadas com mesmo padrao de bits" << endl;

  for(int i = 0; i < N; i++) {
    //N pseudo-chaves aleatórias com até tal número de Bits
    /*forca as chaves a iniciarem com o mesmo padrao de bits,
    primeira metade dos bits com 0*/
    k = rand()%(int)pow(2, B/2);

    diretorio.insere(k, B);
  }
  diretorio.imprimeDados();
}

int main(int argc, char** argv)
{
  srand(time(NULL));
  int M = 0, B = 0;

  cout << "Digite o tamanho M dos baldes: ";
  cin >> M;
  cout << "Digite o numero de Bits das pseudo-chaves: ";
  cin >> B;

  //cria diretorios para teste
  Diretorio diretorio01(M);
  Diretorio diretorio02(M);

  //valor de N
  int N = 20;
  cout << "N aleatorio: " << N << endl;

  testeA(diretorio01, N, B);
  testeB(diretorio02, N, B);

  return 0;
}
