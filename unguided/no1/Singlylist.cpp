#include "Singlylist.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void printInfo(List L) {
    address P = L.first;

    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void deleteFirst(List &L) {
    if (L.first != Nil) {
        address P = L.first;
        L.first = P->next;
        dealokasi(P);
    }
}

void deleteLast(List &L) {
    if (L.first == Nil) return;

    address P = L.first;

    if (P->next == Nil) {
        L.first = Nil;
        dealokasi(P);
        return;
    }

    address prec = Nil;
    while (P->next != Nil) {
        prec = P;
        P = P->next;
    }

    prec->next = Nil;
    dealokasi(P);
}

void deleteAfter(List &L, address prec) {
    if (prec != Nil && prec->next != Nil) {
        address P = prec->next;
        prec->next = P->next;
        dealokasi(P);
    }
}

int nbList(List L) {
    int jumlah = 0;
    address P = L.first;

    while (P != Nil) {
        jumlah++;
        P = P->next;
    }

    return jumlah;
}

void deleteList(List &L) {
    while (L.first != Nil) {
        deleteFirst(L);
    }

    cout << "List Berhasil Terhapus" << endl;
}