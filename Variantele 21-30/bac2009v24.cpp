#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

ifstream fin("bac.txt");

void p(int n, int x[], int &mini, int &maxi) {
    for(int i=1; i<=n; i++) {
        mini = min(mini, x[i]);
        maxi = max(maxi, x[i]);
    }
    /*
        int vMax=0, vMin = 10000, sum=0;
        int size, data[101];
        cin>>size;
        for(int i=1; i<=size; i++) {
            cin>>data[i];
        }

        p(size,data,vMin,vMax);

        for(int i=1; i<=size; i++) {
            sum+=data[i];
        }

        sum-=(vMin+vMax);

        cout<<fixed<<setprecision(3)<<(double)s/(n-2);

        return 0;
    */
}

int main() {

    /*
        Algoritmul marcheaza intr-un vector caracteristic prezenta
        elementelor citite. Cauta in intervalul [a,b] prima aparitie = 1 si
        salveaza valoarea indicelui in variabila result.

        Se afiseaza mesajul corespunzator in functie de valoarea variabilei result.
    */

    int size, number, result = -10000, ap[30001];

    fin>>size;
    for(int i=1; i<=size; i++) {
       fin>>number;
       ap[number]=1;
    } 

    int cap1, cap2;
    fin>>cap1>>cap2;
    fin.close();

    for(int number=cap1; number<=cap2; number++){
        if(ap[number]==1){
            result = number;
            break;
        }
    }

    if(result == -10000) cout<<"NU";
    else cout<<result;

    return 0;
}