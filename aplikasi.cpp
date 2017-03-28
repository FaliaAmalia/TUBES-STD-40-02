#include "parent.h"
#include "child.h"
#include "relasi.h"
#include <windows.h>
#include <conio.h>



void tbhukm(list_u &U){
    infotype_u x;
    address_u p, q;
    cout<<endl;
    cout<<"-------Masukkan Data UKM-------"<<endl;
    cout<<endl;
    cout<<"Masukkan ID UKM                                : ";
    cin>>x.id;
    cout<<"Masukkan Nama UKM                              : ";
    cin>>x.nama;
    cout<<"Jenis UKM (or,agama,seni,skill atau etc)       : ";
    cin>>x.jenis;
    cout<<"     Tanggal masuk UKM                         : ";
    cin>>x.tanggal;
    cout<<"     Bulan masuk UKM                           : ";
    cin>>x.bulan;
    cout<<"     Tahun masuk UKM                           : ";
    cin>>x.tahun;
    cout<<"     Status UKM (Aktif / Tidak?)               : ";
    cin>>x.status;
    p = alokasi(x);
    if(first(U) == NULL || info(first(U)).id > x.id && info(first(U)).id != x.id){
        insertfirst(U, p);
        cout<<endl;
        cout<<"     Berhasil di tambahkan"<<endl;
    }
    else{
        q = first(U);
        while(next(q) != NULL && info(next(q)).id < x.id){
            q = next(q);
        }
        if(next(q) != NULL && info(q).id != x.id){
            insertafter(U, q, p);
            cout<<endl;
            cout<<"     Berhasil di tambahkan"<<endl;
        }
        else if(info(q).id != x.id){
            insertlast(U, p);
            cout<<endl;
            cout<<"     Berhasil di tambahkan"<<endl;
        }
        if(info(first(U)).id == x.id || info(q).id == x.id){
            cout<<endl;
            cout<<"     Input gagal. Silahkan coba lagi."<<endl;
        }
    }
    getch();
    system("cls");
}

void tbhmhs(list_m &M){
    infotype_m x;
    address_m p, q;
    cout<<endl;
    cout<<"----------Masukkan Data Anggota Baru----------"<<endl;
    cout<<endl;
    cout<<" ID / NIM (4 digit terakhir)      : ";
    cin>>x.nim;
    cout<<" Nama Mahasiswa                   : ";
    cin>>x.nama;
    cout<<" Jurusan                          : ";
    cin>>x.jurusan;
    cout<<" Alamat Tempat tinggal            : ";
    cin>>x.alamat;
    cout<<" Email                            : ";
    cin>>x.email;
    cout<<" Jenis Kelamin                    : ";
    cin>>x.jk;
    p = alokasi(x);
    if(first(M) == NULL || info(first(M)).nim > x.nim && info(first(M)).nim != x.nim){
        insertfirst(M, p);
        cout<<endl;
        cout<<"     Data berhasil di input. Terimakasih."<<endl;
    }
    else{
        q = first(M);
        while(next(q) != NULL && info(next(q)).nim < x.nim){
            q = next(q);
        }
        if(next(q) != NULL && info(q).nim != x.nim){
            insertafter(M, q, p);
            cout<<endl;
            cout<<"     Added :)"<<endl;
        }
        else if(info(q).nim != x.nim){
            insertlast(M, p);
            cout<<endl;
            cout<<"     Added :)"<<endl;
        }
        if(info(first(M)).nim == x.nim || info(q).nim == x.nim){
            cout<<endl;
            cout<<"     Gagal. Silahkan coba lagi."<<endl;
        }
    }
    getch();
    system("cls");
}

void tbhr(list_r &R, list_u U, list_m M){
    infotype_u x;
    infotype_m y;
    address_u p;
    address_m q;
    address_r r;
    cout<<endl;
    cout<<"--------Tambah Relasi------"<<endl;
    cout<<endl;
    cout<<"ID UKM : ";
    cin>>x.id;
    cout<<"ID / NIM (4 digit terakhir) : ";
    cin>>y.nim;
    p = findelm(U, x);
    q = findelm(M, y);
    if(p != NULL && q != NULL){
        r = alokasi(p, q);
        if(first(R) != NULL){
            insertlast(R, r);
            cout<<endl;
            cout<<"   Berhasil dihubungkan"<<endl;
        }
        else{
            insertfirst(R, r);
            cout<<endl;
            cout<<"   Berhasil di hubungkan"<<endl;
        }
    }
    else{
        cout<<endl;
        cout<<"     Gagal. ilahkan coba lagi."<<endl;
    }
    getch();
    system("cls");
}

