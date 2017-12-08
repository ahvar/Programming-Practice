#include <cstdlib>
#include <cstdio>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <iostream>

template<typename OuterWear>
class CoatRack {
public:
  using size_type = unsigned long;
  using value_type = OuterWear;
  using owIterator = OuterWear*; 
  using const owIterator = const OuterWear*;
  owIterator begin();
  const owIterator begin();
  owIterator end();
  const owIterator end();
  size_type size();


};