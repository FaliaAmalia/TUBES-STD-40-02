#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include<iostream>

#include "parent.h"
#include "child.h"
#include "relasi.h"

#define ukm(p) (p)->ukm
#define mahasiswa(p) (p)->mahasiswa

typedef struct elmlist_r *address_r;

using namespace std;

struct elmlist_r{
    address_r next;
    address_u ukm;
    address_m mahasiswa;
};

struct list_r{
    address_r first;
};

void createlist(list_r &l);
address_r alokasi(address_u u, address_m m);
void dealokasi(address_r &p);
void insertfirst(list_r &l, address_r p);
void insertlast(list_r &l, address_r p);
void deletefirst(list_r &l, address_r &p);
void deletelast(list_r &l, address_r &p);
address_r findelm(list_r l, address_u u, address_m m);
void insertafter(list_r &l, address_r q, address_r p);
void deleteafter(list_r &l, address_r q, address_r &p);
void printinfo(list_r l);
void sortrelasi(list_r &l);
#endif // RELASI_H_INCLUDED
