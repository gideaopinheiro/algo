#include <iostream>
#include <vector>
using namespace std;

bool twoSum(vector<int> &nums, int target) {
  int i = 0, j = (nums.size() - 1);

  while (i != j) {
    if ((nums[i] + nums[j]) < target) {
      i++;
    } else if (((nums[i] + nums[j]) > target)) {
      j--;
    } else {
      cout << "i: " << i << ", j: " << j << endl;
      return true;
    }
  }
  cout << "i: " << i << ", j: " << j << endl;
  return false;
}

int main(int argc, char const *argv[]) {
  vector<int> arr = {1, 4, 7, 10, 12};
  cout << twoSum(arr, 22) << endl;
  return 0;
}
