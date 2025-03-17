#include "LL-ADT.h"

bool isListEmpty(List list)
{
	return (list.first == NULL);
}

void createList(List *list)
{
	list->first = NULL;
}

// Create and insert at the same time
void createNode(List *list, string nama, infotype nilai)
{
	printf("Membuat node baru...\n");
	address newNode = (address)malloc(sizeof(dataMahasiswa));
	address curr = (list)->first;

	if(newNode == NULL)
	{
		printf("Memory gagal dialokasikan!\n");
		exit(1);
	}

	newNode->nama = nama;
	newNode->nilai = nilai;

	if(isListEmpty(*list))
	{
		(newNode)->next = (list)->first;
		(list)->first = newNode;
		printf("Node berhasil dibuat!\n");
		return;
	}
		
	while(newNode->next != NULL && strcasecmp(newNode->nama, (curr->next)->nama) != 0)
		curr = (curr)->next;

	(newNode)->next = (curr)->next;
	(curr)->next = newNode;
	printf("Node berhasil dibuat!\n");
}

void deleteList(List *list)
{
	if(isListEmpty(*list))
	{
		printf("Tidak ada elemen untuk dihapus!\n");
		return;
	}

	address curr = (list)->first;
	address tmp;

	while(curr != NULL)
	{
		tmp = curr;
		curr = (curr)->next;
		free(tmp);
	}

	(list)->first = NULL;
}

int getElement(List list)
{
	int count = 0;
	address curr = list.first;
	
	while(curr != NULL)
	{
		count++;
		curr = (curr)->next;
	}

	return count;
}

void printList(List list)
{
	printf("\nMencoba menampilkan list...\n");
	if(isListEmpty(list))
	{
		printf("List kosong!\n");
		return;
	}

	address curr = list.first;
	int no = 1;

	printf("Daftar Mahasiswa berdasarkan nama\n");
   	printf("=========================================================\n");
    	printf("No. | Nama                 | Nilai UTS SDA \n");
    	printf("---------------------------------------------------------\n");
	while(curr != NULL)
	{
		printf("%-4d| %-21s| %-12d\n", no++, (curr)->nama, (curr)->nilai);
		curr = (curr)->next;
	}
	printf("=========================================================\n\n");
}

void printListOrdered(List list)
{
    if(isListEmpty(list))
    {
        printf("List kosong!\n");
        return;
    }

    List sortedList;
    createList(&sortedList);

    address curr = list.first;
    while(curr != NULL)
    {
        address newNode = (address)malloc(sizeof(dataMahasiswa));
        if(newNode == NULL)
        {
            printf("Memory gagal dialokasikan!\n");
            deleteList(&sortedList);
            return;
        }

        newNode->nama = curr->nama;
        newNode->nilai = curr->nilai;
        newNode->next = NULL;

        if(isListEmpty(sortedList) || curr->nilai > sortedList.first->nilai)
        {
            newNode->next = sortedList.first;
            sortedList.first = newNode;
        }
        else
        {
            address sortCurr = sortedList.first;
            while(sortCurr->next != NULL && curr->nilai <= sortCurr->next->nilai)
            {
                sortCurr = sortCurr->next;
            }

            newNode->next = sortCurr->next;
            sortCurr->next = newNode;
        }
        curr = curr->next;
    }

    printf("Daftar Mahasiswa berdasarkan nilai\n");
    address sortedCurr = sortedList.first;
    int no = 1;

    printf("=========================================================\n");
    printf("No. | Nama                 | Nilai UTS SDA \n");
    printf("---------------------------------------------------------\n");
    while(sortedCurr != NULL)
    {
        printf("%-4d| %-21s| %-12d\n", no++, sortedCurr->nama, sortedCurr->nilai);
        sortedCurr = sortedCurr->next;
    }
    printf("=========================================================\n\n");

    curr = sortedList.first;
    while(curr != NULL)
    {
        address temp = curr;
        curr = curr->next;
        free(temp); 
    }

}

void copyList(List *L1, List *L2)
{
	printf("Mencoba untuk menyalin data...\n");
	if(isListEmpty(*L1))
	{
		printf("List sumber kosong!\n");
		return;
	}

	address curr = L1->first;
	
	while(curr != NULL)
	{
		if(curr->nilai > 70)
			createNode(L2, curr->nama, curr->nilai);
		curr = curr->next;
	}
	printf("Data berhasil disalin!\n");
}

void deleteDuplicate(List *list)
{
    	if(isListEmpty(*list)) 
    	{
    		printf("List kosong!\n");
    		return;
	}

    	if((list->first)->next == NULL)
    	{
		printf("List hanya memiliki 1 elemen!\n");
		return;
	}
    
    	address curr = (list)->first;
	
	while(curr != NULL) 
	{
        	address runner = curr;
        	while(runner->next != NULL) 
		{
            		if(strcasecmp(curr->nama, runner->next->nama) == 0) 
			{
                		address dupe = (runner)->next;
                		(runner)->next = (dupe)->next;
                		free(dupe);
            		} 
			else 
                		runner = (runner)->next;
        	}
        	curr = (curr)->next;
	}
	printf("Data duplikat dalam list berhasil dihapus!\n");
}
