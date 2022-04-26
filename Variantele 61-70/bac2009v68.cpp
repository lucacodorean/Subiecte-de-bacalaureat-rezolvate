#include <iostream>
#include <fstream>

using namespace std;


int calcul(int a, int k) {

    int result = -1;
    int power = 1;

    if(k==1) return a%10;

    while(k>1) {
        power*=10;
        k--;
    }

    power <= a ? result = (a/(power))%10 : result = -1;
    return result;
}

void solveExercise3() {
   //n: 4 3 2 1
   //k: 4 1 6 0
   //   k k _ k

   int n; cin>>n;
   int rank = 1;
   bool ok = true;

   while(n>0)
    {
        int digit = n%10;
        int value = calcul(n,rank);

        if(value<rank && value != -1) 
        {
            ok = false; 
            break;
        }

        n/=10;
        rank++;
    }   

    ok == true ? cout<<"Da" : cout<<"Nu";

}

void solveExercise4() {

/*
    Profitam de faptul ca elementele sunt ordonate crescator. Lungimea secventei
    creste daca valoarea anterior citita este egala cu valoarea actual citita.
    Lungimea se reseteaza daca se citeste o valoare diferita fata de valoarea anterior citita.

    Se gaseste lungimea maxima. Daca se gaseste o lugime mai mare sau egala decat maximul gasit,
    se salveaza valoarea de afisat in variabila.

*/


    ifstream fin("data.in");

    int n,x_ant, x, lung = 1, maxim = -1, element;
    fin>>n;
    fin>>x_ant;
    n--;
    
    while(n>0) {
        fin>>x;
        
        if(x==x_ant) {
            lung++;
        }
        else lung = 1;

        if(lung>=maxim) element = x;

        maxim = max(maxim, lung);
        x_ant = x;
        n--;
    } fin.close();

    cout<<maxim<<' '<<element;
}

int main() {
    Solver problem;
    //problem.solveExercise3();
    problem.solveExercise4();

    return 0;
}
