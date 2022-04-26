#include <iostream>
#include <fstream>
#include <cmath>
#define MAX 100
using namespace std;

ifstream fin("numere.txt");

void p(int a, int b) {

    if(a>b) swap(a,b);

    for(int number=a; number<=b; number++) {
        bool ok = true;
        int value = sqrt(number);
        for(int div=2; div<value; div++) {
            if(value % div == 0) {
                    ok = false;
            }
        }
        if(value * value == number && ok == true) cout<<number<<" ";    
    }
}

 void getSolution() {

    // Vectori caracteristici. Marcam prezenta fiecarei cifre in scriera numerelor cu 1 daca nu a mai aparut, dupa care parcurgem vectorul si afisam elementele pt care ap[i] = 1;


    int ap[MAX] = {0};
    for(int i=1, x; i<=getSize(); i++) {
        fin>>x;
        while(x>0) {
            int cifra = x % 10;
            x/=10;
            if(ap[cifra]==0) ap[cifra] = 1;
        }
    } fin.close();

    for(int i=0; i<=9; i++) if(ap[i]==1) cout<<i<<' ';
}



int main() {
    int n;
    fin>>n;
    Solution sol(n);
    sol.getSolution();
    return 0;
}