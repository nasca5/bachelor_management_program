#include "bachelor_info.h"

int main()
{
  FILE *fp;
  const char *filename = "./staff/bachelor_info.txt";
  int id;
  int play;
  int choose;
  BACHELOR temp;

  if ((fp = fopen(filename, "r+b")) == NULL)
  {
    fprintf(stderr, "error!\n");
    return 1;
  }

  printf("Input your id : ");
  scanf("%d", &id);

  fseek(fp, (id - START_ID) * sizeof(BACHELOR), SEEK_SET);
  if (fread(&temp, sizeof(BACHELOR), 1, fp) == 1 && temp.id != 0)
  {
    printf("\n%10s / %20s / %20s / %20s / %20s / %20s / %10s / %10s / %20s / %10s / %10s\n\n", "id", "name", "phone", "email", "address", "major", "grade", "scholarship", "double_major", "graduate", "rest");
    printf("%10d / %20s / %20s / %20s / %20s / %20s / %10d / %10d / %20s / %10s / %10s\n", temp.id, temp.name, temp.phone, temp.email, temp.address, temp.major, temp.grade, temp.scholarship, temp.double_major, temp.graduate ? "True" : "False", temp.rest ? "True" : "False");
  }
  else
  {
    printf("no info...\n");
    return 1;
  }

  printf("Modify it? (Y : 1 / N : 0) : ");
  scanf("%d", &play);

  while (play)
  {
    printf("1. Phone\n");
    printf("2. Email\n");
    printf("3. Address\n");

    printf("Choose keyword you want to modify : ");
    scanf("%d", &choose);

    switch (choose)
    {
    case 1:
      printf("Phone : ");
      scanf("%s", temp.phone);
      break;
    case 2:
      printf("Email : ");
      scanf("%s", temp.email);
      break;
    case 3:
      printf("Address : ");
      scanf("%s", temp.address);
      break;
    default:
      printf("Choose in 1 ~ 3\n");
      break;
    }

    printf("%10d / %20s / %20s / %20s / %20s / %20s / %10d / %10d / %20s / %10s / %10s\n", temp.id, temp.name, temp.phone, temp.email, temp.address, temp.major, temp.grade, temp.scholarship, temp.double_major, temp.graduate ? "True" : "False", temp.rest ? "True" : "False");
    printf("Modify more? (Y : 1 / N : 0) : ");
    scanf("%d", &play);
  }

  fseek(fp, (long int)sizeof(BACHELOR) * -1, SEEK_CUR);
  fwrite(&temp, sizeof(BACHELOR), 1, fp);

  fclose(fp);

  return 0;
}
