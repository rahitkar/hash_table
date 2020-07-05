#ifndef __HASH_TABLE_H_
#define __HASH_TABLE_H_

typedef struct 
{
  char* key;
  void* value;
} Data_info;

typedef Data_info* Data_info_ptr;

Data_info_ptr* create_hash_table(int size);

void insert(Data_info_ptr* table, int table_size, char* key, void* value);

void delete(Data_info_ptr* table, int table_size, char* key);

void *search(Data_info_ptr *table, int table_size, char *key);

#endif