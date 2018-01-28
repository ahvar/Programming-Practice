#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX_WRD_LNG 20
#define BUFFER_LNG 75

bool getLetters( char *letters )
{
  printf("prompt> ");
  char line[75];
  if ( fgets(line, sizeof(line), stdin) != NULL ) {
    printf("%s \n", line);
    return true;
  }
  //printf("Buffer contains: %s Buffer length: %d\n", buffer, len);
  //for(int i = 0; i < strlen(buffer); i++)
  //  buffer[i] = 0;
  //len = strlen(buffer);
  //const char *ptr = buffer + 7;
  //sscanf(ptr, "%s", buffer);
  //printf("Buffer contains: %s. Buffer length: %d\n", buffer, len);
  return false;
}

int main()
{
  char letters[MAX_WRD_LNG];

  
  while( getLetters(letters) ) {
    
  
  } 

  if ( ferror(stdin) ) {
    printf("%s", "Invalid letters.");
    scanf("%*[^\n]");
    
  } 
  //while( (ch = getchar()) != EOF) {
    //  printf("%c", ch);
  return 0;

}