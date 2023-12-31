#include "bachelor_info.h"

int register_info(FILE *fp, const char *filename)
{
  BACHELOR temp;
  int check;

  if (freopen(filename, "r+b", fp) == NULL)
  {
    fprintf(stderr, "error!\n");
    return 1;
  }

  printf("In graduate and rest, please write 1 or 0(Y : 1 / N : 0)\n");
  printf("If you don't have double_major, please write only \"no\"\n");
  printf("input phonenumber without dash (ex. 010********)\n\n");
  printf("%10s / %10s / %10s / %10s / %10s / %10s / %10s / %10s / %10s / %10s / %10s\n\n", "id", "name", "phone", "email", "address", "major", "grade", "scholarship", "double_major", "graduate", "rest");
  while (scanf("%d / %s / %s / %s / %s / %s / %d / %d / %d / %d / %d", &temp.id, temp.name, temp.phone, temp.email, temp.address, temp.major, &temp.grade, &temp.scholarship, &check, &temp.graduate, &temp.rest) == 11)
  {
    if (check == 0)
    {
      strcpy(temp.double_major, "nothing");
    }

    else
    {
      printf("write your double major : ");
      scanf("%s", temp.double_major);
    }
    fseek(fp, (temp.id - START_ID) * sizeof(BACHELOR), SEEK_SET);
    fwrite(&temp, sizeof(BACHELOR), 1, fp);
  }
  return 0;
}
