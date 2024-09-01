#include <iostream>
#include <string>
using namespace std;

class Person {
private:
  string name;
  string idNum;

public:
  void print();
  string getName();
  Person(const string &nm, const string &id);
};

Person::Person(const string &nm, const string &id) : name(nm), idNum(id) {}

class Student : public Person {
private:
  string major;
  int gradYear;

public:
  void print();
  void changeMajor(const string &newMajor);
  Student(const string &nm, const string &id, string maj, int year);
};

Student::Student(const string &nm, const string &id, string maj, int year)
    : Person(nm, id), major(maj), gradYear(year) {}

void Person::print() {
  cout << "Name " << name << endl;
  cout << "IDnum " << idNum << endl;
};

void Student::print() {
  Person::print();
  cout << "Major " << major << endl;
  cout << "Year " << gradYear << endl;
};

// void Student::printName() { cout << name << endl; }

int main(int argc, char const *argv[]) {
  Student *std;
  cout << (*std).getName() << endl;

  return 0;
}
