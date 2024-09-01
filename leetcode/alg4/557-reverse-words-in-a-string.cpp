#include <iostream>
#include <vector>
using namespace std;

// Input: s = "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"

class Solution {
public:
  string reverseWords(string s) {
    int size = s.size();
    if (size == 1) {
      return s;
    }

    int left = 0, right = left + 1;
    while (right <= size) {
      if ((s[right] == ' ') || (right == size)) {
        int temp = right - 1;
        while (temp > left) {
          char t = s[left];
          s[left] = s[temp];
          s[temp] = t;

          --temp;
          ++left;
        }
        left = ++right;
        ++right;
      } else {
        ++right;
      }
    }
    return s;
  }
};

int main(int argc, char const *argv[]) {
  Solution *sol = new Solution();
  cout << sol->reverseWords("a b d") << endl;
  return 0;
}
