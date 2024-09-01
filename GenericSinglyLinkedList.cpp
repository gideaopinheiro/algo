#include <iostream>
#include <string>
using namespace std;

template <typename E> class Node {
private:
  E elem;
  Node<E> *next;
  friend class SinglyLinkedList<E>;
};

template <typename E> class SinglyLinkedList {
public:
  SinglyLinkedList();
  ~SinglyLinkedList();
  bool empty() const;
  void pop();
  void addFront(const E &e);
  void print();

private:
  Node<E> *head;
};

template <typename E> void SinglyLinkedList<E>::addFront(const E &e) {
  Node<E> *node = new Node<E>;
  node->elem = e;
  node->next = head;
  head = node;
}

template <typename E> bool SinglyLinkedList<E>::empty() const {
  return (head == NULL);
}

template <typename E> void SinglyLinkedList<E>::pop() {
  Node<E> *temp = head;
  temp = head->next;
  delete temp;
}

template <typename E> SinglyLinkedList<E>::SinglyLinkedList() : head(NULL) {}

template <typename E> SinglyLinkedList<E>::~SinglyLinkedList() {
  while (!empty())
    pop();
}

template <typename E> void SinglyLinkedList<E>::print() {
  Node<E> *temp = head;
  while (temp != NULL) {
    cout << temp->elem;
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  SinglyLinkedList<string> *ll = new SinglyLinkedList<string>;
  ll->addFront("hello");
  ll->addFront(", world");
  ll->print();
  delete ll;
  return 0;
}
