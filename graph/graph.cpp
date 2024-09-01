#include "vertice.cpp"
#include <list>
#include <stdexcept>
#include <string>
#include <unordered_map>

class Graph {
public:
  Graph();
  Graph(int qtdVertices);
  list<Vertice> getVertices();
  void adicionarVertice(string rotulo);

private:
  int qtdMaximaVertices;
  int qtdAtualVertices;
  bool isQtdMaximaDefinida = false;
  unordered_map<string, int> rotulosEmIndices;
  list<Vertice> vertices;
};

Graph::Graph() { qtdMaximaVertices = 10; };

Graph::Graph(int qtdVertices) {
  if (qtdVertices <= 0) {
    throw invalid_argument("O grafo não pode ter menos que 1 vertice");
  }
  qtdMaximaVertices = qtdVertices;
  isQtdMaximaDefinida = true;
};

list<Vertice> Graph::getVertices() { return vertices; }

void Graph::adicionarVertice(string rotulo) {
  if (qtdAtualVertices <= (qtdMaximaVertices - 1)) {
    Vertice *vtc = new Vertice(rotulo);
    vertices.push_back(vtc);
    rotulosEmIndices.insert(rotulo, qtdAtualVertices);
  } else {
    throw invalid_argument("O grafo já está completo");
  }
}

int main(int argc, char *argv[]) {
  Vertice *vtc = new Vertice("asd");
  cout << vtc->getRotulo() << endl;
  Graph *g = new Graph(25);
  return 0;
}
