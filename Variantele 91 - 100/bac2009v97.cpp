#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int arr[50] = {0};
void Calcul(int k, int& s) {
    s = 0;

    for(int i = k; i<=50; i++) {
        if(arr[i]>=0) {
           s+=arr[i];
        }
    }

    /*
        ifstream fin("bac.dat");

        for(int i=1; i<=50; i++) fin>>arr[i];
        int x, y;
        cin>>x>>y;
        int s = 0;
        if(x>y) swap(x,y);

        int s_total =   0; Calcul(1,s_total);
        
        int s_de_la_x = 0; Calcul(x,s_de_la_x); int s_pana_la_x = s_total - s_de_la_x;
        int s_de_la_y = 0; Calcul(y,s_de_la_y); int s_pana_la_y = s_total - s_de_la_y;

        int s_interval = s_pana_la_y - s_pana_la_x + arr[y];

        cout<<s_interval;

    */
}


int main() {

    /*
        x patrat + y patrat = k
        deci y = radical din (k - x patrat);

        daca k - y patrat == x patrat si x <= y (pentru a evita afisarea 
                                                multipla a unei perechi)
         se afiseaza perechea.


         #mate_frate
    */

    ifstream fin("bac.txt");
    int k; fin>>k; fin.close();
    int y;
    for (int x = 1; x<sqrt(k); x++) {
        int x_power = x*x;

        y = sqrt(k - x_power);

        if(k - y * y == x_power && sqrt(x_power)<=y) {
            cout<<sqrt(x_power)<<' '<<y<<endl;
        }
    }

    return 0;
}