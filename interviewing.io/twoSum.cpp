// #include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/*
Given a list of positive whole numbers with no duplicates
how would you go about finding any two numbers in that list
that sum up to a given target number.

[3, 6,12, 15, 4, 2, 1, 30] and target is 15, print "6 and 9"

12 6
*/

// Brute force approach
void printTwoNumbers(vector<int> arr, int target) {
  for (int i = 0; i < arr.size() - 1; i++) {
    if (arr[i] >= target)
      continue;
    for (int j = i + 1; j < arr.size(); j++) {
      if ((arr[i] + arr[j]) == target) {
        cout << arr[i] << " and " << arr[j] << endl;
        return;
      }
    }
  }
}

// Optimized approach
std::pair<int, int> getTwoNumbers(const vector<int> &nums, int target) {
  std::pair<int, int> result = std::make_pair(-1, -1);
  unordered_set<int> visitedNums;
  for (const auto &n : nums) {
    bool remainderExists = (visitedNums.find(target - n) != visitedNums.end());
    if (remainderExists) {
      result.first = (target - n);
      result.second = n;
      break;
    }
    visitedNums.insert(n);
  }
  return result;
}

int main(int argc, char const *argv[]) {
  vector<int> arr = {3, 6, 9, 12, 15, 4, 2, 1, 30};
  // printTwoNumbers(arr, 15);
  std::pair<int, int> result = getTwoNumbers(arr, 15);
  cout << result.first << " and " << result.second << endl;
  return 0;
}
