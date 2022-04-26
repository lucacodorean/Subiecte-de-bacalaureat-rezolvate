/** S3
 1) se generaza doar din 3,5,7 numere de forma 33333, 33335, 33339 => ultimele generari sunt: 77773, 77775, 77777
*/

#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("numere.txt");

/// EX. 3
int multiplu(int arr[], int size, int k) {
    // nr el care au u. cif == k si sunt multiplu de k.

    int result = 0;
    for(int i=1; i<=size; i++) {
        if(arr[i]%10==k && arr[i]%k == 0) result ++;
    }
    return result;

    /*int n,a[101];
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    cout<<multiplu(a,n,3);
    return 0;*/
}

/// EX. 4
int main() {
    /*
        Algoritmul se bazeaza pe folosirea vec. caracteristici. Se ia
        fiecare cifra din numerele date, dupa care se creste valoarea
        indicelui cifrei in vectorul caracteristic. Se parcurge de la 9
        la 0 vectorul pentru ca sunt 10 cifre in total, dupa care se afiseaza
        cifra cat timp valoarea lui arr[i] este diferita de 0.
    */
    int data, aparitii[10] = {0};

    while(!fin.eof()) {
        fin>>data;
        while(data>0){
            int cifra = data % 10;
            aparitii[cifra]+=1;
            data/=10;
        }
    } fin.close();

    for(int digit=9; digit>=0; digit--){
        while(aparitii[digit]>0) {
            cout<<digit;
            aparitii[digit]--;
        }
    }
    return 0;
}