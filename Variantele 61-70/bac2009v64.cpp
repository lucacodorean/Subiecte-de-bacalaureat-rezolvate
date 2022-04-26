#include <iostream>
#include <fstream>

using namespace std;
#define LIMIT 1005

int diviz(int n, int a[]) {
    
    int pairs = 0;
    
    for(int i=0; i<n; i++) {
        for(int j = i+1; j<n; j++) {
            if(a[i]%a[j] == 0 || a[j]%a[i] == 0) {
                pairs++;
            }
        }
    }

    return pairs;
}

void solveExercise3() {
    
    int n = 5; 
    int a[] = {4,8,3,9,4};
    
    cout<<diviz(n,a);
}

void solveExercise4() {

/*
    Se pun elementele intr-un tablou unidimensional dupa care cauta secventa.
    Atat timp cat elementele corespund indicatiei, acestea se marcheaza cu o valoare
    egala in vectorul de secventa. De asemenea, se numara secventa cea mai lunga.
    Stop-ul se muta cat timp elementele corespund indicatiei. In caz contrar, se creste indexul
    si se reseteaza lungimea secventei.

    Se determina maximul in ceea ce priveste lungimea.

    Se afiseaza secventa.
*/


    int n=0, v[LIMIT];

    ifstream fin("text.in");
    ofstream fout("data.out");

    while(!fin.eof()) {
        fin>>v[++n];
    } fin.close();

    int actual = v[1];
    int maxim = -1, howMany = 0;
    int stop, finalStop = 0, finalSteps = 0;

    for(int i=2; i<=n; i++) {
        if(actual>v[i]) {
            howMany++;
            stop = i;
        } else {
            howMany = 0;
        }

        maxim = max(maxim, howMany);
        actual = v[i];

        if(maxim == howMany) {
            finalStop  = stop;
            finalSteps =howMany;
        }
    }
    for(int i=finalStop - finalSteps; i<=finalStop; i++) {
        fout<<v[i]<<' ';
    } fout.close();
}

int main() {
    //solveExercise3();
    solveExercise4();

    return 0;
}
