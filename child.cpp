#include "child.h"

//1301164602//
void createlist(list_m &l){
    first(l) = NULL;
    last(l) = NULL;
}

address_m alokasi(infotype_m x){
    address_m p = new elmlist_m;
    info(p) = x;
    next(p) = NULL;
    prev(p) = NULL;
    return p;
}

void dealokasi(address_m &p){
    delete p;
}

address_m findelm(list_m l, infotype_m x){
    address_m q = first(l);
    while(q != NULL && info(q).nim != x.nim){
        q = next(q);
    }
    return q;
}

void insertfirst(list_m &l, address_m p){
    if(first(l) != NULL){
        next(p) = first(l);
        prev(first(l)) = p;
        first(l) = p;
    }
    else{
        first(l) = p;
        last(l) = p;
    }
}

void insertlast(list_m &l, address_m p){
    if(first(l) != NULL){
        prev(p) = last(l);
        next(last(l)) = p;
        last(l) = p;
    }
    else{
        insertfirst(l, p);
    }
}

void insertafter(list_m &l, address_m q, address_m p){
    if(q != NULL){
        if(next(q) != NULL){
            next(p) = next(q);
            prev(p) = q;
            prev(next(p)) = p;
            next(q) = p;
        }
        else{
            insertlast(l, p);
        }
    }
}

void deletefirst(list_m &l, address_m &p){
    if(first(l) != NULL){
        if(next(first(l)) != NULL){
            p = first(l);
            first(l) = next(p);
            prev(first(l)) = NULL;
            next(p) = NULL;
        }
        else{
            p = first(l);
            first(l) = NULL;
            last(l) = NULL;
        }
    }
}

void deletelast(list_m &l, address_m &p){
    if(first(l) != NULL){
        if(next(first(l)) != NULL){
            p = last(l);
            last(l) = prev(p);
            next(last(l)) = NULL;
            prev(p) = NULL;
        }
        else{
            deletefirst(l, p);
        }
    }
}

void deleteafter(list_m &l, address_m q, address_m &p){
    if(first(l) != NULL){
        if(q != NULL && q != last(l)){
            if(next(q) != last(l)){
                p = next(q);
                next(q) = next(p);
                prev(next(p)) = q;
                next(p) = NULL;
                prev(p) = NULL;
            }
            else{
                deletelast(l, p);
            }
        }
    }
}

void printinfo(list_m l){
    address_m q = first(l);
    if(first(l) != NULL){
        while(q != NULL){
            cout<<"     "<<info(q).nim<<" - "<<info(q).nama<<endl;
            q = next(q);
        }
    }
}
