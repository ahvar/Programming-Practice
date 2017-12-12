#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;


/** A delegating constructor calls a different constructor in the same class to do some of the work of initialization. In the following example, the derived class has three constructors---the second constructor delegates to the first, and the third constructor delegates to the second
  you will need gcc 4.7 or newer to do this
*/
class ConstructorDestructor {
public:

  ConstructorDestructor() {
    cout << "ConstructorDestructor default constructor." << endl;
  }

  ConstructorDestructor( int int1 ) {
    cout << "ConstructorDestructor with 1 int." << endl;
  }

  ConstructorDestructor( int int1, int int2 ) : ConstructorDestructor( int1 ) {
    
    cout << "ConstructorDestructor with 2 ints." << endl;
    throw exception();
  }

  ConstructorDestructor( int int1, int int2, int int3 ) : ConstructorDestructor( int1, int2 ) {
    cout << "ConstructorDestructor with 3 ints." << endl;
  }
  
  ~ConstructorDestructor() {
    cout << "ConstructorDestructor destructor." << endl;
  }

};

int main()
{
  // The object created by the constructors is fully initialized as soon as any constructor is finished. ConstructorDestructor with one int parameter succeeds and ConstructorDestructor with two int parameters fails */
  ConstructorDestructor dc(1, 2, 3);


}