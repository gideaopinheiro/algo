#include <iostream>
#include <stdexcept>
using namespace std;

class Vertice {
public:
  Vertice(string rotulo);
  string getRotulo();

private:
  string rotulo;
  int grau;
};

Vertice::Vertice(string rtl) {
  if (rtl.size() == 0) {
    throw invalid_argument("O rotulo não pode ser uma string vazia");
  }
  rotulo = rtl;
};

string Vertice::getRotulo() { return rotulo; }
