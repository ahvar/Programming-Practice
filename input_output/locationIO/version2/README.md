# Version Two

###### Header File: __location_v2.h__
###### Implementation: __location_v2.cpp__
###### Driver: __locationTest_v2.cpp__

## Description
The header file contains the location class which declares the data members and functions for a particular location.

### Instance Variables / Data Fields
All location data fields are strings types rather than pointers to char like in Version1. In this version, the programmer does not have to manually allocate memory to read and store data in the respective fields of a location object.
 - In C, strings are character arrays. The notation for declaring a character array uses the subscript operator '[]' or a pointer '*'to the first character in the array. If the parameter types declared in a Location method's formal declaration are strings, can we pass a char pointer? 
 

### Overloading Operators
The following operators are overloaded:
  - right shift operator '<<' to print a location 
  - assignment operator '=' to copy one location to the next
  - the equality operator '==' to compare two locations for equality



