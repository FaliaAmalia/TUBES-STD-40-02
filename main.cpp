#include <iostream>
#include "parent.h"
#include "child.h"
#include "relasi.h"
using namespace std;

void menu(list_u U,list_m M,list_r R);

int main()
{
    list_u U;
    list_m M;
    list_r R;
    createlist(U);
    createlist(M);
    createlist(R);
    menu(U, M, R);
    return 0;
}
