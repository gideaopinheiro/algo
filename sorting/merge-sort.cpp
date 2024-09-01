#include <iostream>
#include <vector>
using namespace std;

// O (n * log n)

vector<int> merge(vector<int> s1, vector<int> s2) {
  int i = 0, j = 0;
  int s1Size = s1.size(), s2Size = s2.size();
  vector<int> result;
  while (i < s1Size && j < s2Size) {
    if (s1[i] < s2[j]) {
      result.push_back(s1[i++]);
    } else {
      result.push_back(s2[j++]);
    }
  }
  while (i < s1Size) {
    result.push_back(s1[i++]);
  }
  while (j < s2Size) {
    result.push_back(s2[j++]);
  }
  return result;
}

vector<int> mergeSort(vector<int> arr, int begin, int end) {
  if (begin >= end) {
    vector<int> copy = {arr[begin]};
    return copy;
  }
  int mid = (begin + end) / 2;
  return merge(mergeSort(arr, begin, mid), mergeSort(arr, mid + 1, end));
}

int main(int argc, char *argv[]) {
  vector<int> arr = {4, 1, 5, 2, 22, 7, 8, 10};
  vector<int> result = mergeSort(arr, 0, arr.size() - 1);
  for (auto c: result) {
    cout << c << " ";
  }
  cout << endl;
  return 0;
}
