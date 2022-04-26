/**
 * @file subiectul6.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-18
 * 
 * @copyright Copyright (c) 2022
 * 
 *  S1:
 *      1)  a = 10, b = 15
 *          150%10 = 0              0 == 50 => 0
 *          15%10 = 5 * 10 = 50                                          => a)
 *      2)      
 *              1200 noduri       -> gradul 3 => 3 descendeti fiecare    => 3600 muchii
 *              300  noduri       -> gradul 2 => 2 descendent fiecare    => 600 muchii 
 *              1    nod          -> gradul 1 => 1 descendent            => 1 muchie
 *                                                                       => R: b)
 * 
 *      3)  Un graf neorientat are n(n-1)/2 muchii.                      => R: d)
 *      4)  nr. de patru cifre, cifrele vecine sunt de paritate diferita.
 *          A = {0,1,2,3,4};
 *              
 *              1010  1030   ...   Al patrulea numar generat este 1030.          
 *              1012  1032      
 *              1014  1034                                               => R: b)
 *      5)  rec(17,2)
 *                                  afisare inainte | ar | afisare dupa
 *                                  2               17,4        3   
 *                                  4               17,5        5
 *                                                               2453   => R: b)
 *  S2:                             
 *  
 *      1)  Algoritmul determina maximul, pana la aparitia unui 0, dupa care se reseteaza.
 *          a) Pentru secventa data, se va afisa: 34, 100, 50.
 *          b) 1 1 1 0 1 1 1 0 1 1 1 0 0
 *          c) citeste a,b (numere naturale nenule)
 *             m <- a
 *             daca a>0 sau b>0 atunci
 *                  repeta
 *                     a<-b
 *                       citeste b
 *                       dacă a>m atunci m<-a
 *                       
 *                       dacă b=0 și a>0 atunci scrie m; m<-0
 *                   cat timp a>0 sau b>0
 * 
 * 
 *          d)  #include <iostream>
 *           using namespace std;
 *                int main() {
 *                     int a,b; cin>>a>>b;
 *                     int m = a;
 *                     while(a>0 || b>0) {
 *                          a = b;
 *                          cin>>b;
 *                          if(a>m) {
 *                             m = a; 
 *                          }
 *                
 *                         if(b==0 && a>0) {
 *                           cout<<m;
 *                           m = 0;
 *                         }     
 *                     }
 *                     return 0;
 *                }
 *      
 *      2)  
 *          std::cin>>m.datan.zi>>m.datan.luna>>m.datan.an;
 *          std::cin.getline(m.nume);
 *          
 *          if(m.datan.an < 2000) std::cout<<m.nume;
 *          else std::cout<<'/'<<m.datan.zi<<'/'<<m.datan.luna<<'/'<<m.datan.an;
 * 
 *      3)  pentru caracterele litera mare -> ele devin litera mica.
 *          pentru caracterele litera mica by default -> le sterge.
 *          afiseaza rezultatul.
 * 
 *          BacaLauReat => bcaLauReat
 *          bcaLaureat  => bcLauReat
 *          bcLauReat   => bcLuReat
 *          bcLuReat    => bcLureat
 *          bcLureat    => bcLurat
 *          bcLurat     => bcLura                           => bcLura
 *  S3:
 *      1)  N/A
 *      2)  Folosim doua patru subprograme: afisare, citire, gasirea primei respectiv ultimii
 *          linii care respecta cerinta impusa, pentru a elimina logica intuila.
 *      3)  Programul este eficient din punct de vedere a memoriei 
 *          deoarece foloseste doar 2 bytes. In ceea ce priveste
 *          timpul, el este eficient deoarece parcurge numerele din
 *          fisier, o singura data.
 */

#include <iostream>
#include <fstream>
#include <iomanip>

int p(int n, int x[101], int k) {
    int cate = 0, start = 0;

    for(int i=n-1; i>=0; i--) {
        if(x[i]%2==0) {
            cate++;
            start = i;
        } 
        
        if(cate==k) {
            return start;
        }
    }

    return -1;
}


void read(int arr[25][25], int sizeR, int sizeC) {
    for(int i=1; i<=sizeR; i++) {
        for(int j=1; j<=sizeC; j++) {
            std::cin>>arr[i][j];
        }
    }
}

void display(int arr[25][25], int sizeR, int sizeC) {
    for(int i=1; i<=sizeR; i++) {
        for(int j=1; j<=sizeC; j++) {
            std::cout<<arr[i][j]<<' ';
        } std::cout<<'\n';
    }
}

int get_first_line(int arr[25][25], int sizeR, int sizeC) {
    for(int i=1; i<=sizeR; i++) {
        bool ok = true;
        for(int j=1; j<=sizeC && ok == true; j++) {
            if(arr[i][j] == 0) ok = false;
        }
        if(ok == true) return i;
    }

    return 0;
}

int get_last_line(int arr[25][25], int sizeR, int sizeC) {
    for(int i=sizeR; i>=1; i--) {
        bool ok = true;
        for(int j=1; j<=sizeC && ok == true; j++) {
            if(arr[i][j] == 0) ok = false;
        }
        if(ok == true) return i;
    }

    return 0;
}

void solve_ex2(){ 
    int n,m, a[25][25] = {0};
    std::cin>>n>>m;
    read(a,n,m); std::cout<<std::endl;

    int firstLine = get_first_line(a,n,m);
    int lastLine  = get_last_line(a,n,m);
    std::swap(a[firstLine],a[lastLine]);


    display(a,n,m);
    return;
}

void solve_ex3() {
    std::fstream fin("bac.in", std::ios::in);
    int n,m; fin>>n>>m;

    for(int i=1,number; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            fin>>number;
            if(number==1) {
                std::cout<<i<<' '<<j<<';';
            }
        }
    } fin.close();

    return;
}
#include <cstring>

int main() {
   char a[31] = "BacaLauReat";
int i;
for(i=0;i<strlen(a);i++)
 if(a[i]>='A'&&a[i]<='Z')
 a[i]=a[i]+32;
 else
 {char t[31];
 strcpy(t , a + i + 1);
 strcpy(a + i , t);}
std::cout<<a;
    return 0;
}