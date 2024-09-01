#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
  bool isAlNum(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9'));
  }
  string toLowerCase(string s) {
    string result = "";
    for (auto c : s) {
      if ((c >= 'A') && (c <= 'Z')) {
        result += (c + 32);
      } else {
        result += c;
      }
    }
    return result;
  }

public:
  bool isPalindrome(string s) {
    string lower = toLowerCase(s);
    cout << lower << endl;
    int i = 0, j = s.size() - 1;
    while (i <= j) {
      if (!isAlNum(lower[i])) {
        cout << "hey" << endl;
        i++;
      } else if (!isAlNum(lower[j])) {
        cout << "alo" << endl;
        j--;
      } else if (lower[i] != lower[j]) {
        cout << "hi" << endl;
        return false;
      } else {
        i++;
        j--;
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  string s = "0P";
  Solution *sol = new Solution();
  cout << sol->isPalindrome(s) << endl;
  return 0;
}