void viewukm(list_u U){
    cout<<endl;
    cout<<"**----------View Data UKM-----------**"<<endl;
    cout<<endl;
    if(first(U) != NULL){
        printinfo(U);
        cout<<endl;
        cout<<"   Data sudah tersimpan"<<endl;
    }
    else{
        cout<<"     Tidak ada data"<<endl;
    }
    getch();
    system("cls");
}

void viewmhs(list_m M){
    cout<<endl;
    cout<<"**----------View Data Mahasiswa----------**"<<endl;
    cout<<endl;
    if(first(M) != NULL){
        printinfo(M);
        cout<<endl;
        cout<<"     Data sudah tersimpan"<<endl;
    }
    else{
        cout<<"     Tidak ada data"<<endl;
    }
    getch();
    system("cls");
}

void viewr(list_r R){
    cout<<endl;
    cout<<"**----------View Relasi----------**"<<endl;
    cout<<endl;
    if(first(R) != NULL){
        printinfo(R);
        cout<<endl;
        cout<<"   Data sudah tersimpan"<<endl;
    }
    else{
        cout<<"   List Kosong"<<endl;
    }
    getch();
    system("cls");
}

void searchukm(list_u U){
    infotype_u x;
    address_u p;
    cout<<endl;
    cout<<"**------------Search Data UKM----------**"<<endl;
    cout<<endl;
    cout<<"Masukkan ID UKM : ";
    cin>>x.id;
    p = findelm(U, x);
    if(p != NULL){
        cout<<endl;
        cout<<"  Data ditemukan"<<endl;
        cout<<endl;
        cout<<"     Name                : "<<info(p).nama<<endl;
        cout<<"     ID                  : "<<info(p).id<<endl;
        cout<<"     Jenis UKM           : "<<info(p).jenis<<endl;
        cout<<"     Date masuk UKM      : "<<info(p).tanggal<<" - "<<info(p).bulan<<" - "<<info(p).tahun<<endl;
        //cout<<"     Tanggal masuk UKM      : "<<info(p).bulan<<endl;
        cout<<"     Status              : "<<info(p).status<<endl;
    }
    else{
        cout<<endl;
        cout<<"  Data tidak ditemukan"<<endl;
    }
    getch();
    system("cls");
}

void searchmhs(list_m M){
    infotype_m y;
    address_m q;
    cout<<endl;
    cout<<"**-----------Search Data Mahasiswa----------**"<<endl;
    cout<<endl;
    cout<<"ID / NIM (4 digit terakhir) : ";
    cin>>y.nim;
    q = findelm(M, y);
    if(q != NULL){
        cout<<endl;
        cout<<"  Data ditemukan"<<endl;
        cout<<endl;
        cout<<"     Name             :  "<<info(q).nama<<endl;
        cout<<"     ID / NIM         :  "<<info(q).nim<<endl;
        cout<<"     Jurusan          :  "<<info(q).jurusan<<endl;
        cout<<"     Jenis Kelamin    :  "<<info(q).jk<<endl;
        cout<<"     Alamat           :  "<<info(q).alamat<<endl;
        cout<<"     Email            :  "<<info(q).email<<endl;
    }
    else{
        cout<<endl;
        cout<<"  Data tidak ditemukan"<<endl;
    }
    getch();
    system("cls");
}

void searchr(list_r R, list_u U, list_m M){
    infotype_u x;
    infotype_m y;
    address_u p;
    address_m q;
    address_r r;
    cout<<endl;
    cout<<"**---------Search Relasi----------**"<<endl;
    cout<<endl;
    cout<<"ID UKM : ";
    cin>>x.id;
    cout<<"ID / NIM Mahasiswa (4 digit terakhir) : ";
    cin>>y.nim;
    p = findelm(U, x);
    q = findelm(M, y);
    if(p != NULL && q != NULL){
        r = findelm(R, p, q);
        if(r != NULL){
            cout<<endl;
            cout<<"  Data berhasil ditemukan"<<endl;
            cout<<endl;
            cout<<"     "<<info(ukm(r)).nama<<" dengan nama Mahasiswa "<<info(mahasiswa(r)).nama<<" telah direlasikan "<<endl;
        }
        else{
            cout<<endl;
            cout<<"  Pencarian gagal"<<endl;
        }
    }
    else{
        cout<<endl;
        cout<<"    Pencarian Gagal"<<endl;
    }
    getch();
    system("cls");
}

