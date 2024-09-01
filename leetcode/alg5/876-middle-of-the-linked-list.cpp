
#include <iostream>
using namespace std;

class ListNode {
public:
  ListNode *next;
};

class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    int counter = 0;
    ListNode *temp = head;
    while (head != NULL) {
      if (counter & 1)
        temp = temp->next;
      counter++;
      head = head->next;
    }
    return temp;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
