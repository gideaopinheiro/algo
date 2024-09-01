#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {

public:
  bool isValid(string s) {
    stack<char> parentheses;
    for (char c : s) {
      if (c == '(') {
        parentheses.push(c);
      } else {
        parentheses.pop();
      }
    }
    return (parentheses.size() == 0);
  }
};

int main(int argc, char *argv[]) { 
  Solution *sol = new Solution();
  cout << sol->isValid("(())") << endl;
  return 0; }
