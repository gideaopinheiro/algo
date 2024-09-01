#include "graph/graph.cpp"
#include <list>
#include <vector>

class MatrizAdjacencia {
public:
  MatrizAdjacencia(list<Vertice> vtcs);

private:
  vector<vector<int>> matriz;
  list<Vertice> vertices;
  int qtdVertices;
};

MatrizAdjacencia::MatrizAdjacencia(list<Vertice> vtcs) {
  vertices = vtcs;
  qtdVertices = vtcs.size();
  vector<vector<int>> m(qtdVertices, vector<int>(qtdVertices));
  matriz = m;
};
