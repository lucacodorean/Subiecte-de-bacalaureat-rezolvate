#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double nrreal (int x, int y) {

    int p = 1, aux = y, cate = 0;
    while (aux > 0) {
        p*=10;
        aux/=10;
        cate++;
    }

    return x + (double)y/p;
}

int main () {

    /*
        Numarul de elemente intregi dintr-un interval este reprezentat de diferenta partilor intregi
        ale capetelor, dat fiind faptul ca sunt intervale deschise.

        Pentru ca fisierul contine doar numere ordonate crescator, inseamna ca pentru ca sa
        sa existe un numar mai mare de elemente decat in primul interval, diferenta dintre
        numerele vecine trebuie sa fie mai mica.

        Dat fiind faptul ca se folosesc 4 variabile algoritmul prezentat consuma 8 + 8 =
        16 octeti. De asemenea, programul executa n-1 pasi, deci complexitatea acestuia
        este O(n-1);
    */

    ifstream fin("numere.txt");

    int size, minim = INT_MAX;
    fin>>size;
    float x, x_ant;
    fin>>x_ant; size--;
    /*
        fin>>x_ant>>x;
        size-=2;
        minim = minim(x,x,ant);
    */
    while(size>0) {
        fin>>x;
        if(x==floor(x)) minim = min(minim, int(x)-int(x_ant)-1); 
        else minim = min(minim, int(x)-int(x_ant));
        x_ant = x;
        size--;
    } fin.close();


    cout<<minim;
    return 0;
}