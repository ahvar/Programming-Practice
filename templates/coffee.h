#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <list>

template<typename Bean>
struct Node {
  Node *prev;
  Node *succ;
  Bean b;
};

template<typename Bean>
class BeanList{
  class BeanIterator;
  Node<Bean> *first;
  Node<Bean> *last;
  BeanIterator begin();
  BeanIterator end();
  BeanIterator insert();
  BeanIterator erase();
  
};

template<typename Bean>
class BeanList<Bean>::BeanIterator {
  Node<Bean> *curr;
public:
  BeanIterator(Node<Bean> *p) : curr{p} {}
  BeanIterator &operator++() { curr = curr->succ; return *this; }


};
  