#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class BC {
public:
  BC() {
    print_it();
  }
  virtual void print_it() {
    cout << "BC print_it" << endl;
  }
};

class DC : public BC {
public:
  DC() {
    print_it();
  }
  virtual void print_it() {
    cout << "DC print_it" << endl;
  }
};

int main()
{
  DC dc;

}