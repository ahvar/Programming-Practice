#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class A {
protected:  

  /**
  Prints "Class: A" to the console.

  @param a reference to an instance of class 'A'
  @param out a reference to the output stream
  @return out reference to the output stream
*/
  void print(){ cout << "Class: A" << endl; }
  friend ostream &operator<<( ostream &out, A &a );
};

class B {
public:

  /**
    Adds a pointer to an instance of 'A' class to the vector named list.
    @param a pointer to an instance of 'A' class
  */
  void add( A *a ) { list.push_back(a); }
public:

  /** A vector of pointers to 'A' objects */
  vector<A *> list;

  /**
    Prints the contents of the vector named list. Accessing items by indexing.

    @param out a reference to the output stream
    @param b a reference to an instance of 'B' class
    @return a reference to the output stream
  */
  friend ostream &operator<<( ostream &out, B &b );
};


ostream &operator<<( ostream &out, A &a )
{
  out << "Class: A" << endl;
  return out;
}

ostream &operator<<( ostream &out, B &b )
{
  for ( int i = 0; i < (int) b.list.size(); i++ ) 
    out << *(b.list[i]) << endl;
  return out;

}


int main()
{
  B b;
  A *aptr; // pointer to 'A'
  A a1; // first A object
  A a2; // second A object
  aptr = &a1; // holds the address the first A object 
  A &a3 = a1; // also holds the address of the first A object
  a3 = a2; // now it holds the address of the second A object
  vector<A *> *alist = &b.list; // a pointer to a pointer to a Portfolio (the first Portfolio in 'alist'
  
  for ( int i = 0; i < 5; i++ ) {
    //a = new A();
    //b.add(a);
  }
  cout << b << endl;
  return 0;

}