#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct A {

  /**
    A pointer to a function that takes no parameters and returns nothing. It is initialized with the address of the function called printA(), which is defined
    outside of 'A's name space. 
  */
  void(*print)();
  
};

struct B {

  /**
    A pointer to the function addAToList, which is defined outside of 'B's name space
    @param a pointer to an instance of 'A' class
    @param a struct of 'B'
  */
  void(*add)(A *a);

  /** An array of pointers to 'A' objects */
  A *list[];
 
  /** 
    A pointer to a function that prints struct B
  */
  void(*print)(B b);

};

void printA()
{
  printf("%s\n", "Class: A");
}

void addAToList(A *a, B b)
{

  A *ptr = list;
  while( ptr )
    ptr++;
  *ptr = *a;

}

void printB(B b)
{
  A *ptr = b->list;
  while (ptr) {
    printf("%s\n", *ptr);
    ptr++;
  }

}


int main()
{
  A a;
  a.print = &printA;
  B b;
  b.add = &addAToList;
  b.print = &printB;
 
  
  
  return 0;
}