#include <iostream>
#include <cstdlib>
#include <string>
#include "string.h"
#include <cstring>
#include <fstream>
#include <istream>
#include <sstream>
#include <cstdio>
#include <ostream>
#include <cmath>
#include <stdexcept>
#include <vector>

using namespace std;

struct Link {
  string value;
  Link *prev;
  Link *succ;
  Link(const string &v, Link *p = NULL, Link *s = NULL) : value(v), prev{p}, succ{s} {}
  Link(){}
};

class GodList{
public:
  GodList(Link *l) : head(l) { count++; }
  GodList(){}

  void addToFront(Link *l) 
  {

    l->succ = head;
    head->prev = l;
    l->prev = NULL;
    head = l;
    count++;

  }

  void addToEnd(Link *l)
  {
    Link *ptr = head;
    while(ptr->succ)
      ptr = ptr->succ;
    ptr->prev->succ->succ = l;
    l->prev = ptr->prev->succ;
    count++; 
  }

  void remove(int x)
  {
    if ( x < count && x != 1 ) {
      Link *ptr = head;
      for ( int i = 0; i < x; i++ ) 
        ptr = ptr->succ;
      ptr->succ->prev = ptr->prev;
      ptr->prev->succ = ptr->succ;
    }
  
  }

  friend ostream &operator<<(ostream &out, GodList gl);

private:
  Link *head;
  int count;
};

ostream &operator<<(ostream &out, GodList gl)
{
  Link *ptr = gl.head;
  while(ptr) {
    out << ptr->value << endl;
    ptr = ptr->succ;
  }
  return out;

}

ostream &operator<<(ostream &out, Link l)
{
  out << l.value << endl;
  return out;

}

int main()
{

  Link *thor = new Link{"Thor",NULL,NULL};
  Link *hermia = new Link("Hermia",NULL, NULL);
  Link *apollo = new Link("Apollo", NULL, NULL);
  Link *posideon = new Link("Posideon",NULL,NULL);
  Link *aries = new Link("Aries",NULL,NULL);

  GodList *gl = new GodList(thor);
  gl->addToFront(hermia);
  gl->addToEnd(apollo);
  gl->addToEnd(posideon);
  gl->addToFront(aries);
  cout << *gl << endl;
  
  return 0;


}