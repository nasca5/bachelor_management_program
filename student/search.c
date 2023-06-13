#include "bachelor_info.h"

void search_info()
{
  int choose;

  printf("1. id\n");
  printf("2. name\n");
  printf("3. phone\n");
  printf("4. email\n");
  printf("Choose keyword you want to search : ");
  scanf("%d", &choose);

  switch (choose)
  {
  case 1:
    printf("\n");
    search_by_id();
    break;
  case 2:
    printf("\n");
    search_by_name();
    break;
  case 3:
    printf("\n");
    search_by_phone();
    break;
  case 4:
    printf("\n");
    search_by_email();
    break;
  default:
    printf("\n");
    printf("Choose in 1~4\n");
    break;
  }
}

int search_by_id()
{
  BACHELOR temp;
  int id;
  int mod;

  if (freopen(filename, "rb", fp) == NULL)
  {
    fprintf(stderr, "error!\n");
    return 1;
  }

  printf("Input id : ");
  scanf("%d", &id);

  printf("\n%10s / %20s / %20s / %20s / %20s / %20s / %10s / %10s / %20s / %10s / %10s\n\n", "id", "name", "phone", "email", "address", "major", "grade", "scholarship", "double_major", "graduate", "rest");
  while (fread(&temp, sizeof(BACHELOR), 1, fp) == 1)
  {
    if (temp.id == id)
    {
      printf("%10d / %20s / %20s / %20s / %20s / %20s / %10d / %10d / %20s / %10s / %10s\n\n", temp.id, temp.name, temp.phone, temp.email, temp.address, temp.major, temp.grade, temp.scholarship, temp.double_major, temp.graduate ? "True" : "False", temp.rest ? "True" : "False");

      printf("modify it? (Y : 1 / N : 0) : ");
      scanf("%d", &mod);

      if (mod == 1)
      {
        modify_info(&temp);
      }
      else
      {
        break;
      }
    }
  }

  fclose(fp);
}

int search_by_name()
{
  BACHELOR temp;
  char name[20];
  int mod;

  if (freopen(filename, "rb", fp) == NULL)
  {
    fprintf(stderr, "error!\n");
    return 1;
  }

  printf("Input name : ");
  scanf("%s", name);

  printf("\n%10s / %20s / %20s / %20s / %20s / %20s / %10s / %10s / %20s / %10s / %10s\n\n", "id", "name", "phone", "email", "address", "major", "grade", "scholarship", "double_major", "graduate", "rest");
  while (fread(&temp, sizeof(BACHELOR), 1, fp) == 1)
  {
    if (!strcmp(temp.name, name))
    {
      printf("%10d / %20s / %20s / %20s / %20s / %20s / %10d / %10d / %20s / %10s / %10s\n\n", temp.id, temp.name, temp.phone, temp.email, temp.address, temp.major, temp.grade, temp.scholarship, temp.double_major, temp.graduate ? "True" : "False", temp.rest ? "True" : "False");

      printf("modify it? (Y : 1 / N : 0) : ");
      scanf("%d", &mod);

      if (mod == 1)
      {
        modify_info(&temp);
      }
      else
      {
        break;
      }
    }
  }

  fclose(fp);
}

int search_by_phone()
{
  BACHELOR temp;
  char phone[20];
  int mod;

  if (freopen(filename, "rb", fp) == NULL)
  {
    fprintf(stderr, "error!\n");
    return 1;
  }

  printf("Input phone(without dash) : ");
  scanf("%s", phone);

  printf("\n%10s / %20s / %20s / %20s / %20s / %20s / %10s / %10s / %20s / %10s / %10s\n\n", "id", "name", "phone", "email", "address", "major", "grade", "scholarship", "double_major", "graduate", "rest");
  while (fread(&temp, sizeof(BACHELOR), 1, fp) == 1)
  {
    if (!strcmp(temp.phone, phone))
    {
      printf("%10d / %20s / %20s / %20s / %20s / %20s / %10d / %10d / %20s / %10s / %10s\n\n", temp.id, temp.name, temp.phone, temp.email, temp.address, temp.major, temp.grade, temp.scholarship, temp.double_major, temp.graduate ? "True" : "False", temp.rest ? "True" : "False");

      printf("modify it? (Y : 1 / N : 0) : ");
      scanf("%d", &mod);

      if (mod == 1)
      {
        modify_info(&temp);
      }
      else
      {
        break;
      }
    }
  }

  fclose(fp);
}

int search_by_email()
{
  BACHELOR temp;
  char email[20];
  int mod;

  if (freopen(filename, "rb", fp) == NULL)
  {
    fprintf(stderr, "error!\n");
    return 1;
  }

  printf("Input email : ");
  scanf("%s", email);

  printf("\n%10s / %20s / %20s / %20s / %20s / %20s / %10s / %10s / %20s / %10s / %10s\n\n", "id", "name", "phone", "email", "address", "major", "grade", "scholarship", "double_major", "graduate", "rest");
  while (fread(&temp, sizeof(BACHELOR), 1, fp) == 1)
  {
    if (!strcmp(temp.email, email))
    {
      printf("%10d / %20s / %20s / %20s / %20s / %20s / %10d / %10d / %20s / %10s / %10s\n\n", temp.id, temp.name, temp.phone, temp.email, temp.address, temp.major, temp.grade, temp.scholarship, temp.double_major, temp.graduate ? "True" : "False", temp.rest ? "True" : "False");

      printf("modify it? (Y : 1 / N : 0) : ");
      scanf("%d", &mod);

      if (mod == 1)
      {
        modify_info(&temp);
      }
      else
      {
        break;
      }
    }
  }

  fclose(fp);
}
