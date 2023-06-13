
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
  char email[30];
  char address[30];
  char major[20];
  int grade;
  int scholarship;
  char double_major[20];
  int graduate;
  int rest;
} BACHELOR;

int register_info(FILE* fp, const char* filename);
void print(FILE* fp, const char* filename);
int print_all_info(FILE* fp, const char* filename);
int print_by_major(FILE* fp, const char* filename);
void search_info(FILE* fp, const char* filename);
int search_by_id(FILE* fp, const char* filename);
int search_by_name(FILE* fp, const char* filename);
int search_by_phone(FILE* fp, const char* filename);
int search_by_email(FILE* fp, const char* filename);
int modify_info(BACHELOR *temp, FILE* fp, const char* filename);
int remove_info(FILE* fp, const char* filename);
