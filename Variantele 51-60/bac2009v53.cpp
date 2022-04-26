#include <iostream>
#include <fstream>
using namespace std;
 
#define MAX 205

 
int cmmdc(int a, int b)
{
    if(a%b) return cmmdc(b,a%b);
    else return b;
 
    /**
 
    int n, c=0;
    cin>>n;
    for(int i=2; i<=n; i++) {
        for(int j=3; j<=n; j++) {
            if(cmmdc(i,j)==1 && i<j) c++;
        }
    }
 
    cout<<c;
    return 0;
 
    **/
}
 
int main() {
   ifstream fin("numere.txt");

   int n, v[MAX];
   fin>>n;
   for(int i=1; i<=n; i++) {
        fin>>v[i];
   } fin.close();
 
   v[n+1] = v[1];
 
   for(int i=1; i<=n; i++) {
        cout<<v[i]<<' ';
   } cout<<endl;
 
   for(int i=1; i<n; i++) {
        for(int j=1; j<=n; j++) {
            swap(v[j],v[j+1]);
            cout<<v[j]<<' ';
            v[j+1] = v[1];
        }
        cout<<endl;
   }
 
   return 0;
}