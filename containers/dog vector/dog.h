/**
  This is the header file for the dog hierarchy
*/

#include <vector>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>

/**
  The Dog class describes the behavior and characteristics of a dog. Dog is the base class from which other categories of dogs are derived.
*/
class Dog {
  
public:

  /** 
    The default constructor for Dog
  */
  Dog(){}

  /**
    The constructor for dog
    @param b the breed of the dog
    @param s the size of the dog
  */
  Dog( std::string b, std::string s ) : breed(b), size(s){}

  /**
    Right shift operator will print theh dog
  */
  friend std::ostream &operator<<( std::ostream &out, Dog &d );

protected:
  /** The breed of the dog */
  std::string breed;
  /** The size of the dog: big, medium, or small */
  std::string size;
};

/**
  The ServiceDog class describes a dog that has been certified by the government or an independent agency to assist people with certain activities.
  It is a child of the Dog class
*/
class ServiceDog : public Dog {
public:

  /**
    The constructor for Dog
    @param b the breed of the dog
    @param s the size of the dog
    @param id the identification number for the dog
  */
  ServiceDog( std::string b, std::string s, int id ) : Dog( b, s ) {
    idNumber = id;
  }

  /**
    The default constructor for ServiceDog
  */
  ServiceDog(){}

  /**
    The right shift operator will print the ServiceDog
  */
  friend std::ostream &operator<<( std::ostream &out, ServiceDog &sd );

protected:
  /** The identification number for this service dog */
  int idNumber;

};