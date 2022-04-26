#include <iostream>
#include <fstream>
#include <algorithm>
#define MAX 105
using namespace std;

ifstream fin("numere.txt");

int p(int v[], int n, int k){
    int s = 0;
    for (int i = 1; i <= n; i++){
        fin >> v[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (v[i] > v[j]) swap(v[i], v[j]);
        }
    }

    for (int i = n - k + 1; i <= n; i++) {
        s += v[i];
    }

    return s;
}

void getSolution(int size) {
    int ap[MAX] = {0};
    int x;

    for (int i = 1; i <= size; i++) {
        fin >> x;
        ap[x]++;
    } fin.close();

    for (int i = 0; i < 100; i++){
        if (ap[i] == 1) cout << i << ' ';
    }
}

int main()
{
    int n;
    fin >> n;
    getSolution(n);

    return 0;
}