void deleter(list_r &R, list_u U, list_m M){
    infotype_u x;
    infotype_m y;
    address_u p;
    address_m q;
    address_r r, r1, rd;
    cout<<endl;
    cout<<"**-------Delete Relasi--------**"<<endl;
    cout<<endl;
    cout<<"ID UKM : ";
    cin>>x.id;
    cout<<"ID / NIM Mahasiswa (4 digit terakhir) : ";
    cin>>y.nim;
    p = findelm(U, x);
    q = findelm(M, y);
    if(p != NULL && q != NULL && first(R) != NULL){
        r = findelm(R, p, q);
        if(r == first(R)){
            deletefirst(R, r);
        }
        else if(r != first(R) && next(r) != NULL){
            r1 = r;
            r = first(R);
            while(next(r) != r1){
                r = next(r);
            }
            deleteafter(R, r, rd);
        }
        else{
            deletelast(R, r);
        }
        cout<<endl;
        cout<<" \Relasi telah dihapus/"<<endl;
    }
    else{
        cout<<endl;
        cout<<"  Tidak bisa menghapus Relasi"<<endl;
    }
    getch();
    system("cls");
}

void deleteukm(list_u &U, list_r &R){
    infotype_u x;
    address_u p, p1, p2, pd;
    address_r r, r1, r2, rd;
    cout<<endl;
    cout<<"**-------Delete Data UKM------**"<<endl;
    cout<<endl;
    cout<<"ID UKM : ";
    cin>>x.id;
    p = findelm(U, x);
    if(p != NULL && first(U) != NULL){
        r = first(R);
        while(r != NULL){
            if(ukm(r) == p && r == first(R)){
                deletefirst(R, rd);
                if(first(R) != NULL){
                    r = first(R);
                }
            }
            else if(ukm(r) == p && r != first(R)){
                r1 = r;
                r = first(R);
                r2 = first(R);
                while(next(r2) != r1){
                    r2 = next(r2);
                }
                deleteafter(R, r2, rd);
            }
            else if(ukm(r) == p && next(r) == NULL){
                deletelast(R, rd);
                r = first(R);
            }
            r = next(r);
        }
        if(p == first(U)){
            deletefirst(U, pd);
        }
        else if(p != first(U) && next(p) != NULL){
            p1 = p;
            p2 = first(U);
            while(next(p2) != p1){
                p2 = next(p2);
            }
            deleteafter(U, p2, pd);
        }
        else if(next(p) == NULL){
            deletelast(U, pd);
        }
        cout<<endl;
        cout<<"  Data selesai dihapus"<<endl;
    }
    else{
        cout<<endl;
        cout<<"  Tidak bisa menghapus data UKM"<<endl;
    }
    getch();
    system("cls");
}

void deletemhs(list_m &M, list_r &R){
    infotype_m y;
    address_m q, q1, q2, qd;
    address_r r, r1, r2, rd;
    cout<<endl;
    cout<<"**----------Delete Data Mahasiswa---------**"<<endl;
    cout<<endl;
    cout<<"ID / NIM Mahasiswa (4 digit terakhir): ";
    cin>>y.nim;
    q = findelm(M, y);
    if(q != NULL && first(M) != NULL){
        r = first(R);
        while(r != NULL){
            if(mahasiswa(r) == q && r == first(R)){
                deletefirst(R, rd);
                if(first(R) != NULL){
                    r = first(R);
                }
            }
            else if(mahasiswa(r) == q && r != first(R)){
                r1 = r;
                r = first(R);
                r2 = first(R);
                while(next(r2) != r1){
                    r2 = next(r2);
                }
                deleteafter(R, r2, rd);
            }
            else if(mahasiswa(r) == q && next(r) == NULL){
                deletelast(R, rd);
                r = first(R);
            }
            r = next(r);
        }
        if(q == first(M)){
            deletefirst(M, qd);
        }
        else if(q != first(M) && next(q) != NULL){
            q1 = q;
            q2 = first(M);
            while(next(q2) != q1){
                q2 = next(q2);
            }
            deleteafter(M, q2, qd);
        }
        else if(next(q) == NULL){
            deletelast(M, qd);
        }
        cout<<endl;
        cout<<" Data selesai dihapus"<<endl;
    }
    else{
        cout<<endl;
        cout<<" Tidak bisa menghapus data mahasiswa"<<endl;
    }
    getch();
    system("cls");
}

void sortrelasi(list_r &l) {
    address_r P,P1,P2;
    if(first(l) != NULL)
    {
        P = first(l);
        while ((P) != NULL)
        {
            if(info(ukm(P)).id > info(next(ukm(P))).id)
            {
                P2 = first(l);
                while(next(P2) != P){
                    P2 = next(P2);
                }
                deleteafter(l,P2,P);
                insertafter(l,next(P),P);
            }
            P = next(P);
        }
    }
    else
    {
        cout<<"List Relasi Kosong"<<endl;
    }
    getch();
    system("cls");
}
