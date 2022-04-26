#include <iostream>
#include <fstream>

using namespace std;

#define LIMIT 100000001


void inv(int a, int &b) {

    b=0;

    while(a) {
        int cifra = a%10;
        a/=10;

        b = b*10 + cifra;
    }
}

void getSolution() {

    int n; cin>>n;

    int auxL=-1, auxG=-1, step = n;

    for(int number = n; number>9; number--) {
        int x = 0;
        inv(number,x);
        if(x==number) {
            auxL=number;
            break;
        }
    }

    for(int number = n; number<=LIMIT; number++) {
        int x = 0;
        inv(number,x);
        if(x==number) {
            auxG=number;
            break;
        }   
    }

    if(auxG - n < n - auxL) cout<<auxG;
    else cout<<auxL;
}

void getSecondSolution() {

    /*
        Numerele vor fi stocate intr-un tablou unidimensional. Se ia fiecare element din tablou si se numara perechile de numbere care indeplinesc conditia:
                                                    numbers[i] = numbers[j] + numbers[k], unde i!=j && i!=k
        Rezultatul se imparte la 2 pentru ca solutia considera corecta si solutia c = a+b, insa si c= b+a;
    */


    ifstream fin("numere.in");
    int size; fin>>size;

    int numbers[101], cate = 0;

    for(int i=1; i<=size; i++) {
        fin>>numbers[i];
    } fin.close();

    for(int i=1; i<=size; i++) {
        for(int j=1; j<=size; j++) {
            for(int k=1; k<=size; k++) {
                if(numbers[i]==numbers[k]+numbers[j] && i!=j && i!=k && j!=k) cate++;
            }
        }
    }

    cout<<cate/2;
}

int main() {
    getSecondSolution();

    return 0;
}