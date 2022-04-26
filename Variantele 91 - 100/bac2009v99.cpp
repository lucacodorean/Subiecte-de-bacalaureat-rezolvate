#include <iostream>
#include <fstream>

using namespace std;

void Nr(int& k) {
    
    k/=10;

    int aux = k, p = 1;
    while(aux>0) {
        aux/=10;
        p*=10;
    }
    p/=10;
    k = k%p;
}


int main() {

    /*
        Problema stocheaza intr-un vector numerele citite.
        
            Se citesc initial primele doua numere pentru a putea determina 
        daca se porneste un sir de pe acestea.

            Daca paritatea numarului citit este diferita de paritatea numarului
        anterior acestuia, creste lungimea secventei, iar valoarea de stop se
        pune pe pozitia numarului citit.

            In caz contrar, se creste lungimea cu 1, pentru a baga in secventa 
        si capatul acesteia. Se compara rezultatul cu lungimea maxima.
        In cazul in care rezultatul este > lMax, lMax preia valoarea lungimii noi,
        iar pozitia de final preia valoarea pozitiei de stop a lungimii noi.
        Se reseteaza lungimea.

            Se face afisarea numerelor din vector de la  
        sfarsitul secventei- lungimea maxima + 1,
        pana la sfarsitul secventei.

            Eficienta metodei consta in faptul ca aceasta executa un numar 
        de pasi echivalent cu numarul de elemente din fisier, complexitatea 
        fiind O(n).

    */

    ifstream fin("numere.in");

    int numere[10000], position = 1,l=0;
    int x, x_ant;
    int stop_point=0, final_stop=0, lMax = -1;
    
    fin>>x_ant>>x;

    if(x%2 != x_ant%2) {
        l++;
    }

    numere[0] = x_ant;
    numere[1] = x;

    x_ant = x;
    while(!fin.eof()) {
        fin>>x;
        position++;
        numere[position] = x;

        if(x%2 != x_ant%2) {
            l++;
            stop_point = position;
        } else {
            l++;
            if(l>lMax) {
                lMax = l;
                final_stop = stop_point;
            }
            l = 0;
        }
       
        x_ant = x;
    } fin.close();

    cout<<lMax<<endl;

    for(int i=final_stop-lMax + 1; i<=final_stop; i++) {
        cout<<numere[i]<<' ';
    }

    return 0;
}