#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    int i = 0, j = (numbers.size() - 1);
    while (i != j) {
      if ((numbers[i] + numbers[j]) < target) {
        i++;
      } else if ((numbers[i] + numbers[j]) > target) {
        j--;
      } else {
        return {i + 1, j + 1};
      }
    }
    return {-1, -1};
  }
};

int main(int argc, char const *argv[]) {
  vector<int> arr = {-1, 0};
  Solution *sol = new Solution();
  vector<int> result = sol->twoSum(arr, -1);
  cout << "[" << result[0] << ", " << result[1] << "]" << endl;
  return 0;
}
