#include <iostream>
#include <vector>
using namespace std;

template <typename T> class Node {
public:
  T elem;
  Node<T> *next;
};

template <typename T> class LinkedList {
public:
  LinkedList();
  ~LinkedList();
  bool empty() const;
  const T& front() const;
  void addFront(const T& e);
  void removeFront();
  // treino
  bool contains(const T& t) const;
  void print();
  void reverse();
private:
  Node<T> *head;
};

template<typename T> LinkedList<T>::LinkedList() : head(NULL) {};
template<typename T> LinkedList<T>::~LinkedList() {
  while (!empty()) {
    removeFront();
  } 
}
template<typename T> bool LinkedList<T>::empty() const {
  return (head == NULL);
}
template<typename T> const T& LinkedList<T>::front() const {
  return head->elem;
}
template<typename T> void LinkedList<T>::addFront(const T& e) {
  Node<T> *v = new Node<T>();
  v->elem = e;
  v->next = head;
  head = v;
}
template<typename T> void LinkedList<T>::removeFront() {
  Node<T> *old = head;
  head = old->next;
  delete old;
}
template<typename T> bool LinkedList<T>::contains(const T& t) const {
  Node<T> *it = head;
  while (it != NULL) {
    if (it->elem == t) return true;
    it = it->next;
  }
  return false;
}
template <typename T> void LinkedList<T>::print() {
  Node<T> *n = head;
  while (n != NULL) {
    cout << n->elem << " ";
    n = n->next;
  }
  cout << endl;
}
template <typename T> void LinkedList<T>::reverse() {
  if (head != NULL) {
    Node<T> *prev = NULL;
    Node<T> *curr = head;
    Node<T> *next = curr->next;

    while (true) {
      curr->next = prev;
      prev = curr;
      if (next == NULL) {
        head = curr;
        break;
      }
      curr = next;
      next = next->next;
    }
  }
}

template<typename T>
LinkedList<T> *fromVectorToLinkedList(vector<T> v) {
  LinkedList<T>* ll = new LinkedList<T>();
  int vSize = v.size();
  for (int i = 0; i < vSize; i++) {
    ll->addFront(v.back());
    v.pop_back();
  }
  return ll;
}



int main (int argc, char *argv[]) { 
  vector<int> v = {9, 7, 2, 0, 87};
  auto ll = fromVectorToLinkedList(v);
  // cout << ll->contains(2) << endl;
  ll->print();
  ll->reverse();
  ll->print();


  vector<char> vc = {'d', 'k'};
  auto ll2 = fromVectorToLinkedList(vc);
  // cout << ll2->contains('d') << endl;

  vector<string> vs = {"meu", "nome"};
  auto ll3 = fromVectorToLinkedList(vs);
  // cout << ll3->contains("meus") << endl;
  return 0;
}

