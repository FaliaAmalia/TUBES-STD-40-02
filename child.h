#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED
#include<iostream>
#include "parent.h"

#define last(l) l.last
#define prev(p) p->prev

//1301164602//
using namespace std;

struct infotype_m{
    string nama, nim, jk, jurusan, alamat, email;
    //int rating;
};

typedef struct elmlist_m *address_m;

struct elmlist_m{
    infotype_m info;
    address_m next, prev;
};

struct list_m{
    address_m first, last;
};

void createlist(list_m &l);
address_m alokasi(infotype_m x);
void dealokasi(address_m &p);
void insertfirst(list_m &l, address_m p);
void insertlast(list_m &l, address_m p);
void deletefirst(list_m &l, address_m &p);
void deletelast(list_m &l, address_m &p);
address_m findelm(list_m l, infotype_m x);
void insertafter(list_m &l, address_m q, address_m p);
void deleteafter(list_m &l, address_m q, address_m &p);
void printinfo(list_m l);
#endif // CHILD_H_INCLUDED
