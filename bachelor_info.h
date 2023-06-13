#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define START_ID 1001001

typedef struct
{
  int id;
  char name[20];
  char phone[20];
  char email[20];
  char address[20];
  char major[20];
  int grade;
  int scholarship;
  char double_major[20];
  int graduate;
  int rest;
} BACHELOR;

FILE* fp;
const char* filename = "bachelor_info.txt";
