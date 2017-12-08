# Version One

###### Header File: __location_v1.h__
###### Implementation: __location_v1.cpp__
###### Driver: __locationTest_v1.cpp__

## Description
The header file contains the location class which declares the data members and functions for a particular location.

### Instance Variables / Data Fields
All location data fields are pointers to char. The allcateMemory() function is called by the client to allocate the memory for each character string. C++ rolls these lower level character functions from C into a higher level data type called  string.  
 - What are some situations where a programmer may need to manually assign and release memory?
 

### Overloading Operators
The following operators are overloaded:
  - right shift operator '<<' to print a location 
  - assignment operator '=' to copy one location to the next
  - the equality operator '==' to compare two locations for equality



