#include <iostream>
#include <vector>
using namespace std;


int binarySearch(vector<int> arr, int target, int start, int end) {
  int size = arr.size();
  int mid = (start + end) / 2;
  if (start > end) {
    return -1;
  }
  if (arr[mid] == target) {
    return mid;
  } else if (arr[mid] < target) {
    return binarySearch(arr, target, mid+1, end);
  } else {
    return binarySearch(arr, target, start, mid);
  }
} 

int main (int argc, char *argv[]) {
  vector<int> arr = {1, 2, 3, 4, 5, 6};
  auto pos = binarySearch(arr, 3, 0, arr.size() - 1);
  cout << "The position is: " << pos << endl;
  return 0;
}
