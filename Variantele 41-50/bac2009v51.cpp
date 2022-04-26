#include <iostream>
#include <algorithm>

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


