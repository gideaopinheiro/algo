#include <bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// usando a tecnica 'two pointers', podemos dizer que o nth nó
// que queremos deletar a partir do fim da lista, será a distancia
// entre os ponteiros... Dessa forma, quando o ponteiro mais à frente
// chegar no último nó, o nó mais lento estará exatamente 1 nó antes do nó
// que precisa ser deletado. Assim ligamos este nó ao nó posterior ao nó
// que será deletado.

// cuidados quando o número do nó a ser deletado é igual a quantidade
// de nós na lista. (sabemos disso quando )

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    int distance = n;
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next != NULL && n > 0) {
      fast = fast->next;
      --n;
    }

    while (fast->next != NULL) {
      slow = slow->next;
      fast = fast->next;
    }

    if (n > 0) {
      head = head->next;
    } else {
      ListNode *temp = slow->next;
      slow->next = temp->next;
      temp = NULL;
      delete temp;
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

int main(int argc, char const *argv[]) {
  ListNode *calda = new ListNode(5);
  ListNode *node1 = new ListNode(4, calda);
  ListNode *node2 = new ListNode(3, node1);
  ListNode *node3 = new ListNode(2, node2);
  ListNode *node4 = new ListNode(1, node3);

  Solution *sol = new Solution();
  printList(node2);
  ListNode *result = sol->removeNthFromEnd(node2, 1);
  printList(result);

  return 0;
}
