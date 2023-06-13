#include "bachelor_info.h"

int print_all_info(FILE* fp, const char* filename)
{
  BACHELOR temp;

  if (freopen(filename, "rb", fp) == NULL)
  {
    fprintf(stderr, "error!\n");
    return 1;
  }

  printf("\n%10s / %20s / %20s / %20s / %20s / %20s / %10s / %10s / %20s / %10s / %10s\n\n", "id", "name", "phone", "email", "address", "major", "grade", "scholarship", "double_major", "graduate", "rest");
  while (fread(&temp, sizeof(BACHELOR), 1, fp) == 1)
  {
    if (temp.id != 0)
    {
      printf("%10d / %20s / %20s / %20s / %20s / %20s / %10d / %10d / %20s / %10s / %10s\n", temp.id, temp.name, temp.phone, temp.email, temp.address, temp.major, temp.grade, temp.scholarship, temp.double_major, temp.graduate ? "True" : "False", temp.rest ? "True" : "False");
    }
  }

  fclose(fp);
  return 0;
}

int print_by_major(FILE* fp, const char* filename)
{
  BACHELOR temp;
  char major[20];

  if (freopen(filename, "rb", fp) == NULL)
  {
    fprintf(stderr, "error!\n");
    return 1;
  }

  printf("Input major : ");
  scanf("%s", major);

  printf("\n%10s / %20s / %20s / %20s / %20s / %20s / %10s / %10s / %20s / %10s / %10s\n\n", "id", "name", "phone", "email", "address", "major", "grade", "scholarship", "double_major", "graduate", "rest");
  while (fread(&temp, sizeof(BACHELOR), 1, fp) == 1)
  {
    if (strcmp(temp.major, major) == 0 || strcmp(temp.double_major, major) == 0)
    {
      printf("%10d / %20s / %20s / %20s / %20s / %20s / %10d / %10d / %20s / %10s / %10s\n", temp.id, temp.name, temp.phone, temp.email, temp.address, temp.major, temp.grade, temp.scholarship, temp.double_major, temp.graduate ? "True" : "False", temp.rest ? "True" : "False");
    }
  }

  fclose(fp);
  return 0;
}

void print(FILE* fp, const char* filename)
{
  int choose;

  printf("1. all\n");
  printf("2. major\n");

  printf("Choose keyword you want to print : ");
  scanf("%d", &choose);

  switch (choose)
  {
  case 1:
    printf("\n");
    print_all_info(fp, filename);
    break;
  case 2:
    printf("\n");
    print_by_major(fp, filename);
    break;
  default:
    printf("choose in 1~6\n");
    break;
  }

  fclose(fp);
}
