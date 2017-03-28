#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED
#include<iostream>
#define info(p) (p)->info
#define next(p) (p)->next
#define first(l) l.first

//SINGLE LINK LIST-1301164004//

using namespace std;

struct infotype_u{
    string id, nama, jenis, status;
    int tanggal, bulan, tahun;
};
typedef struct elmlist_u *address_u;

struct elmlist_u{
    infotype_u info;
    address_u next;
    };

struct list_u{
    address_u first;
    };

void createlist(list_u &l);
address_u alokasi(infotype_u x);
void dealokasi(address_u &p);
void insertfirst(list_u &l, address_u p);
void insertlast(list_u &l, address_u p);
void deletefirst(list_u &l, address_u &p);
void deletelast(list_u &l, address_u &p);
address_u findelm(list_u l, infotype_u x);
void insertafter(list_u &l, address_u q, address_u p);
void deleteafter(list_u &l, address_u q, address_u &p);
void printinfo(list_u l);
#endif // PARENT_H_INCLUDED
