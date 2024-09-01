// #include <iostream>
// using namespace std;

// class Person {
// public:
//   void printHello() { cout << "Hello!!" << endl; }
// };

// class Student : public Person {
// public:
//   void printHi() { cout << "Hi!!" << endl; };
// };

// int main(int argc, char const *argv[]) {
//   Person *pp[3];
//   pp[0] = new Person();
//   pp[1] = new Student();
//   // pp[1]->printHi();
//   // Student *temp = dynamic_cast<Student *>(pp[1]);
//   // temp->printHi();
//   return 0;
// }

#include <iostream>
using namespace std;

template <typename T> T sumABTogether(T a, T b) { return (a + b); }

int main(int argc, char const *argv[]) {
  float a = 3.23;
  float b = 4.40;
  cout << sumABTogether(a, b) << endl;
  return 0;
}
