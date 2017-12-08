#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <list>

template<typename Animal>
struct Link{
  Link *prev;
  Link *succ;
  Animal a;
};

template<typename Animal>
class AnimalList {
  class AnimalIterator;
  AnimalIterator begin();
  AnimalIterator end();
};


template<typename Animal>
class AnimalList<Animal>::AnimalIterator {
  Link<Animal> *curr;
public:
  AnimalIterator(Link<Animal> *p);
  AnimalIterator &operator++();
  AnimalIterator &operator--() { curr = curr->prev; return *this; }
  Animal &operator*(){ return curr->val; }
  bool operator==(const AnimalIterator *b) const { return curr==b.curr; }
  bool operator!=(const AnimalIterator *b) const { return curr!=b.curr; }
  AnimalIterator begin();
  AnimalIterator end();
  AnimalIterator insert(AnimalIterator p, const Animal &v);
  AnimalIterator erase(AnimalIterator p);
  void push_back(const Animal &v);
  void pop_back(const Animal &v);
  Animal &front();
  Animal &back();
};


