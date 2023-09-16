#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Define a structure for a key-value pair
struct KeyValue {
  char key[50];
  int value;
};

// Define a hash table as an array of KeyValue structures
struct KeyValue hashTable[TABLE_SIZE];

// Simple hash function that takes a string key and returns a hash code
int hash(char key[]) {
  int sum = 0;
  for (int i = 0; key[i] != '\0'; i++) {
    sum += key[i];
  }
  return sum % TABLE_SIZE;
}

// Function to insert a key-value pair into the hash table
void insert(char key[], int value) {
  int index = hash(key);
  strcpy(hashTable[index].key, key);
  hashTable[index].value = value;
}

// Function to retrieve the value associated with a key from the hash table
int retrieve(char key[]) {
  int index = hash(key);
  if (strcmp(hashTable[index].key, key) == 0) {
    return hashTable[index].value;
  }
  return -1; // Key not found
}

int main() {
  // Initialize the hash table
  for (int i = 0; i < TABLE_SIZE; i++) {
    strcpy(hashTable[i].key, "");
    hashTable[i].value = -1;
  }

  // Insert key-value pairs into the hash table
  insert("Roshan", 22);
  insert("Bikash", 28);
  insert("Rakesh", 21);
  insert("Bishnu", 19);

  // Retrieve values by key
  printf("Roshan's age: %d\n", retrieve("Roshan"));
  printf("Bikash's age: %d\n", retrieve("Bikash"));
  printf("Anish's age: %d\n", retrieve("Anish")); // Not found

  return 0;
}
