#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    int sizeS1 = s1.size(), sizeS2 = s2.size();
    if (sizeS1 > sizeS2) {
      return false;
    }
    vector<int> freqS1 = vector<int>(26);
    for (auto i : s1) {
      freqS1[i - 'a']++;
    }

    int beggin = 0;
    while ((beggin + sizeS1) <= sizeS2) {
      if (isPermutation(freqS1, s2.substr(beggin, sizeS1))) {
        return true;
      }
      ++beggin;
    }
    return false;
  }

  bool isPermutation(vector<int> freqS1, string s2) {
    vector<int> freqS2 = vector<int>(26);
    for (auto j : s2) {
      freqS2[j - 'a']++;
    }

    return (freqS1 == freqS2);
  }
};

int main(int argc, char const *argv[]) {
  Solution *sol = new Solution();
  cout << sol->checkInclusion("ab", "eidoooba") << endl;
  return 0;
}
