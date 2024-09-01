#include <iostream>
#include <vector>
using namespace std;

class Node {
private:
  int item;
  Node *next;
  friend class LinkedList;
};

class LinkedList {
private:
  Node *head;

protected:
  void pop();

public:
  void insertInOrder(int num);
  void insertAfter(Node *node, int num);
  void insert(int num);
  void print();
  bool empty();
  LinkedList();
  ~LinkedList();
};

LinkedList::LinkedList() : head(NULL) {}

void LinkedList::pop() {
  Node *temp = head;
  head = head->next;
  temp = NULL;
  delete temp;
}

bool LinkedList::empty() { return head == NULL; }

LinkedList::~LinkedList() {
  while (!empty()) {
    pop();
  }
}

void LinkedList::insertAfter(Node *node, int num) {
  Node *n = new Node;
  n->item = num;
  n->next = node->next;
  node->next = n;
}

void LinkedList::insert(int num) {
  Node *n = new Node;
  n->item = num;
  n->next = head;
  head = n;
}

void LinkedList::insertInOrder(int num) {
  if (empty()) {
    insert(num);
  } else if (num < head->item) {
    Node *n = new Node;
    n->item = num;
    n->next = head;
    head = n;
  } else {
    Node *temp = head;
    while ((num > temp->item) && (temp->next != NULL)) {
      temp = temp->next;
    }
    insertAfter(temp, num);
  }
}

void LinkedList::print() {
  Node *temp = head;
  while (temp != NULL) {
    cout << temp->item << " ";
    temp = temp->next;
  }
  cout << endl;
}

class Solution {
public:
  vector<int> KWeakestRows(vector<vector<int>> &mat, int k) {
    LinkedList *ll = new LinkedList;
    for (auto line : mat) {
      int count = 0;
      for (auto col : line) {
        count += col;
      }
    }
  }
};

int main(int argc, char const *argv[]) {
  LinkedList *ll = new LinkedList;
  ll->insertInOrder(3);
  ll->print();
  ll->insertInOrder(5);
  ll->print();
  ll->insertInOrder(1);
  ll->print();
  ll->insertInOrder(9);
  ll->print();
  ll->insertInOrder(0);
  ll->print();
  ll->insertInOrder(14);
  ll->print();

  delete ll;
  return 0;
}
