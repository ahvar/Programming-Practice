#include "human.h"

std::ostream &operator<<( std::ostream &out, Human &h )
{
  out << h.name << std::endl;
  return out;


}

std::ostream &operator<<( std::ostream &out, TSA_Agent &t)
{
  out << t.name << std::endl;
  out << t.badgeNum << std::endl;

}

