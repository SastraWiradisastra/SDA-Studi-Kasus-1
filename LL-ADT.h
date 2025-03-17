#ifndef LL_ADT_h
#define LL_ADT_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// ADT utama program yang meliputi struktur utama 
// untuk menampung nilai, nama, dan next.
typedef int infotype;
typedef char* string;
typedef struct dataMahasiswa *address;
typedef struct dataMahasiswa {
	infotype nilai;
	string nama;
	address next;
} dataMahasiswa;

// ADT mendeklarasikan listnya sendiri
typedef struct List {
	address first;
} List;

// Constructor
void createList(List *list);
void createNode(List *list, string nama, infotype nilai);

// Destructor
void deleteList(List *list);
void deleteDuplicate(List *list);

// Validator
bool isListEmpty(List list);

// Getter	
int getElement(List list);

// Print
void printList(List list);
void printListOrdered(List list);

// Copy
void copyList(List *L1, List *L2);

#endif
