#include <iostream>
#include <fstream>
using namespace std;

int medie(int arr[], int size) {
    int sum = 0;
    for(int i=0; i<size; i++) {
        sum+=arr[i];
    }

    return sum/size;
}

void solveExercise3() {
    int size, numbers[9999]; 

    cin>>size;
    for(int i=0; i<size; i++) {
        cin>>numbers[i];
    }

    cout<<medie(numbers, size);
}

void solveExercise4() {

    /*
        Se citesc numerele din fisier si li se actualizeaza numarul de aparitii.
        Se afiseaza numerele pentru care valoarea din vectorul de aparitii este 1.
    */

    ifstream fin("numere.in");
    int ap[501] = {0};

    while(!fin.eof()) {
        int number;
        fin>>number;
        ap[number]++;
    } fin.close();

    for(int number=0 number<501; number++) {
        if(ap[number] == 1) cout<<number<<' ';
    }
}

int main() {
    solveExercise4();
    return 0;
}