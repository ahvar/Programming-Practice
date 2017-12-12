#include "dog.h"

/**
  A kennel is a transitory home for dogs
*/

/**
  The kennel class describes the data and functions for a kennel
*/
class Kennel {

public:

  friend std::ostream &operator<<( std::ostream &out, Kennel &k );

  std::vector<Dog *> kennel;

};