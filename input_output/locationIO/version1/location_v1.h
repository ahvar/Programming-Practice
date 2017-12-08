/**
  Location
  @file location.h
  @author Arthur Vargas (ahvargas92@gmail.com)
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>

class Location {

public:
  /** 
    Constructs a location.
    @param a1 a pointer to the first character of the address line
    @param a2 a pointer to the first character of another line in the address
    @param c a pointer to the first character in the name of the city
    @param s a pointer to the first character in the abbreviation for the state
    @param z a pointer to the first character in the zip code
    @param e a pointer to the first character in the description of the environment
  */
  Location( char *a1, char *a2, char *c, char *s, char *z, char *e ) : add1{a1}, add2{a2}, city{c}, state{s}, zip{z}, environ{e}{}

  /** 
    Constructs a location.
    @param a1 a pointer to the first character of the address line
    @param c a pointer to the first character in the name of the city
    @param s a pointer to the first character in the abbreviation for the state
    @param z a pointer to the first character in the zip code
    @param e a pointer to the first character in the description of the environment
  */
  Location( char *a1, char *c, char *s, char *z, char *e  ) : add1{a1}, city{c}, state{s}, zip{z}, environ{e}{}

  /**
   The default constructor for the location
  */
  Location( ){}

  /**
    Prints all the location data fields to standard output
  */
  void print() { std::cout << this << std::endl; }

  /**
    The overloaded stream operator prints all the location data fields to standard output
    @param os a reference to the standard output stream
    @param l a reference to location to be output
    @return standard output stream
  */
  friend std::ostream &operator<<( std::ostream &os, Location &l );

  /**
    Overloaded assignment operator. Uses the strncpy function to copy the field from 'l' to the corresponding field of the assigning location (i.e. the operand on
    the left-hand side). The location passed into the function is the right-hand side operand.
    @param l a reference to the location
    @return this location 
  */
  Location &operator=( Location &l );

  /**
    Overloaded equality operator. Uses the strncmp function to compare each location data field. The length of the character array of a given data field in l1
    determines how many characters are compared.
    @param l1 a reference to the location
    @param l2 a reference to the location
    @return true if all of the data fields in a location are equivalent, false otherwise
  */
  bool operator==( Location &l );

private:
  /** The first line in the address */
  char *add1;
  /** The second line in the address, if there is one */
  char *add2;
  /** The city */
  char *city;
  /** The abbreviation for the state */
  char *state;
  /** The zip code */
  char *zip;
  /** The environment. Either urban or rural */
  char *environ;

};

