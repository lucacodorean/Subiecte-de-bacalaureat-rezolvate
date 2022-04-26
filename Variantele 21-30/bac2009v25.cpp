#include <iostream>
#include <fstream>
using namespace std;

void f(int size, int arr[], int &result) {
    int prevResult = 0;
    
    int cate=0;
    for(int i=n; i>=1; i--) {
        if(a[i]%2==0) {
            prevResult *= 10;
            prevResult += a[i];
            cate++;
        }
    }

    cate>0 ? result = prevResult: result = -1;
}


int cmmdc(int a, int b) {

    short int r = 0;
    while(b!=0) {
        r = a%b;
        a = b;
        b = r;
    }

    return a;
}

int main() {

    ifstream fin("A.txt");

    /*
        Programul citeste valoarea data in fisier si o copiaza in numaratorul fractiei. Initializam numitorul cu valoarea 1 pentru ca impartirea sa aiba sens.
        
        Prin inmultirea cu aceeasi valoare atat la numitor, cat si la numarator se obtine acelasi rezultat, deci vom incerca sa mutam virgula de la numarator
        pana numaratorul devine numar natural. Pentru aceasta, inmultim numaratorul cu 10. Executam aceeasi operatie si pentru numitor pentru ca rezutlatul sa ramana
        acelasi. Calculam cmmdc-ul numitorului si al numaratorului cu scopul de a aduce fractia la o forma ireductibila.

        Impartim numaratorul si numitorul la cel mai mare divizor comun si afisam rezultatele.

    */

    double rezultat; 
    fin>>rezultat;
    fin.close();

    double numarator = rezultat;
    int numitor = 1, divizorComun;

    while(numarator != (int)numarator) {
        numarator*=10;
        numitor*=10;
    }

    divizorComun = cmmdc(numitor, numarator);
    cout<<numarator/divizorComun<<' '<<numitor/divizorComun;
    
    return 0;
}