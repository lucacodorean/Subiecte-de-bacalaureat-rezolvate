#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

#define  limit  -32000

double Ecuatie(int a, int b, int c) {
    int delta = (b*b)-(4*a*c);
    double x1, radDelta;

    if (delta<0) return limit;
    
    radDelta = sqrt(delta);
    x1 = (-b+radDelta)/(2*a);

    return (x1<0 ? limit : x1);
}

void solveExercise3() {

/*
    Se observa ca sirul este format din grupuri de sume Gauss. Se foloseste
    formula sumei Gauss dupa care se urmaresc calculele.
    Odata gasita o solutie, se inlocuieste in formula dupa care se scade
    din k-ul dat rezultatul obtinut in urma inlocuirii cu scopul de a gasi
    numarul de cifre de care mai este nevoie pana a ajunge la k.
*/


    ofstream fout("data.out");

    int k; cin>>k;
    double x1 = Ecuatie(1,1,(-2*k));
    cout<<x1;
    if (x1 == (int)x1) {
        fout<<x1;
    } else {
        int g = x1;       
        fout << k - g*(g+1)/2;
    }
    fout.close();
}

int main() {
    solveExercise3();
    return 0;
}

/*
1 (1)
1 2 (3)
1 2 3 (6)
1 2 3 4 (10)
*/