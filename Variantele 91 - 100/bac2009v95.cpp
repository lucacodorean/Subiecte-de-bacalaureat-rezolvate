#include <iostream>
#include <fstream>
using namespace std;


int f(int arr[], int size) {

    int desc = 0, cresc = 0;

    for(int i = 0; i<size; i++) {
        for(int j = 0; j<size; j++) {
            if(arr[i]<arr[j]) cresc++;
            else if(arr[i]>arr[j]) desc++;
        }
    }

    if(desc>cresc) return -1;
    if(cresc>desc) return 1;

    return 0;
}

int main() {
    ofstream fout("rez.dat");

    int s; cin>>s;
    int termen = s/3;

    /*
        Fie a - numarul citit.
        Pentru ca avem nevoie de trei termeni, vom imparti numarul la 3.

        termen = a/3. Dupa, verificam daca numarul se imparte exact la 3.
        Daca se imparte, inseamna ca inmultirea a doi dintre termeni va avea
        valoare maxima, iar suma lor este s.

        Singurele resturi posibile sunt 1 sau 2,
        clasa de resturi a lui 3 fiind formata din 1 sau 2. card(Z3) = 2,
        deci exista doua cazuri. In primul caz, cand se da restul 1, se va creste
        valoarea unui singur termen, respectiv in cazul in care da restul 2, 
        se va creste valoarea a doi termeni.

    */

    if(s%3==0) {
        fout<<termen<<' '<<termen<<' '<<termen;
    } else {
        if(s%3==1) fout<<termen<<' '<<termen<<' '<<termen+1;
        if(s%3==2) fout<<termen<<' '<<termen+1<<' '<<termen+1;
    }
    fout.close();

    return 0;
}