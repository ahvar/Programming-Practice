/**
  The implementation file for filereader.h
*/
#include "filereader.h"

FileReader::FileReader( std::vector<std::string *> s )
{

}

void readFile( FILE *f )
{



}

Stock *FileReader::loadPrices()
{
  return NULL;
     

  

}

using namespace std;

int main(int argc, char *argv[])
{
  //FILE *f = new FILE(argv[1], "r");
  ifstream file;
  file.open(argv[1], ios_base::in);

  string line;
  while(!file.eof()) {
    file >> line;
    //file.get(buffer, sizeof(buffer)-1);
    cout << line << endl;
    
  }
  return 0;
}