#include <cstdlib>
#include <string>
#include <iostream>

/**
  Human describes the characteristics and behaviors of a person. Human is the base class.
*/
class Human {

public:
  /**
    Constructs an instance of human.
    @param n the name of the human
  */
  Human( std::string n ) : name(n){}

  /**
    Default constructor for Human
  */
  Human(){}

  friend std::ostream &operator<<( std::ostream &out, Human &h );

protected:

  std::string name;
};

/**
  The TSA_Agent class describes the characteristics and behavior or a TSA_Agent. It descends from the Human class
*/
class TSA_Agent : public Human {

  TSA_Agent( std::string n, int num ) : Human( n ) {
    badgeNum = num;   
  }
  TSA_Agent( std::string n ) : Human( n ) {
    badgeNum = 0;
  }
  TSA_Agent(){}

  friend std::ostream &operator<<( std::ostream &out, TSA_Agent &ts );
    
protected:
  int badgeNum;
  
};