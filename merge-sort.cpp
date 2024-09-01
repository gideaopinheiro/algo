#include <iostream>
#include <vector>
using namespace std;

// 3  7
// 5  9

void printl(vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

vector<int> merge(vector<int> arr1, vector<int> arr2) {
  vector<int> arrFinal;
  int i = 0, j = 0;
  while (i < arr1.size() && j < arr2.size()) {
    if (arr1[i] < arr2[j]) {
      arrFinal.push_back(arr1[i]);
      i++;
    } else {
      arrFinal.push_back(arr2[j]);
      j++;
    }
  }
  while (i < arr1.size()) {
    arrFinal.push_back(arr1[i]);
    i++;
  }
  while (j < arr2.size()) {
    arrFinal.push_back(arr2[j]);
    j++;
  }
  return arrFinal;
}

vector<int> mergeSort(vector<int> arr, int begin, int end) {
  if (begin >= end) {
    vector<int> copy = {arr[begin]};
    return copy;
  }

  int middle = (begin + end) / 2;
  vector<int> left = mergeSort(arr, begin, middle);
  vector<int> right = mergeSort(arr, middle + 1, end);

  return merge(left, right);
}

int main(int argc, char *argv[]) {
  vector<int> arr = {14, 7, 3, 12, 9, 11, 6, 2};

  vector<int> ordered = mergeSort(arr, 0, arr.size() - 1);

  printl(ordered);

  return 0;
}
