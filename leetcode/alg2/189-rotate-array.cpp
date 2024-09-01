#include <iostream>
#include <vector>
using namespace std;

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// [1,2,3,4,5,6,7]

// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// [-1,-100,3,99]

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    int size = nums.size();
    vector<int> aux;
    k = k % size;
    for (int i = size - k; i < size; i++) {
      aux.push_back(nums[i]);
    }
    for (int i = 0; i < size - k; i++) {
      aux.push_back(nums[i]);
    }

    for (int i = 0; i < size; i++) {
      nums[i] = aux[i];
    }
  }
};

int main(int argc, char const *argv[]) {
  Solution *sol = new Solution();
  vector<int> arr = {1};
  sol->rotate(arr, 1);
  return 0;
}
