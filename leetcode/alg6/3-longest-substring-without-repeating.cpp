#include <iostream>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int length = s.size();
    if (size <= 1) {
      return size;
    }

    return 0;
  }
};

int main(int argc, char *argv[]) {
  Solution *sol = new Solution();
  cout << sol->lengthOfLongestSubstring("abcabcbb") << endl;
  return 0;
}
