#include "bachelor_info.h"

int main()
{
  FILE *fp;
  const char *filename = "bachelor_info.txt";

  fp = fopen(filename, "ab");
  int play = 1;
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
      register_info(fp, filename);
      fclose(fp);
      return 0;
    case 2:
      printf("\n");
      print(fp, filename);
      break;
    case 3:
      printf("\n");
      search_info(fp, filename);
      break;
    case 4:
      printf("\n");
      remove_info(fp, filename);
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
