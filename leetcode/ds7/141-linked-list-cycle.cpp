#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  // bool hasCycle(ListNode *head) {
  //   unordered_set<ListNode *> mySet;
  //   ListNode *temp = head;
  //   while (temp != NULL) {
  //     if (mySet.find(temp) != mySet.end()) {
  //       return true;
  //     }
  //     mySet.insert(temp);
  //     temp = temp->next;
  //   }
  //   return false;
  // }

  bool hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        return true;
      }
    }
    return false;
  }
};

int main(int argc, char const *argv[]) {
  ListNode *head;
  cout << head->next << endl;
  return 0;
}
