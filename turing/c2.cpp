#include <string>
#include <iostream>
#include <stack>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
  public:
  std::vector<int> solution(const std::vector<int>& k) {
    std::unordered_map<int, int> countMap;
    for (int num : k) {
        countMap[num]++;
    }

    auto compare = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        if (a.second != b.second) {
            return a.second < b.second;
        } else {
            return a.first > b.first;
        }
    };

    std::vector<std::pair<int, int>> counts;
    for (const auto& pair : countMap) {
        counts.push_back(pair);
    }

    std::sort(counts.begin(), counts.end(), compare);

    std::vector<int> result;
    for (const auto& pair : counts) {
        int num = pair.first;
        int count = pair.second;
        for (int i = 0; i < count; ++i) {
            result.push_back(num);
        }
    }

    return result;
}
};

int main() {
  vector<int> k = {-1, 1, -6, 4, 5, -6, 1, 4, 1};
  Solution solution;
  vector<int> result =solution.solution(k);
  for (auto c : result) {
    cout << c << " ";
  }
  cout << endl;
  return 0;
}