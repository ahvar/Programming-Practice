#include <iostream>
#include <cstdlib>
#include <string>
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
  Link(const string &v, Link *p = NULL, Link *s = NULL);
};

class SimpleList {
  int size;
  double *elem;
public:
  SimpleList(int s);
  int getSize() const { return size; }
  ~SimpleList() { delete[] elem; }
  double getElem( int i ) const { return elem[i]; }
  void set( int i, double a ) { elem[i] = a; }

};

SimpleList *f( int s)
{
  SimpleList *list = new SimpleList(s);
  for ( int i = 0; i < s; i++ )
    list[i] = 0;
  return list;

}

void ff()
{

  SimpleList *sl = f(4);
  for ( int i = 0; i < sl.getSize(); i++ )
    cout << sl[i] << endl;
  delete sl;

}

Link *insert(Link *p, Link *n)
{
  if (n==NULL) return p;
  if (n==NULL) return n;
  n->succ = p;
  p->prev->succ = n;
  n->prev = p->prev;
  p->prev = n;
  return n;

}

Link *add( Link *p, Link *n )
{
  if(p==NULL) return p;
  n->prev = p;
  p->succ = n;
  return n;

}

Link *erase( Link *p )
{
  if(p==NULL) return NULL;
  if(p->succ)p->succ->prev = p->prev;
  if(p->prev)p->prev->succ = p->succ;
  return p->succ;

}

Link *find(Link *p, const string &s)
{
  while(p) {
    if(p->value==s) return p;
    p = p->succ;
  }
  return NULL;

}

Link *advance(Link *p, int n)
{
  if(p==NULL) return NULL;
  if(0<n) {
    while(n--) {
      if(p->succ=NULL) return NULL;
      p = p->succ;
    }
  else if(n<0) {
    while(n++) { // the postfix yields the value before the increment as its value
      if(p->prev==NULL) return NULL;
      p = p->prev;
    }
  }
  return p;
}



int main()
{

  Link *norseGods = new Link{"Thor",NULL,NULL};
  norseGods = insert(norseGods, new Link{"Odin"});
  norseGods = insert(norseGods, new Link{"Freia"});

  Link *greekGods = new Link("Hera");
  greekGods = insert(greekGods, new Link{"Athena"});
  greekGods = insert(greekGods, new Link{"Mars"});
  greekGods = insert(greekGods, new Link{"Poseidon"});

  Link *p = find(greekGods,"Mars");
  if(p)p->value = "Ares";
  return 0;


}