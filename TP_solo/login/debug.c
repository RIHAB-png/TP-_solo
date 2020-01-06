#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char * readUsername(FILE* fin)
{
  char c;
  char *s;
  s = (char *) malloc(1);
  s[0] = '\0';
  int l = 1;
  c = fgetc(fin);
  while(c != '\n'){
    if(!isalnum(c))
      {
	fprintf(stderr,"Only alpha-numeric value allowed\n");
	__fpurge(fin);
      }
    else
      {
        l++;
	s = (char*)realloc(s,l);
	s[l-2]=c;
	s[l-1]='\0';
	c = fgetc(fin);
      }
  }
  return s;
}

char * readPassword(FILE* fin)
{
  char c;
  char *s;
  s = (char *) malloc(1);
  s[0] = '\0';
  unsigned int l = 1;
  unsigned int lower = 0, upper = 0, digit = 0, punct = 0;
  c = fgetc(fin);
  while(c != '\n'){
    if(islower(c))
      {
	lower ++;
      }
    if(isupper(c))
      {
	upper ++;
      }
    if(isdigit(c))
      {
	digit ++;
      }
    if(ispunct(c) || c == ' ')
      {
	punct ++;
      }
    l++;
    s = (char*)realloc(s,l);
    s[l-2]=c;
    s[l-1]='\0';
    c = fgetc(fin);
  }
  if (digit >= 1 && punct >= 1 && lower >= 1 && upper >= 1 && l >= 8)
    return s;
  else
      return NULL;

}


int main(int argc, char **argv)
{
  printf("Enter username : ");
  char * u = readUsername(stdin);
  printf("%s",u);
  printf("\nEnter your password : ");
  char * p = readPassword(stdin);
  printf("%s\n",p);
  free(p);
  return 1;
}
