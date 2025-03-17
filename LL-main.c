#include "LL-ADT.h"

int main() {
    // 2. Membuat List L1 dan L2
    List L1, L2;
    createList(&L1);
    createList(&L2);

    printf("Program ADT Linked List Mahasiswa\n");
    printf("=================================\n\n");
    
    // 3. Mengisi List L1 (terurut ascending berdasarkan nama)
    createNode(&L1, "Dewi Putri", 87);
    createNode(&L1, "Ali Santoso", 92);
    createNode(&L1, "Citra Mulia", 68);
    createNode(&L1, "Budi Setiawan", 75);
    createNode(&L1, "Fauzan Ahmad", 95);
    createNode(&L1, "Eko Nugroho", 73);
    createNode(&L1, "Gita Purnama", 89);
    
    // 4. Menampilkan List L1 (terurut ascending berdasarkan nama)
    printList(L1);

    // 5. Menampilkan List L1 (terurut descending berdasarkan nilai)
    printListOrdered(L1);

    // 6. Menghitung jumlah elemen pada List L1
    printf("Jumlah mahasiswa pada List L1: %d orang\n\n", getElement(L1));

    // 7. Menyalin elemen dengan nilai > 70 dari L1 ke L2
    copyList(&L1, &L2);

    // 8. Menampilkan List L2
    printList(L2);

    // 9. Menambahkan beberapa data dengan nama duplikat ke L2 untuk pengujian
    printf("Menambahkan data dengan nama duplikat ke L2 untuk pengujian...\n");
    createNode(&L2, "Ali Santoso", 82); // Duplikat nama dengan nilai berbeda
    createNode(&L2, "Dewi Putri", 90);  // Duplikat nama dengan nilai berbeda
    printf("Data duplikat berhasil ditambahkan!\n\n");

    printf("Menampilkan List L2 setelah penambahan data duplikat:\n");
    printList(L2);

    // Menghapus duplikasi nama pada List L2
    deleteDuplicate(&L2);

    // 10. Menampilkan List L2 yang baru (tanpa duplikasi)
    printList(L2);

    // 11. Menghapus List L1 dan L2
    deleteList(&L1);
    deleteList(&L2);

    // Verifikasi list telah kosong
    printf("Verifikasi List L1 setelah dihapus: %s\n",
           isListEmpty(L1) ? "Kosong" : "Tidak Kosong");
    printf("Verifikasi List L2 setelah dihapus: %s\n",
           isListEmpty(L2) ? "Kosong" : "Tidak Kosong");

    return 0;
}
