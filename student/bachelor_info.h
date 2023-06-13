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

FILE *fp;
const char *filename = "bachelor_info.txt";
