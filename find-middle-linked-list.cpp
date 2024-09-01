#include <iostream>
#include <string>
using namespace std;

class Node {
private:
  int elem;
  Node *next;
  friend class LinkedList;
};

class LinkedList {
private:
  Node *header;

public:
  LinkedList();
  ~LinkedList();
  void add(const int e);
  void remove();
  void print();
  bool empty() const;
  int findMiddle() const;
};

LinkedList::LinkedList() : header(NULL){};

LinkedList::~LinkedList() {
  while (!empty()) {
    remove();
  }
}

bool LinkedList::empty() const { return header == NULL; }

void LinkedList::remove() {
  Node *temp = header;
  header = header->next;
  temp->next = NULL;
  delete temp;
}

void LinkedList::add(const int e) {
  Node *u = new Node;
  u->elem = e;
  u->next = header;
  header = u;
}

void LinkedList::print() {
  if (!empty()) {
    Node *temp = header;
    while (temp->next != NULL) {
      cout << "[ " << temp->elem << " ] -> ";
      temp = temp->next;
    }
    cout << "[ " << temp->elem << " ]" << endl;
  }
}

// int LinkedList::findMiddle() const
// {
//   int counter = 0;
//   Node *temp = header;
//   if (!empty())
//   {
//     while (temp->next != NULL)
//     {
//       temp = temp->next;
//       counter++;
//     }
//   }
//   int middle = (counter / 2);
//   temp = header;
//   counter = 0;
//   while (counter < middle)
//   {
//     temp = temp->next;
//     counter++;
//   }
//   return temp->elem;
// }

int LinkedList::findMiddle() const {
  if (empty())
    throw invalid_argument("A lista está vazia");

  Node *slowPtr = header;
  Node *fastPtr = header;
  while (fastPtr->next != NULL) {
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
  }
  // cout << "middle: [ " << slowPtr->elem << " ]" << endl;
  return slowPtr->elem;
}

// 4bits.com
// goldencow.com

// PRIMEIRO: Estudos na pandemia
// SEGUNDO: cada vez mais estudos sobre vicio alimentar

int main(int argc, char const *argv[]) {
  LinkedList *p = new LinkedList;
  (*p).add(4);
  (*p).print();
  p->add(12);
  p->print();
  cout << p << endl;

  int arr[] = {1, 2, 3};
  cout << arr << endl;
  arr[1] = 33;
  cout << arr[1] << endl;
  // int k = 8;
  // int *q = &k;
  // *q = 99;
  // cout << q << endl;  // endereço de k
  // cout << &q << endl; // endereço de q
  // cout << *q << endl; // valor de k
  // cout << k << endl;

  // int a[] = {1, 2, 3};
  // cout << &a[0] << endl;
  // cout << a << endl;

  // string k = "oi";
  // string l = ", tudo bem?";
  // // k.append("k");
  // bool check = (k == l);
  // cout << check << endl;
  // cout << k + l << endl;
  // cout << true << endl;

  return 0;
}
