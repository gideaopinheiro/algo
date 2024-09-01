#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void reverseString(vector<char> &s) {
    int i = 0, j = (s.size() - 1);
    while (j > i) {
      char temp = s[i];
      s[i] = s[j];
      s[j] = temp;
      i++;
      j--;
    }
  }
};

int main(int argc, char const *argv[]) { return 0; }
