/*
Given the head of a singly linked list, return true if it is a palindrome.
*/

#include <iostream>
#include <stack>
using namespace std;

class Item {
public:
  int value;
  Item *next;

  friend class LinkedList;
};

class LinkedList {
public:
  Item *head;
  void pushInFront(int num);
  void pop();
  int front();
  void print();
  LinkedList();
  ~LinkedList();
};

LinkedList::LinkedList() : head(NULL) {}

LinkedList::~LinkedList() {
  while (head != NULL) {
    pop();
  }
};

void LinkedList::print() {
  Item *temp = head;
  while (temp->next != NULL) {
    cout << "[ " << temp->value << " ] -> ";
    temp = temp->next;
  }
  cout << "[ " << temp->value << " ]" << endl;
}

void LinkedList::pushInFront(int num) {
  Item *node = new Item;
  node->value = num;
  node->next = head;
  head = node;
};

void LinkedList::pop() {
  Item *temp = head;
  head = head->next;
  temp->next = NULL;
  delete temp;
};

int LinkedList::front() { return head->value; };

// ================= SOLUTION ====================

class Solution {
public:
  bool isPalindrome(Item *it);
};

bool Solution::isPalindrome(Item *item) {
  if (item != NULL) {
    stack<int>
        pilha; // Pilha para armazenar a primeira metade da lista encadeada
    Item *mid = item; // ponteiro apontando para a cabeça da lista
    int count = 0;    // contador para saber o tamanho da lista encadeada
    pilha.push(
        mid->value); // iniciamos adicionando o primeiro valor da ll na pilha
    while (item != NULL) // vamos iterar até o último elemento da lista
    {
      if (count % 2 != 0) {
        pilha.push(mid->value);
        mid = mid->next;
      }
      ++count;
      item = item->next;
    }

    if (count % 2 != 0) {
      mid = mid->next;
    }

    while (mid != NULL) {
      int val = pilha.top();
      pilha.pop();
      if (mid->value != val) {
        return false;
      }
      mid = mid->next;
    }
    return true;
  }
  return false;
};

// ================= SOLUTION ====================

int main(int argc, char *argv[]) {
  LinkedList *ll = new LinkedList;

  ll->pushInFront(1);
  ll->pushInFront(2);
  // ll->pushInFront(3);
  // ll->pushInFront(3);
  // ll->pushInFront(2);
  // ll->pushInFront(1);
  Solution *sl;
  cout << (sl->isPalindrome(ll->head) ? "Sim" : "Não") << endl;

  delete ll;

  return 0;
}
