#include <stdio.h>
#include <stdlib.h>

#include "hash_table.h"

int main(void)
{
  Data_info_ptr* table = create_hash_table(2);
  int a = 2;
  char* b = "hello";
  int c = 6;

  insert(table, 2, "numb", &a);
  printf("%d\n", *(int *)search(table, 2, "numb"));

  delete(table, 2, "numb");
  printf("%s\n", (char *)search(table, 2, "numb"));

  insert(table, 2, "numb", b);
  printf("%s\n", (char *)search(table, 2, "numb"));

  insert(table, 2, "number", &c);
  printf("%d\n", *(int *)search(table, 2, "number"));

return 0;
}