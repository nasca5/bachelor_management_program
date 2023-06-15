#include "bachelor_info.h"

int modify_info(BACHELOR *temp, FILE *fp, const char *filename)
{
  int play = 1;
  int choose;

  if (freopen(filename, "r+b", fp) == NULL)
  {
    fprintf(stderr, "error!\n");
    return 1;
  }

  while (play)
  {
    printf("\n");
    printf("1. Phone\n");
    printf("2. Email\n");
    printf("3. Address\n");
    printf("4. Major\n");
    printf("5. Grade\n");
    printf("6. Scholarship\n");
    printf("7. Double Major\n");
    printf("8. Graduate\n");
    printf("9. Rest\n");
    printf("Choose keyword you want to modify : ");
    scanf("%d", &choose);

    switch (choose)
    {
    case 1:
      printf("\n");
      printf("Phone : ");
      scanf("%s", temp->phone);
      break;
    case 2:
      printf("\n");
      printf("Email : ");
      scanf("%s", temp->email);
      break;
    case 3:
      printf("\n");
      printf("Address : ");
      scanf("%s", temp->address);
      break;
    case 4:
      printf("\n");
      printf("Major : ");
      scanf("%s", temp->major);
      break;
    case 5:
      printf("\n");
      printf("Grade : ");
      scanf("%d", &temp->grade);
      break;
    case 6:
      printf("\n");
      printf("Scholarship : ");
      scanf("%d", &temp->scholarship);
      break;
    case 7:
      printf("\n");
      printf("Double Major(if you only remove it, then input \"nothing\") : ");
      scanf("%s", temp->double_major);
      break;
    case 8:
      printf("\n");
      printf("Graduate : ");
      scanf("%d", &temp->graduate);
      break;
    case 9:
      printf("\n");
      printf("Rest : ");
      scanf("%d", &temp->rest);
      break;
    default:
      printf("\n");
      printf("Choose in 1~9\n");
      break;
    }

    printf("%10d / %20s / %20s / %20s / %20s / %20s / %10d / %10d / %20s / %10s / %10s\n\n", temp->id, temp->name, temp->phone, temp->email, temp->address, temp->major, temp->grade, temp->scholarship, temp->double_major, temp->graduate ? "True" : "False", temp->rest ? "True" : "False");

    printf("Modify more?(Y : 1 / N : 0) : ");
    scanf("%d", &play);
  }

  fseek(fp, (temp->id - START_ID) * sizeof(BACHELOR), SEEK_SET);
  fwrite(temp, sizeof(BACHELOR), 1, fp);

  return 0;
}

int remove_info(FILE *fp, const char *filename)
{
  BACHELOR temp = {0};
  int id;

  if (freopen(filename, "r+b", fp) == NULL)
  {
    fprintf(stderr, "error!\n");
    return 1;
  }

  printf("Input id to remove : ");
  scanf("%d", &id);

  fseek(fp, (id - START_ID) * sizeof(BACHELOR), SEEK_SET);
  fwrite(&temp, sizeof(BACHELOR), 1, fp);

  return 0;
}

void search_info(FILE *fp, const char *filename)
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
    search_by_id(fp, filename);
    break;
  case 2:
    printf("\n");
    search_by_name(fp, filename);
    break;
  case 3:
    printf("\n");
    search_by_phone(fp, filename);
    break;
  case 4:
    printf("\n");
    search_by_email(fp, filename);
    break;
  default:
    printf("\n");
    printf("Choose in 1~4\n");
    break;
  }
}

int search_by_id(FILE *fp, const char *filename)
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
        modify_info(&temp, fp, filename);
      }
      else
      {
        break;
      }
    }
  }

  return 0;
}

int search_by_name(FILE *fp, const char *filename)
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
        modify_info(&temp, fp, filename);
      }
      else
      {
        break;
      }
    }
  }

  return 0;
}

int search_by_phone(FILE *fp, const char *filename)
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
        modify_info(&temp, fp, filename);
      }
      else
      {
        break;
      }
    }
  }

  return 0;
}

int search_by_email(FILE *fp, const char *filename)
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
        modify_info(&temp, fp, filename);
      }
      else
      {
        break;
      }
    }
  }

  return 0;
}
