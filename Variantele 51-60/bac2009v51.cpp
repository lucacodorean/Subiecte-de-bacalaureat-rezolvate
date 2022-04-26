#include <iostream>
#include <fstream>
#include <cmath>
#define MAX 105

using namespace std;

int dist2(int xA, int yA, int xB, int yB) { return (xA-xB)*(xA-xB)+(yA-yB)*(yA-yB); }

struct Punct {
    int x, y;
};

int main() {
    Punct puncte[4];

    for(int i=0; i<4; i++) {
        cin>>puncte[i].x>>puncte[i].y;
    }  

    int distante[6],  l=0;

    for(int i=0; i<4; i++) {
        for(int j=i+1; j<4; j++) {
            distante[l++] = dist2(puncte[i].x, puncte[i].y, puncte[j].x, puncte[j].y);
        }
    }

    sort(distante, distante+l);

    cout<<(distante[4] == distante[5] && distante[0] == distante[3] ? "Da" : "Nu");
    return 0;
}

int main() {

    ifstream fin("numere.txt");

    int n, v[MAX];
    bool found = false;

    fin>>n;
    for(int i=1; i<=n; i++) {
        fin>>v[i];
    } fin.close();

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) {
            if(v[i]%2 == v[j]%2 && v[i] != v[j] && i < j) {
                cout<<v[i]<<' '<<v[j]<<endl;
                found = true;
            }
        }
    }

    if(found == false) cout<<0;

    return 0;
}