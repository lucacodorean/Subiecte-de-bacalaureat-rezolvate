#include <iostream>
#include <fstream>
#define MAX 1005
using namespace std;

void Del(int &x, int y) {
    int aux = x;
    int result = 0;
    while (aux > 0) {
        bool ok = true;
        int cifra = aux % 10;
        aux /= 10;
        if (cifra > y) {
            ok = false;
        }

        if (ok == true) {
            result = result * 10 + cifra;
        }
    }

    aux = result;
    result = 0;

    while (aux > 0) {
        result = result * 10 + aux % 10;
        aux /= 10;
    }

    x = result;
}

void inter(int &x, int &y) {
    int aux = x;
    x = y;
    y = aux;
}

void Solver()
{

    ifstream fin("numere.txt");

    int size, v[100];
    
    fin>>size;
    for (int i = 0; i < n; i++) {
        fin >> v[i];
    } fin.close();

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (v[i] > v[j]) inter(v[i], v[j]);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << v[i] << ' ';
    }
}

int main()
{
    Solver();
    return 0;
}
