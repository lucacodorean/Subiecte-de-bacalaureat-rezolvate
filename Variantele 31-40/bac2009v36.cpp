#include <iostream>
#include <fstream>
using namespace std;


/*
    Se formeaza numarul parcurgand de la 8 la 0, din doi in doi vectorul de aparatii. 
    Variabila booleana found decide daca s-a gasit sau nu solutie. In cazul afirmativ se
    returneaza numarul rezultat, iar in caz negativ se returneaza -1.
*/

int cifra(int n) {
    if(n == 0) return 0;
    int solution = -1;
    while(n>0){ 
        int cifra = n%10;
        if(cifra%2==0) {
            solution = cifra;
            break;
        }
        n/=10;
    }

    return solution;
}


int Solution() {

    ifstream fin("A.txt");

    int number = 0, limit;
    bool exists = false;
    int ap[9] = {0};

    fin>>limit;
    for(int i=1; i<=limit; i++) {
        int data;
        fin>>data;
        ap[cifra(data)]++;
    } fin.close();

    for(int i=8; i>=0; i-=2) {
        while(ap[i]>0) {
            number = number*10 + i;
            exists = true;
            ap[i]--;
        }
    }

    if(exists == true) return number;
    else return -1;
}

int main(){ 
    cout<<Solution();
    return 0;
}