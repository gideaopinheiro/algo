#include <iostream>
#include <string>
using namespace std;

class Node {
private:
  string elem;
  Node *next;
  friend class SingleLinkedList;
};

class SingleLinkedList {
public:
  SingleLinkedList();
  ~SingleLinkedList();
  bool empty() const;
  const string &front() const;
  void addFront(const string &e);
  void removeFront();

private:
  Node *head;
};

SingleLinkedList::SingleLinkedList() : head(NULL) {}

SingleLinkedList::~SingleLinkedList() {
  while (!empty())
    removeFront();
}

bool SingleLinkedList::empty() const { return head == NULL; }

const string &SingleLinkedList::front() const { return head->elem; }

void SingleLinkedList::addFront(const string &e) {
  Node *v = new Node;
  v->elem = e;
  v->next = head;
  head = v;
}

void SingleLinkedList::removeFront() {
  Node *v = head;
  head = v->next;
  v = NULL;
  delete v;
}

int main(int argc, char *argv[]) { return 0; }
