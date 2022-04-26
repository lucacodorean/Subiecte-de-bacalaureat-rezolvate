#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

ifstream fin("numere.txt");

bool progresie(int x[], int n) {
    int ratia = x[2]-x[1];
    for(int i=2; i<=n; i++) {
        if(x[i]-x[i-1]!=ratia) return false;
    }
    return true;
}
//AICI IN VS?
:// stai sa-ti arat ce am fct aseara da nu stiu daca merge ca trb sa schimb directoryu
int max(int x[], int n) {
    /*
        Exista doua posibilitati:
            1) Progresia are termenii ordonati crescator deci elementul 
            cu valoare maxima este ultimul.

            2) Progresia are termanii ordonati descrescatori deci
            elementul cu valoare maxima este primul.

            Pentru a ne da seama de natura monotoniei, comparam ratia cu 0;
            
                1) Daca ratia este mai mica decat 0 returnam x[1].
                2) Daca ratia este mai micare decat 0 returnam x[n].
    */

    int ratia = x[2]-x[1];
    if(ratia<0) return x[1];
    else if(ratia>0) return x[n];
}


int main () {
    int n,maxVal=INT_MIN;
    fin>>n;
    for(int i=1; i<=n; i++) {
        int x[101];
        for(int j=1; j<=n; j++) {
            fin>>x[j];
        }
        if(progresie(x,n)==true) {
            maxVal = max(max(x,n), maxVal);
            cout<<max(x,n)<<endl;
        }
    }
    fin.close();

    cout<<maxVal;
    return 0;
}