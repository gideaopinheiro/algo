#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
  unordered_map<char, int> rti = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                  {'C', 100}, {'D', 500}, {'M', 1000}};

public:
  int romanToInt(string s) {
    int result = rti[s[0]];
    int size = s.size();
    for (int i = 1; i < size; i++) {
      if (rti[s[i]] > rti[s[i-1]]) {
        result -= rti[s[i-1]];
        result = result + (rti[s[i]] - rti[s[i-1]]);
      } else {
        result += rti[s[i]];
      }
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  Solution *sol = new Solution();
  auto result = sol->romanToInt("LVIII");
  cout << result << endl;
  return 0;
}
