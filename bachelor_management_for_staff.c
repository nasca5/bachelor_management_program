#include "bachelor_info.h"

int register_info();
void print();
int print_all_info();
int print_by_major();
void search_info();
int search_by_id();
int search_by_name();
int search_by_phone();
int search_by_email();
int modify_info(BACHELOR *temp);
int remove_info();

int main()
{
  fp = fopen(filename, "ab");
  int play = true;
  int choose;

  while (play)
  {
    printf("1. Register info\n");
    printf("2. Print info\n");
    printf("3. Search info\n");
    printf("4. Remove info\n");
    printf("5. Quit\n");
    printf("\nChoose What you want : ");
    scanf("%d", &choose);

    switch (choose)
    {
    case 1:
      printf("\n");
      register_info();
      break;
    case 2:
      printf("\n");
      print();
      break;
    case 3:
      printf("\n");
      search_info();
      break;
    case 4:
      printf("\n");
      remove_info();
      break;
    case 5:
      printf("\n");
      return 0;
    default:
      printf("Choose in 1~5\n\n");
      break;
    }

    printf("More? (Y : 1 / N : 0) : ");
    scanf("%d", &play);
    printf("\n\n");
  }

  fclose(fp);

  return 0;
}

int register_info()
{
  BACHELOR temp;
  int check;

  if (freopen(filename, "r+b", fp) == NULL)
  {
    fprintf(stderr, "error!\n");
    return 1;
  }

  printf("Yes : 1 / No : 0 (ex. graduate : 1 / rest : 1 / double_major : 1)\n");
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
  fclose(fp);
}

int print_all_info()
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
}

int print_by_major()
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
}

void print()
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
    print_all_info();
    break;
  case 2:
    printf("\n");
    print_by_major();
    break;
  default:
    printf("choose in 1~6\n");
    break;
  }

  fclose(fp);
}

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

int modify_info(BACHELOR *temp)
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

  fclose(fp);
}

int remove_info()
{
  BACHELOR temp;
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

  fclose(fp);
}
