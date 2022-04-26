#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int catidiv(int number){
    int cati=2;
    for(int divisor=2; divisor<number; divisor++){
        if(number%divisor==0){
            cati++;
        }
    }
    return cati;
}

int maxdiv(int limit){
    int maxim=0;
    for(int number=1; number<=limit; number++){
        maxim=max(maxim, catidiv(number));
    }
    return maxim;
}

void ex3(){
    int limit,maxim=2;
    cin>>limit;
    int target = maxdiv(limit);
    for(int i=1; i<=limit; i++){
        if(target==catidiv(i)){
            cout<<i;
            break;
        }
    }
}

void ex4(){

    /*
        Algoritmul citeste datele din fisier numar cu numar. In cazul in care numarul este impar,
        prima valoare de afisat preia valoarea ultimei valori de afisat, iar ultima valoare preia 
        valoarea numarului citit.

        Se afiseaza cele doua numere doar in cazul in care se gasesc minim doua numere de acest tip.
        In caz contrar se afiseaza mesajul sugerat.

    */

    ifstream fin("A.txt");

    int first = 0, last = 0, number;

    while(!fin.eof()){
        fin>>number;
        if(number%2!=0){
            first = last;
            last = number;
        }
    } fin.close();

    (first==0 || last == 0) ? cout<<"Numere insuficiente" : cout<<first<<' '<<last;
}

int main(){
    ex4();
    return 0;
}

