#include <iterator>
#include <iostream>
#include <list>
using namespace std;

void findTheMiddle(list<int> ll) {
  list<int>::iterator slow;
  list<int>::iterator fast;

  for (slow = ll.begin(), fast = ll.begin(); fast != ll.end() ; slow++, fast++) {
    fast++;
    continue;
  }
  cout << *slow << endl;
}

int main (int argc, char *argv[]) {
  list<int> myList{12, 3, 4, 1, 7, 9, 10, 12};
  findTheMiddle(myList);
  return 0;
}
