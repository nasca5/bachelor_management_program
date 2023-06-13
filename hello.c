#include <stdio.h>

int main()
{
  FILE *fp;
  char *filename = "text.txt";

  fp = fopen(filename, "ab");

  fclose(fp);

  printf("%p", fp);
  return 0;
}
