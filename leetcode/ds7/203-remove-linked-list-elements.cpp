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
  ListNode *removeElements(ListNode *head, int val) {
    if (head == NULL) {
      return head;
    }
    ListNode *slow = head;
    ListNode *fast = slow->next;

    while (fast != NULL) {
      if (fast->val == val) {
        slow->next = fast->next;
        delete fast;
        fast = slow->next;
      } else {
        slow = slow->next;
        fast = fast->next;
      }
    }

    if (head->val == val) {
      head = head->next;
    }
    return head;
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
  ListNode *a = new ListNode(6);
  ListNode *b = new ListNode(5, a);
  ListNode *c = new ListNode(4, b);
  ListNode *d = new ListNode(3, c);
  ListNode *e = new ListNode(6, d);
  ListNode *f = new ListNode(2, e);
  ListNode *g = new ListNode(1, f);

  Solution *sol = new Solution();
  printLinkedList(g);
  ListNode *res = sol->removeElements(g, 6);
  printLinkedList(res);

  return 0;
}
