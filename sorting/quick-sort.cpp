#include <iostream>
#include <vector>
using namespace std;

vector<int> quickSort(vector<int> arr) {
  int sizeArr = arr.size();
  if (sizeArr <= 1) {
    return arr;
  }

  vector<int> L, E, G;
  int pivot = arr.back();
  while (!arr.empty()) {
    if (arr.back() < pivot) {
      L.push_back(arr.back());
      arr.pop_back();
    } else if (arr.back() == pivot) {
      E.push_back(arr.back());
      arr.pop_back();
    } else {
      G.push_back(arr.back());
      arr.pop_back();
    }
  }

  auto orderedL = quickSort(L);
  auto orderedG = quickSort(G);

  for (auto c : orderedL) {
    arr.push_back(c);
  }

  for (auto c : E) {
    arr.push_back(c);
  } 

  for (auto c : orderedG) {
    arr.push_back(c);
  }

  return arr;
}

int main (int argc, char *argv[]) {
  vector<int> arr = {4, 3, 2, 5, 7, 4, 1, 2, 6, 9, 8, 0};
  auto ordered = quickSort(arr);
  for (auto i : ordered) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
