#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    vector<int> result = vector<int>(nums.size());
    int i = 0, j = (nums.size() - 1), k = (nums.size() - 1);
    while (j >= i) {
      if ((nums[j] * nums[j]) > (nums[i] * nums[i])) {
        result[k] = nums[j] * nums[j];
        j--;
      } else {
        result[k] = nums[i] * nums[i];
        i++;
      }
      k--;
    }
    return result;
  }
};

int main(int argc, char const *argv[]) {
  Solution *sol = new Solution();
  vector<int> arr = {-7, -3, 2, 3, 11};
  vector<int> result = sol->sortedSquares(arr);
  for (auto i : result) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
