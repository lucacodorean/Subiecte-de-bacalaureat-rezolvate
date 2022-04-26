#include <iostream>
#include <fstream>
using namespace std;


int numere(int n, int k) {
    
    float number;
    int result =  0;
    for(int i=1; i<=n; i++) {
        cin>>number;

        int z = 0;
        float aux = number;
        while(number != int(number)) {
            number*=10;
            z++;
        }
        
        if(z == k) result++;
    }

    return result;
}

void solveExercise4() {
    /*
        Citim cele n numere din fisier si le actualizam numarul de aparitii.
        Calculam numarul maxim de aparitii si afisam indexii pentru care numarul de aparitii
        este maxim.

        Complexitate: O(n);
    */

    ifstream fin("bac.txt");
    int n, ap[101] = {0}, maxim = -1;
    fin>>n;
    while(!fin.eof()) {
        fin>>n;
        ap[n]++;
        maxim = max(maxim, ap[n]);
    } fin.close();


    for(int number=0; number<101; number++) {
        ap[number] == maxim ? cout<<number<<' ' : cout<<"";
    }
}


int main() {
    solveExercise4();
}

// 6.2 4.234 2 8.13 10.001