#include <stdlib.h>
#include <string.h>

#include "hash_table.h"

Data_info_ptr *create_hash_table(int size)
{
  Data_info_ptr *table = malloc(size * sizeof(Data_info));

  for (size_t i = 0; i < size; i++)
  {
    table[i] = NULL;
  }

  return table;
}

int get_hash_index(char *key, int table_size)
{
  int i = 0;
  int ascii_sum = 0;
  while (key[i] != '\0')
  {
    ascii_sum += key[i];
    i++;
  }
  return ascii_sum % table_size;
}

void insert(Data_info_ptr *table, int table_size, char *key, void *value)
{
  int hash_index = get_hash_index(key, table_size);

  while (table[hash_index] != NULL)
  {
    if (!strcmp(table[hash_index]->key, key))
    {
      table[hash_index]->value = value;
      return;
    }

    hash_index++;
  }
  table[hash_index] = malloc(sizeof(Data_info));
  table[hash_index]->key = key;
  table[hash_index]->value = value;
}

void delete (Data_info_ptr *table, int table_size, char *key)
{
  int hash_index = get_hash_index(key, table_size);
  while (table[hash_index] != NULL)
  {
    if (!strcmp(table[hash_index]->key, key))
    {
      table[hash_index] = NULL;
      return;
    }
    hash_index++;
  }
}

void *search(Data_info_ptr *table, int table_size, char *key)
{
  int hash_index = get_hash_index(key, table_size);
  while (table[hash_index] != NULL)
  {
    if (!strcmp(table[hash_index]->key, key))
    {
      return table[hash_index]->value;
    }
    hash_index++;
  }
  return NULL;
}