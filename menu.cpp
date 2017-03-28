#include<iostream>
#include "parent.h"
#include "child.h"
#include "relasi.h"
#include <windows.h>

using namespace std;

void tbhukm(list_u &U);
void tbhmhs(list_m &M);
void tbhr(list_r &R, list_u U, list_m M);
void viewukm(list_u U);
void viewmhs(list_m M);
void viewr(list_r R);
void searchukm(list_u U);
void searchmhs(list_m M);
void searchr(list_r R, list_u U, list_m M);
void deleter(list_r &R, list_u U, list_m M);
void deleteukm(list_u &U, list_r &R);
void deletemhs(list_m &M, list_r &R);
void sortrelasi(list_r &l);

void menu(list_u U, list_m M, list_r R){
    int pil;
    do{
        cout<<endl;
        cout<<"                    SELAMAT DATANG"<<endl;
        cout<<"===========Relasi antara Mahasiswa dengan UKM=========="<<endl;
        cout<<endl;
        //Sleep(50);
        cout<<"1. Insert Data UKM"<<endl;
        cout<<"2. Insert Data Mahasiswa"<<endl;
        cout<<"3. View Parent"<<endl;
        cout<<"4. View Child"<<endl;
        cout<<"5. Find Parent"<<endl;
        cout<<"6. Find Child"<<endl;
        cout<<"7. Relasikan"<<endl;
        cout<<"8. View Relasi"<<endl;
        cout<<"9. Search Relasi"<<endl;
        cout<<"10. Putus Relasi"<<endl;
        cout<<"11. Delete Parent"<<endl;
        cout<<"12. Delete Child"<<endl;
        cout<<"13. Sort Relasi"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<endl;
        //Sleep(50);
        cout<<"** Masukkan Pilihan : ";
        cin>>pil;
        switch(pil){
            case 1:
                system("cls");
                tbhukm(U);
                break;
            case 2:
                system("cls");
                tbhmhs(M);
                break;
            case 3:
                system("cls");
                viewukm(U);
                break;
            case 4:
                system("cls");
                viewmhs(M);
                break;
            case 5:
                system("cls");
                searchukm(U);
                break;
            case 6:
                system("cls");
                searchmhs(M);
                break;
            case 7:
                system("cls");
                tbhr(R, U, M);
                break;
            case 8:
                system("cls");
                viewr(R);
                break;
            case 9:
                system("cls");
                searchr(R, U, M);
                break;
            case 10:
                system("cls");
                deleter(R, U, M);
                break;
            case 11:
                system("cls");
                deleteukm(U, R);
                break;
            case 12:
                system("cls");
                deletemhs(M, R);
                break;
            case 13:
                system("cls");
                sortrelasi(R);
                break;
        }
    }while(pil != 0);
    cout<<endl;
    cout<<endl;
    cout<<" Terima kasih sudah memasukkan data "<<endl;
    cout<<" Indah Ayu NF: 1301164004"<<endl;
    cout<<" Falia Amalia: 1301164602"<<endl;
    cout<<" IF-40-02 | D U A L I T Y "<<endl;
}
