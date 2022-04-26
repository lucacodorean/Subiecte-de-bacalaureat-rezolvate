#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int factoriprimi (int x)
{
    int d=2,p=0;
    while (x>1){
        p=0;
        while (x%d==0){
            p++;
            x/=d;
        }
        if (d*d<x){
            d+=2;
        }
        else{
            d=x;
        }
    }
    return p;
}

int zerouri(int number) {
    /// Proprietate: În cazul lui n!, numărul de zerouri de la final este egal cu exponentul lui 5 în descompunerea în factori.

    int p = 5, s = 0;
    while(p <= number) {
        s += number / p, p *= 5;
        cout<<s<<endl;
    }
    return s;
}

int main() {


    ifstream fin("A.txt");

    int numarIntervale, inceput, final, maxim;

    fin>>numarIntervale;
    for(int i=1; i<=numarIntervale; i++) {
        fin>>inceput>>final;

        maxim = 0;
        for(int numar=inceput; numar<=final; numar++) {
            maxim = max(maxim, factoriprimi(numar));
        }

        if(maxim > 1) cout<<pow(2,maxim)<<' ';
        else {
            if(inceput == 2 || final == 2) cout<<2<<' ';
            else cout<<0<<' ';
        }
    } fin.close();

    
    return 0;
}