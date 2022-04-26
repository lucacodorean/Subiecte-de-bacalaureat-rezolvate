#include <iostream>
#include <fstream>
using namespace std;


int verif(int a, int b , int c) {
    return ((a>0) && (b>0) && (c>0) && (a+b>c) && (a+c)>b && (b+c)>a);

    /*
        int t1a,t1b,t1c,t2a,t2b,t2c;
        cin>>t1a>>t1b>>t1c>>t2a>>t2b>>t2c;

        bool ok = (verif(t1a,t1b,t1c) == verif(t2a,t2b,t2c));

        if(ok == true) {
            if(
                ((t1a==t2a) || (t1a==t2b) || (t1a==t2c)) && 
                ((t1b==t2a) || (t1b==t2b) || (t1b==t2c)) &&
                ((t1c==t2a) || (t1c==t2b) || (t1c==t2c))) { 
                    cout<<"Congruente";
                } else cout<<"Necongruente";
        } else cout<<"nu";
    */

}

int main() {
    
    ifstream fin("bac.dat");
    int n,m, ap[1000] = {0}, maxim = -1, solutionA, solutionB;

    fin>>n>>m;

    for(int i=1, number; i<=n; i++) {
        fin>>number;
        ap[number] = 1;
    }

    int ant,current; fin>>ant; m--;
    while(m>=0) {
        fin>>current;
        int cate = 0;
        for(int number=ant; number<=current; number++) {
            if(ap[number] == 1) {
                cate++;
            }
        }

        if(cate>maxim) {
            maxim = cate;
            solutionA = ant;
            solutionB = current;
        }
        
        ant = current;
        m--;

    } fin.close();

    cout<<solutionA<<' '<<solutionB;

    return 0;
}