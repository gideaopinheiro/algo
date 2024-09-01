#include <iostream>
#include <vector>
using namespace std;

void divideAndConquer(vector<int> arr, int begin, int end) {
  if (begin == end) {
    cout << arr[begin] << endl;
    return;
  }
  int middle = (begin + end) / 2;
  cout << arr[middle] << endl;
  divideAndConquer(arr, begin, middle - 1);
  divideAndConquer(arr, middle + 1, end);
}

int main(int argc, char *argv[]) {
  vector<int> arr = {1, 7, 6, 9, 12, 4, 0};
  divideAndConquer(arr, 0, arr.size() - 1);
  return 0;
}
