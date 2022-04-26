#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int numar(int x, int y) {

    int z = x;
    for(int k = 1; k<=y; k++) {
        if(z*x>y) return z;
        z *= x;
    }

    return x;
}

int main() {
    
    /*
        INTERCLASAREA
    */

    ifstream fin("data.dat");

    int n,m, number; fin>>n>>m;
    int a[3000] = {0}, b[3000] = {0}, la = 0, lb = 0;

    for(int i=1; i<=n; i++) {
        fin>>number;
        if(number%2==0) {
            a[++la] = number;
        }
    }

    for(int i=1; i<=m; i++) {
        fin>>number;
        if(number%2==0) {
            b[++lb] = number;
        }
    } fin.close();

    int sentinela = max(b[1],a[la])+1;

    a[la+1] = b[0] = sentinela;

    if(la<lb) {
        int aux = la;
        while(aux<=lb) {
            aux++;
            a[aux] = sentinela;
        }
    } else if(lb<la){
        int aux = lb;
        while(aux<=la) {
            aux++;
            b[aux] = sentinela;
        }
    }

    int lc = la + lb, c[lc] = {0};

    for (int ic=0, ia = 1, ib = lb; ic<lc; ic++) {
        c[ic] = (a[ia] <= b[ib] ? a[ia++] : b[ib--]);
    }

    for(int i=0; i<lc; i++) cout<<c[i]<<' ';

    return 0;
}