#include "parent.h"
//SINGLE LINK LIST-1301164004//

void createlist(list_u &l){
    first(l) = NULL;
}

address_u alokasi(infotype_u x){
    address_u p = new elmlist_u;
    info(p) = x;
    next(p) = NULL;
    return p;
}

void dealokasi(address_u &p){
    delete p;
}

void insertfirst(list_u &l, address_u p){
    if(first(l) != NULL){
        next(p) = first(l);
        first(l) = p;
    }
    else{
        first(l) = p;
    }
}

void insertlast(list_u &l, address_u p){
    address_u q;
    if(first(l) != NULL){
        q = first(l);
        while(next(q) != NULL){
            q = next(q);
        }
        next(q) = p;
    }
    else{
        insertfirst(l, p);
    }
}

void deletefirst(list_u &l, address_u &p){
    if(first(l) != NULL){
        if(next(first(l)) != NULL){
        p = first(l);
        first(l) = next(p);
        next(p) = NULL;
        dealokasi(p);
        }
        else{
            p = first(l);
            first(l) = NULL;
            dealokasi(p);
        }
    }
}

void deletelast(list_u &l, address_u &p){
    address_u q;
    if(first(l) != NULL){
        if(next(first(l)) != NULL){
            q = first(l);
            while(next(next(q)) != NULL){
                q = next(q);
            }
            p = next(q);
            next(q) = NULL;
            dealokasi(p);
        }
        else{
            deletefirst(l, p);
        }
    }
}

address_u findelm(list_u l, infotype_u x){
    address_u q;
    q = first(l);
    while(q != NULL && info(q).id != x.id){
        q = next(q);
    }
    return q;
}

void insertafter(list_u &l, address_u q, address_u p){
    if(first(l) != NULL){
        next(p) = next(q);
        next(q) = p;
    }
    else{
        insertfirst(l, p);
    }
}

void deleteafter(list_u &l, address_u q, address_u &p){
    if(first(l) != NULL){
        if(next(first(l)) != NULL){
            p = next(q);
            next(q) = next(p);
            next(p) = NULL;
            dealokasi(p);
        }
        else{
            deletefirst(l, p);
        }
    }
}

void printinfo(list_u l){
    address_u q;
    if(first(l) != NULL){
        q = first(l);
        while(q != NULL){
            cout<<"     "<<info(q).id<<" - "<<info(q).nama<<endl;
            q = next(q);
        }
    }
}
