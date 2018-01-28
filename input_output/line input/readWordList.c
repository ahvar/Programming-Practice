#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#define LEN 50
#define maxWrdLen 20
#define wordmax 100

int main(int argc, char *argv[])
{
  char buffer[LEN];
  char words[wordmax][maxWrdLen];
  int wordcount = 0;
  FILE *fp = fopen(argv[1], "r");
  fgets(buffer, sizeof(buffer), fp);
  int wrdlen = 0;
  for ( int i = 0; sscanf( buffer + wrdlen, "%[a-z]", words[i] ) != EOF; i++ ) {
    wrdlen = wrdlen + strlen(words[i]) + 1;
    wordcount++;
  }
  for ( int i = 0; strlen(words[i]) > 0; i++ )
    printf("%s\n", words[i]);  
  return 0;
}