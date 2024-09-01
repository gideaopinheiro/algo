#include <iostream>
using namespace std;

class Item
{
public:
  int value;
  Item *next;

  friend class LinkedList;
};

class LinkedList
{
public:
  Item *head;
  void pushInFront(int num);
  int pop();
  void print();
  LinkedList();
  ~LinkedList();
};

LinkedList::LinkedList() : head(NULL) {}

LinkedList::~LinkedList()
{
  while (head != NULL)
  {
    pop();
  }
};

void LinkedList::print()
{
  Item *temp = head;
  while (temp->next != NULL)
  {
    cout << "[ " << temp->value << " ] -> ";
    temp = temp->next;
  }
  cout << "[ " << temp->value << " ]" << endl;
}

void LinkedList::pushInFront(int num)
{
  Item *node = new Item;
  node->value = num;
  node->next = head;
  head = node;
};

int LinkedList::pop()
{
  int value = head->value;
  Item *temp = head;
  head = head->next;
  temp->next = NULL;
  delete temp;
  return value;
};

int main(int argc, char *argv[])
{
  LinkedList *ll = new LinkedList;

  ll->pushInFront(2);
  ll->print();
  ll->pushInFront(5);
  ll->print();
  ll->pushInFront(8);
  ll->print();
  ll->pop();
  ll->print();
  ll->pushInFront(90);
  ll->print();
  ll->pushInFront(1);
  ll->print();

  return 0;
}
