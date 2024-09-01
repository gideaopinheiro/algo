#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {

    if (head == NULL || head->next == NULL) {
      return head;
    }

    ListNode *slow = head;
    ListNode *fast = slow->next;

    while (fast != NULL) {
      if (slow->val == fast->val) {
        while (fast != NULL && fast->val == slow->val) {
          ListNode *temp = fast;
          fast = fast->next;
          delete temp;
        }

        if (fast != NULL) {
          slow->next = fast;
          fast = fast->next;
        }
      } else {
        slow = slow->next;
        fast = fast->next;
      }
    }
    return head;
  }
};

void printList(ListNode *head) {
  ListNode *temp = head;
  while (temp != NULL) {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main(int argc, char *argv[]) {
  Solution *sol = new Solution();
  ListNode *a = new ListNode(1);
  ListNode *b = new ListNode(1, a);
  ListNode *c = new ListNode(1, b);

  printList(c);

  ListNode *result = sol->deleteDuplicates(c);

  printList(result);

  return 0;
}
