#include "dog.h"

std::ostream &operator<<( std::ostream &out, Dog &d )
{
  out << "This is a " << d.breed << " and it is " << d.size << "." << std::endl;
  return out;

}


std::ostream &operator<<( std::ostream &out, ServiceDog &sd )
{
  out << "Service dog: " << sd.breed << std::endl;
  out << "Size: " << sd.size << std::endl;
  out << "ID Number: " << sd.idNumber << std::endl;
  out << sd.breed << std::endl;
  return out;


}