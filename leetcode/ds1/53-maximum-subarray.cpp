#include <bits/stdc++.h>
using namespace std;

// 1 2 4 -6

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int max = INT_MIN;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      if (sum < nums[i]) {
        sum = nums[i];
      }
      if (sum >= max) {
        max = sum;
      }
    }
    return max;
  }
};

int main(int argc, char const *argv[]) {
  Solution *sol = new Solution();
  vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout << sol->maxSubArray(arr) << endl;
  return 0;
}
