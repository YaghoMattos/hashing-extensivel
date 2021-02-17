#include "Diretorio.h"

Diretorio::Diretorio(int M) {
  dGlobal = 1;
  tamanhoBalde = M;
  Balde* balde1 = new Balde(M);
  //insere balde1 nas posição 0 e 1 do diretorio
  diretorio.push_back(balde1);
  diretorio.push_back(balde1);
  numeroBaldes = 1;
  numeroChaves = 0;
}

void Diretorio::insere(int k, int B) {
  if(dGlobal < B) {
    string pseudoChave = h(k, B);
    string Nbits = pseudoChave.substr(0, dGlobal);

    int indiceBalde = binarioDecimal(Nbits);
    Balde* balde = diretorio[indiceBalde];

    //insere no balde
    if(!balde->baldeCheio() && !busca(pseudoChave)) {
      balde->insereChave(pseudoChave);
      numeroChaves++;
    }
    else {
      divideBalde(Nbits);
      //insere em bd0
      if(diretorio[indiceBalde]->baldeCheio() && !busca(pseudoChave)) {
        balde->insereChave(pseudoChave);
        numeroChaves++;
      }
      else {
        //insere em bd1
        if(!busca(pseudoChave)) {
          diretorio[indiceBalde]->insereChave(pseudoChave);
          numeroChaves++;
        }
      }
      if(balde->getdLocal() >= dGlobal) {
        duplicaDiretorio();
      }
    }
  }
}    

//encontra balde baseado nos N primeiros bits e procura chave no balde
bool Diretorio::busca(string Nbits)
{
  //encontra balde
  int indiceBalde = binarioDecimal(Nbits.substr(0, dGlobal));
  Balde* balde = diretorio[indiceBalde];
  //procura chave no balde
  for(int i = 0; i < tamanhoBalde; i++) {
    if(balde->getChave(i) == Nbits)
      return true;
  }    
  return false;
}

void Diretorio::divideBalde(string Nbits) {
  //indice do balde no diretorio
  int indiceBalde = binarioDecimal(Nbits);
  //baldes
  Balde* bd0 = diretorio[indiceBalde];
  Balde* bd1 = new Balde(tamanhoBalde);
  diretorio[indiceBalde] = bd1;
  numeroBaldes++;
  //incrementa d local
  bd0->setdLocal(bd0->getdLocal() + 1);
  bd1->setdLocal(bd0->getdLocal() + 1);
  //divide registros entre bd0 e bd1
  for(int i = 0; i < tamanhoBalde; i++) {
    string pseudoChave = bd0->getChave(i);
    if(Nbits == pseudoChave.substr(0, bd0->getdLocal())){
      //set bd0 com null
      bd0->setChave("", i);
      bd1->insereChave(pseudoChave);
    }
  }
}

void Diretorio::duplicaDiretorio() {
  //aumenta profundidade global
  dGlobal++;

  //duplica o diretorio, preenchendo com null
  int max = pow(2, dGlobal);
  for(int i = 0; i < max; i++) {
    diretorio.push_back(NULL);
  }
  //preenche a segunda metade do diretorio
  max--;
  int aux = max;
  for(int i = 0; i < max; i++) {
    diretorio[aux] = diretorio[aux/2];
    aux--;
  }
}

void Diretorio::imprimeDados() {
  cout << "Numero de chaves: " << numeroChaves << endl;
  cout << "Profundidade global: " << dGlobal << endl;
  cout << "Tamanho do diretorio: " << (int)pow(2, dGlobal) << endl;
  cout << "Fator de carga: " << (float)numeroChaves/(numeroBaldes*tamanhoBalde) << endl;
}

//converte binario pra decimal
int Diretorio::binarioDecimal(string binario) {
  int decimal = 0, tam = 0;
  tam = binario.size();

  for(int i = 0; i < binario.size(); i++) {
    if(binario.at(i) == '1')
      decimal += pow(2, tam-1);
      tam--;
  }
  return decimal;
}

//função hash
string Diretorio::h(int k, int B) {
  string binario;

  while (k != 0){
    binario += (k % 2 == 0 ? "0" : "1");
    k = k / 2;
  }
  //zeros para preencher k binario ate o numero restante de bits
  string pseudoChave = "";
  for(int j = binario.size() ; j < B; j++) {
    pseudoChave.append( 1, '0');
  }

  pseudoChave.append(binario);
  return pseudoChave;
}
