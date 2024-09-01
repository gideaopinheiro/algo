#include <iostream>
using namespace std;

class Node {
public:
  int value;
  Node *next;

  friend class LinkedList;
};

class LinkedList {
public:
  Node *head;
  void pushInFront(int num);
  void pop();
  void print();
  Node *top();
  LinkedList();
  ~LinkedList();
};

LinkedList::LinkedList() : head(NULL) {}

LinkedList::~LinkedList() {
  while (head != NULL) {
    pop();
  }
};

void LinkedList::pushInFront(int num) {
  Node *node = new Node;
  node->value = num;
  node->next = head;
  head = node;
  cout << "head: " << head << endl;
  // cout << "head: " << head << "\nndode: " << node << endl;
}

void LinkedList::print() {
  Node *temp = head;
  while (temp != NULL) {
    cout << temp->value << " ";
    temp = temp->next;
  }
  cout << endl;
}

void LinkedList::pop() {
  Node *temp = head;
  head = head->next;
  temp = NULL;
  delete temp;
}

/*
Sempre operaremos dois nós da lista por vez,
mas para isso precisamos ter sempre referência para
os dois nós em que estamos trocando a 'direção' dos ponteiros
e também para uma referência para o resto da lista.

prev -> é o nó à esquerda do nó atual
curr -> é o nó atual, que mudará de direção
nxt ->  é o nó que guarda a referência para o resto da lista

Após o nó atual (curr) apontar para o nó anterior, atualizamos
os nós para que essa operação se repita até que toda a lista esteja
invertida.
a -> b -> c -> NULL
c -> b -> a -> NULL
*/
Node *reverse(Node *head) {
  if (head != NULL) {
    Node *prev = NULL;
    Node *curr = head;
    Node *nxt = curr->next;

    while (true) {
      curr->next = prev;
      prev = curr;
      if (nxt == NULL) {
        /*
        Significa que o último nó da lista teve sua direção alterada no
        último ciclo do loop, por isso temos que sair do loop usando o break
        */
        break;
      }
      curr = nxt;
      nxt = nxt->next;
    }
    return curr;
  }
  return head;
}

Node *LinkedList::top() { return head; }

int main(int argc, char const *argv[]) {
  LinkedList *ll = new LinkedList;
  ll->pushInFront(3);
  ll->pushInFront(4);
  ll->pushInFront(5);
  ll->pushInFront(6);

  ll->print();
  // 5 -> 4 -> 3 -> NULL
  Node *head = ll->top();
  Node *newHead = reverse(head);
  while (newHead != NULL) {
    cout << newHead->value << " ";
    newHead = newHead->next;
  }
  cout << endl;
  return 0;
}
