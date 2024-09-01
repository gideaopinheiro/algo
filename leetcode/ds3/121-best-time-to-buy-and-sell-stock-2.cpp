#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    int mn = INT_MAX;
    int ans = 0;

    for (int i = 0; i < n; i++) {
      mn = min(mn, prices[i]);
      ans = max(ans, prices[i] - mn);
    }
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  Solution *sol = new Solution();
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  cout << sol->maxProfit(prices) << endl;
  return 0;
}
