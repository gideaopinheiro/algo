#include <iostream>
#include <unistd.h>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int l, int h) {
  int i = l;
  int j = h;

  int pivot = arr[l];

  while (i < j) {
    while (arr[i] <= pivot) {
      i++;
    }
    while (arr[j] > pivot) {
      j--;
    }
    if (i < j) {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  int temp = arr[l];
  arr[l] = arr[j];
  arr[j] = temp;

  return j;
}

void quickSort(vector<int> &arr, int l, int h) {
  if (l < h) {
    int j = partition(arr, l, h);
    quickSort(arr, l, j);
    quickSort(arr, j + 1, h);
  }
  return;
}

int main(int argc, char const *argv[]) {
  vector<int> arr = {5, 3, 1, 9, 4, 7, 6, 10};
  // vector<int> arr = {5, 3, 1, 4, 9, 7, 6, 10}; -> j = 3
  // vector<int> arr = {1, 3, 4, 5, 9, 7, 6, 10}; -> j = 0
  // vector<int> arr = {1, 3, 4, 5, 6, 7, 9, 10}; -> j = 6
  // vector<int> arr = {1, 3, 4, 5, 6, 7, 9, 10}; -> j =
  for (auto el : arr) {
    cout << el << " ";
  }
  cout << endl;
  quickSort(arr, 0, (arr.size() - 1));
  for (auto el : arr) {
    cout << el << " ";
  }
  cout << endl;
  return 0;
}
