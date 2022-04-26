#include <iostream>
#include <fstream>

using namespace std;


int function(int arr[], int size) {
    int s = 0;
    for(int i=0; i<size; i++) {
        if(arr[i]%10 == arr[i]/10%10) s+=arr[i];
    }

    return s;
    //int arr[] = {11,22,33,13,14};

}

void solveExercise4() {
    /*
        Se modifica valoarea minimului, maximului si aparitiile lor
        doar daca numarul se afla in intervalul [10,99].

        Daca se gaseste un numar mai mare decat maximul se reseteaza nr.
        de aparitii iar maximul se seteaza pe valoarea respectiva. 
        Acelasi lucru se intampla si in cazul minimului.

        Daca numarul citit este egal fie cu minimul, fie cu maximul, se 
        creste contorul de aparitii.
    */

    ifstream fin("numere.in");
    ofstream fout("numere.out");

    int apMax = 0, apMin = 0;
    int maxim = -1, minim = 501;

    while(!fin.eof()) {
        int number; fin>>number;

        if(number>=10 && number<=99) {
            if(number>maxim) {
                apMax = 0;
                maxim = number;
            }
            if(number<minim) {
                apMin = 0;
                minim = number;
            }
            
            if (maxim == number) {
                apMax++;
            }
            if(minim == number) {
                apMin++;
            }
        }
    } fin.close();


    fout<<maxim<<' '<<apMax<<'\n'<<minim<<' '<<apMin;
    fout.close();
}

int main() {
    solveExercise4();
    return 0;
}