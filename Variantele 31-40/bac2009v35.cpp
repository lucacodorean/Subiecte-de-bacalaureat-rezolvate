#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#define MAX 101
using namespace std;

ifstream fin("numere.txt");

/*int main() {
    int n,x;
    fin>>n;
    for(int i=1; i<=size; i++) {
        fin>>x;
        int aux = x;
        int result = 0;
        while(aux>0) {
            result = result*10 + aux%10;
            aux/=10;
        }
        if(x % 10 == result % 10 || (x>=0 && x<=9)) cout<<x<<' ';
    }

    return 0;
}*/

int sum(int x) {
    int rad = sqrt(x), s = 0;

    for(int d=2; d<=rad; d+=1) {
        if (x%d == 0) s+=(d+x/d);
    }

    if(rad*rad==x) s-=x;

    return s;
}

struct data {
    int first,second;
} v[MAX];

bool corect(pair<int,int>a, pair<int,int>b) {
    return a.second<b.second;
}

int main() {
    int size;
    fin>>size;
    for(int i=1; i<=size; i++) {
        fin>>v[i].first;
        v[i].second = sum(v[i].first);
    }

    for(int i=1; i<=size; i++) {
        for(int j=i+1; j<n; j++) {
            if(v[i].second<v[j].second) {
                swap(v[i].first, v[j].first);
                swap(v[i].second, v[j].second);
            }
        }
    }

    for(int i=1; i<=size; i++){
        cout<<v[i].second<<' ';
    }

    return 0;
}