#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Base
{
public:
  Base() { cout << "Base()" << endl; }
  Base( const Base &other ) { cout << "Base(Base &other)" << endl; }
  Base( int i ) : num(i) { cout << "Base(int)" << endl; }
  Base( char c ) : letter(c) { cout << "Base(char)" << endl; }

private:
  int num;
  char letter;
};

class Derived : Base
{
public:
  using Base::Base;

private:
  int newMember{0};
};

int main( int argc, char argv[] )
{
  cout << "derived d1(5) calls: ";
  Derived d1(5);

}