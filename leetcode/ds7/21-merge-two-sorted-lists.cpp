#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *h = list1;
    ListNode *j = list2;

    ListNode *resultado = new ListNode();
    ListNode *aux = resultado;
    while (h != NULL && j != NULL) {
      if (h->val < j->val) {
        ListNode *n = new ListNode(h->val);
        aux->next = n;
        aux = aux->next;
        h = h->next;
      } else {
        ListNode *n = new ListNode(j->val);
        aux->next = n;
        aux = aux->next;
        j = j->next;
      }
    }

    while (j != NULL) {
      ListNode *n = new ListNode(j->val);
      aux->next = n;
      aux = aux->next;
      j = j->next;
    }

    while (h != NULL) {
      ListNode *n = new ListNode(h->val);
      aux->next = n;
      aux = aux->next;
      h = h->next;
    }
    return resultado->next;
  }
};

void printLinkedList(ListNode *head) {
  while (head != NULL) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  ListNode *a = new ListNode(4);
  ListNode *b = new ListNode(2, a);
  ListNode *c = new ListNode(1, b);

  ListNode *j = new ListNode(4);
  ListNode *k = new ListNode(3, j);
  ListNode *l = new ListNode(1, k);

  Solution *sol = new Solution();
  printLinkedList(sol->mergeTwoLists(c, l));
  return 0;
}
