///s3

#include <iostream>
#include <fstream>
#include <algorithm>
#include <climits>
using namespace std;



int i_prim(int n) {
    int p1,p2 = n;

    for (int i = n; i >=1; i--) {
        if (n % i != 0) {
            p1 = i;
            break;  
        }
    }

    for(int i=2; i<p2; i++){
        if(p2%i == 0) {
            p2++;
            i=2;
        } 
    }

    return p2-p1;
}



struct data{
    double first;
    int second;
};

int main() {

    ifstream fin("A.txt");

    int a[10001] = {0};
    int ma = 0;

    int size,k,number;
    fin>>size>>k;

    for(int i=1; i<=size; i++) {
       fin>>a[i];
    } fin.close();

    for (int i=1; i<=k; i++) {
        ma+=a[i];
    }

    int maxim = ma;
    int result = 1;
    for (int i=2; i<=size-k+1; i++) {
        ma = ma + a[i+k-1] - a[i-1];
        result = (ma > maxim ? i : result);
        maxim = max(maxim, ma);
    }

    cout<<result;

    return 0;
}

/*

 int s = 0;
    double medieMax = -1;
    for(int i=1; i<=size-k+1; i++) {
        int start = i;
        for(int j=start; j<start+k; j++) {
            s += a[j];
        }
        ma[i].first = s/k;
        ma[i].second = start;
        s = 0;
        medieMax = max(medieMax, ma[i].first);
    }

    int minVal = INT_MAX;
    for(int i=1; i<=size-k+1; i++) {
        for(int j=i; j<=size-k+1; j++) {
            if(ma[i].first == ma[j].first && ma[i].first == medieMax) {
                minVal = min(minVal, ma[j].second);
            }
        }
    }
    
    for(int i=minVal; i<minVal+k; i++) {
        cout<<a[i]<<' ';
    } 

    fin.close();

*/