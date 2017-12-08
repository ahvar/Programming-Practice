#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <list>

template<typename Elem>
struct Link {
  Link *prev;
  Link *succ;
  Elem val;
};


template<typename Elem>
class ListTemp {
public:

  class TempIterator{
    Link<Elem> *curr;
  public:
    TempIterator(Link<Elem> *p) : curr{p}{}
    TempIterator &operator++() { curr = curr->succ; return *this; }
    TempIterator &operator--() { curr = curr->prev; return *this; }
    Elem &operator*(){ return curr->val; }
    bool operator==(const TempIterator *b) const { return curr==b.curr; }
    bool operator!=(const TempIterator *b) const { return curr!=b.curr; }
    TempIterator begin();
    TempIterator end();
    TempIterator insert(TempIterator p, const Elem &v);
    TempIterator erase(TempIterator p);
    void push_back(const Elem &v);
    void pop_back(const Elem &v);
    Elem &front();
    Elem &back();

  };

};

