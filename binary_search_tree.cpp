#include <iostream>
using namespace std;

typedef int Elem;
class Node {
  private:
    string key;
    Elem item;
    Node *left;
    Node *right;
    friend class BST;
};

class BST {
  public:
    BST(string key, int val);
    ~BST();
    int find(string key);
    void insert(string key, int val); 
    void remove(string key);
  private:
    Node *root;
};

BST::BST(string key, int val) {
  root = new Node;
  root->key = key;
  root->item = val;
}

BST::~BST() {}

int BST::find(string key) {
  return true;
}

int main (int argc, char *argv[]) {
  
  return 0;
}
