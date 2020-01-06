#include "filename.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char * buildFilenameFromHome(char * filename ) //To be freed
{
  char *file;
  file = (char *) malloc(strlen(getenv("HOME")) + strlen(filename) + 1); // to account for NULL terminator
  sprintf(file, "%s%s", getenv("HOME"), filename);
  return file;
}
