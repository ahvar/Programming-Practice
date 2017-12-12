#include <iostream>
#include <string>

using namespace std;


/** Composite classes contain class-type members. When a class-type member of a composite class is created, the constructor is called before the class's 
    own constructor. When a contained class lacks a default constructor, an initialization list must be used in the constructor of the composite class.
*/
class Description
{
public: 
  Description( const string &name, const string &descr ) 
  {
    m_name = name;
    m_descr = descr;
  }
  string m_name;
  string m_descr;
};

class Case
{
public:
  Case( int width, int length, int height ) 
  {
    m_width = width;
    m_length = length;
    m_height = height;
  }
  int volume() { return m_width * m_length * m_height; }
private:
  int m_width;
  int m_length;
  int m_height;
};

class StorageCase : public Case 
{
public:
  StorageCase( int width, int length, int height, Description descr ) : Case( width, length, height), m_descr(descr){}
private:
  Description m_descr;
};

int main()
{

  Description d1{"box", "kitchen"};
  StorageCase sc1( 1, 2, 3, d1 );

  StorageCase sc2( 3, 4, 5, Description{ "box 2", "bedroom" } );

  StorageCase sc3( 4, 5, 6, { "box 3", "bathroom" } );

}