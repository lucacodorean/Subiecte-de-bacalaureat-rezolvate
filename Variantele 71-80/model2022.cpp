#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
using namespace std;

int cmmdc (int x, int y) {
    return (x%y == 0 ) ? y : cmmdc(y, x%y);
}

int cmmmc(int x, int y) {
    return x*y/cmmdc(x,y);
}

int mozaic(int x, int y, int z) {
    return cmmmc(x, cmmmc(y,z));
}


void solveExercise2() {
    char* s = new char[110];
    int r[100]={0}, l = 0, firstFound = 0;
    cin.getline(s,100);
    
    char *p = new char[110];

    p = strtok(s, " ");
    while(p!=nullptr) {
        bool ok = true;
        for(int i=0; i<strlen(p); i++) {
            if(isdigit(p[i])==0) {
                ok = false;
                break;
            }
        }

        if(ok == true) {
            if (r==0) firstFound = strlen(p);
            r[++l] = strlen(p);
        }
       
        p = strtok(NULL, " ");
    }

    for(int i=1; i<=l; i++) {
        if(r[i]!=firstFound) {
            cout<<"NU";
            return;
        }
    }

    cout<<r[0];

}


struct contor {
    int aparitii, first, last;
};

int main() {
    contor data[10] = {0,0,0};
    int position=0, maxim = 1;
    ifstream fin("bac.txt");
    
    while(!fin.eof()) {
        int numar;
        fin>>numar;
        position++;

        data[numar].aparitii++;

        if(numar%2==0) {
           data[numar].aparitii==1 ? data[numar].first = position : data[numar].last = position;
           maxim=max(data[numar].last - data[numar].first + 1, maxim);
        }
      

    } fin.close();

    cout<<maxim<<endl; 

    for(int digit=0; digit<=9; digit+=2) {
        if(data[digit].last-data[digit].first + 1 == maxim) cout<<digit<<' ';
    }

    return 0;
}

/*
    nr.    5 1 3 2 4 3 3 2 8 9 7 3 4 6 8 1 2 3 4 5 6 7 9 9 8
    index: 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5

    2 | 8 - 2 + 1 = 7
        17 - 7 + 1 = 11

    4 | 13 - 5 + 1 = 7
        19 - 7 + 1 = 13
    
    6 | 21 - 14 + 1 = 8

    8 | 15 - 9 + 1 = 7
        25 - 7 + 1 = 19
*/