#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template<typename Iterator>
Iterator high(Iterator first, Iterator last)
{
  Iterator high = first; 
  for(Iterator p = first; p != last; ++p)
    if(*high < *p) high = p;
  return high;


}
 
class VectorList{
  int sz;
  double *elem;
  int space;
public:
  VectorList(int s) : sz{s}, elem{new double[s]} {}
  VectorList(initializer_list<double> first) : sz{(int)first.size()}, elem{new double[sz]} 
  {
    copy(first.begin(),first.end(),elem);
  }
  // copy constructor
  VectorList(const VectorList &arg);
  VectorList(VectorList &&a);
  VectorList &operator=(VectorList &&a);
  // assignment operator
  VectorList &operator=(const VectorList &a);
  ~VectorList() { delete[] elem; }
  VectorList fill(istream &is);
  VectorList *fill(istream &is);
  // move with assignment operator
  VectorList &operator=(VectorList &&a);

  // reserve more space
  void reserve(int newalloc);
  // add dd to the VectorList
  void pushBack(double dd);

};

VectorList::VectorList(const VectorList &arg) : sz{arg.sz}, elem{new double[arg.sz]}
{
  copy(arg.elem, arg.elem + sz, elem);
}

VectorList &VectorList::operator=(const VectorList &a)
{
  double *p = new double[a.sz];
  copy(a.elem,(a.elem+a.sz),elem);
  delete[] elem;
  elem = p;
  sz = a.sz;
  return *this;
}

VectorList fill(istream &is)
{
  vector res;
  for(double x; is>>x; ) vector.push_back(x);
  return res;

}

VectorList *fill2(istream &is)
{
  vector *res = new vector;
  for(double x; is>>x; ) res->push_back(x);
  return res;

}


VectorList &VectorList(VectorList &&a) : sz{a.sz}, elem{a.elem}
{
  a.sz = 0;
  a.elem = NULL;

}

VectorList &VectorList::operator=(VectorList &&a)
{
  delete[] elem;
  elem = a.elem;
  sz = a.sz;
  a.elem = NULL;
  a.sz = 0;
  return *this; //dereference to get the VectorList. in this case "contents of" this equals the memory address for VectorList  


}

void VectorList::reserve(int newalloc)
{
  if(newalloc<=space) return;
  double *p = new double[newalloc];
  for(int i = 0; i < sz; ++i) p[i] = elem[i];
  delete[] elem;
  elem = p;

}

void VectorList::pushBack(double dd)
{
  if(space==0)
    reserve(8);
  else if(sz==space)
    reserve(2*space);
  elem[sz] = dd;
  ++sz;
}

double *high(double *first, double *last)
{
  double h = -1;
  double *high;
  for(double *p = first; p != last; ++p)
    if(h<*p) { high = p; h = *p; }
  return high;

}

int main()
{
  VectorList v1 = {2.3,3.2,4.5};
  double *high = high

  return 0;
}