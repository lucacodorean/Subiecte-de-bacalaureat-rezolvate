#include <iostream>
#include <fstream>
using namespace std;


void shift (int size, int arr[]) {
    int valInit = arr[1];

    for(int i=1; i<size; i++){
        arr[i] = arr[i+1];
    }

    arr[size] = valInit;
    /*
        int size,data[101];
        fin>>size;
        for(int i=1; i<=size; i++) { 
            fin>>data[i];
        }
        
        int aux = 0;
        while(aux<size) {
            shift(size-aux, data);
            aux++;
        }

        for(int i=1; i<=size; i++) cout<<data[i]<<' ';
        return 0;
    */
}


struct data {
    int inceput;
    int final;
};

int main() {

    ifstream fin("A.txt");

    data intervale[1001] = {0,0};
    int axaNumere[32000] = {0};
    bool found = false;

    int size; fin>>size;
    for(int i=1; i<=size; i++) {
        fin>>intervale[i].inceput>>intervale[i].final;

        for(int numar=intervale[i].inceput; numar<=intervale[i].final; numar++) {
            axaNumere[numar]++;
        }

    } fin.close();

    bool ok;

    for(int i=1; i<=size; i++) {
       
        ok = true;
        for(int j=intervale[i].inceput; j<=intervale[i].final; j++) {
            if(axaNumere[j]!=1) ok = false;
        }

        if(ok == true) {
            cout<<intervale[i].inceput<<' '<<intervale[i].final<<endl;
            found = true;
        }
    }

    if(found == false) cout<<"NU EXISTA";

    return 0;
}