#include <iostream>
#include <fstream>

using namespace std;

class Solver{
    private:
        const int LIMIT = 1005;
        bool palindrom(int x);

    public:
        void solveExercise3();
        void solveExercise4();

};

bool Solver::palindrom(int x) {
    int lung = 0, a[10];

    bool ok = true;

    while(x>0) {
        int cifra = x%10;
        a[++lung] = cifra;
        x/=10;
    }

    if(lung%2==0) {
        for(int i=1; i<=lung/2; i++) {
            if(a[i]!=a[lung-i+1]) {
                ok = false;
                break;
            }
        }
    } else {
       for(int i=1; i<lung/2+1; i++) {
           if(a[i]!=a[lung-i+1]) {
               ok = false;
               break;
           }
       }
    }

    return ok;
}

void Solver::solveExercise3() {
    ifstream fin("data.in");
    ofstream fout("data.out");

    int x, maxim = 0, ap = 0;

    while(!fin.eof()) {
        fin>>x;

        if(palindrom(x)==true) { 
            if(x>maxim) {
                ap=0;
                maxim = x;
            } else {
                if (x==maxim) {
                    ap++;
                }
            } 
        }

    } fin.close();

    fout<<maxim<<' '<<ap;
    fout.close();
}

void Solver::solveExercise4() {

}

int main() {
    Solver problem;
    problem.solveExercise3();
    //problem.solveExercise4();

    return 0;
}
