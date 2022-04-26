/**
 * @file varianta12.cpp
 * @author Luca Codorean (luca.codorean@lapidej.ro)
 * @brief 
 * @version 0.1
 * @date 2022-04-21
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 *  S1:
 *      1)  1 nu apartine [3,7]
 *          1 < 3 || 1 > 7
 *          1     || 0
 *          1                   => R: d)
 * 
 *      2)  f(2,4) = ?
 *              f(2,4); x = 3
 *              f(3,4); x = 4
 *              f(4,4); afiseaza 4,4
 *          => 44...            => R: b)
 *      3) 104  221  302
 *         113  212  311
 *         131  203  320
 *         140  230             => R: b)                => GRESIT: 104 113 122 131 140 221 => R: 221.
 * 
 *      4) Un graf bipartit cu 5 noduri are 6 muchii.
 *         Graful dat are 8 muchii, deci nu este bipartit 
 *         Este conex.
 *         Are cicluci.
 *         Are varfuri cu grad impar => R: c)
 *      5) (s.A.x + s.B.x)/2    => R: d)
 *  S2:
 *      1) Algoritmul determina suma multiplilor 
 *         lui k din [1,n];
 * 
 *          a) n = 20, k  = 3;
 *             s = 3 + 6 + 9 + 12 + 15 + 18
 *             s = 9 + 9 + 30 + 15
 *             s = 18 + 45
 *             s = 63           => R: 63
 * 
 *          b) n = 25 k = ? a.i s = 60;
 *  
 *             60/25 = 12 * 5 / 25 
 *                   = 12 / 5 
 *                   = 6 * 2 / 5
 * 
 *             s = 6 + 12 + 18 + 24
 *             S = 30 + 30 
 *             S = 60           => R = 6
 * 
 *          c) Avem de aface cu o progresie aritmetica de ratie k, care incepe de la k;
 *             Toate elementele incepand de la k din k in k sunt multiplii de k.
 *              s = 3 + 6 + 9 + 12 + 15 + 18
 *              3 =     3 + 0r
 *              6 =     3 + 1r
 *              9 =     3 + 2r
 *              12 =    3 + 3r
 *              15 =    3 + 4r
 *              18 =    3 + 5r
 * 
 *              cate = [n/k]
 *              k*cate + ((cate-1)*cate)/2)*r = 18 + 45 = 63
 *              
 * 
 *              citeste n,k (numere naturale) 
 *              cate <- [n/k]
 *              s <- k*cate
 *              s <- s + (((cate-1)*cate/2)*k)
 *              scriem s
 * 
 *          d)  #include <iostream>
 *              using namespace std;
 *              int main() {
 *                  int s = 0, n,k; cin>>n>>k;
 *                  for(int i=1; i<=n; i++) {
 *                      if(i%k==0) s+=i;
 *                  }
 *                  cout<<s;
 *                  return 0;
 *              }
 *                  
 *                  
 *              V2: #include <iostream>
 *                  int main() {
 *                       int n,k; std::cin>>n>>k;
 *                       int cate = n/k;
 *                       int s = k*cate;
 *                       s += (((cate-1)*cate)/2*k);
 *                       std::cout<<s;
 *                       return 0;
 *                   }
 * 
 *      2) u = 1;
 *         for(int i = 0; i<strlen(s) && u = 1; i++) {
 *             if(s[i]==' ') {
 *                  p = i - 1; 
 *                  u = 0;      // break;
 *             }
 *         }
 * 
 *         for(int i=0; i<p; i++) {
 *            std::swap(s[i],s[p--]);
 *         }
 * 
 *      3) niv = 0;
 *         while(t[nod]!=0) {
 *              niv;
 *              nod = t[nod];
 *          }
 * 
 *  S3:
 * 
 *      1)
 *      2)  N/A
 *      3)  Programul citeste valoarea pentru variabila a, dupa care,
 *          pentru fiecare numar citit din fisier verifica daca
 *          este putere de a lui a, folosind subprogramul isPower.
 * 
 *          Eficienta este data de faptul ca se foloseste o singura parcurgere
 *          a numerelor din fisier. Timpul de executie creste in raport cu
 *          numarul de valori citite din fisierul de intrare.
 * 
 *          In ceea ce priveste memoria, algoritmul este eficient deoarece
 *          are doar o variabila de tip integer a, care foloseste 4bytes, restul
 *          variabilelor distrugandu-se odata cu incheierea instructiunilor.
 */


#include <iostream>
#include <cmath>
void desc(int n, int d, int &p, int &e) {
    e = 0;
    p = 1;
    //while(n%p!=0) p++;
    while(n%d==0) {
        e++;
        p*=d;
        n/=d;
    }
    return;
}

void solve_ex1() {
    int d = 2,x,p,e; std::cin>>x;
    while(x>1) {
        desc(x,d,p,e);
        std::cout<<d<<' '<<e<<' ';
        x/=p;  //// sau void desc(int& n, int d, int &p, int &e)
        d++;
    }
}

void read(int matrix[100][100], int sizeR, int sizeC) {
    for(int i=1; i<=sizeR; i++) {
        for(int j=1; j<=sizeC; j++) {
            std::cin>>matrix[i][j];
        }
    }
}

void display(int matrix[100][100], int sizeR, int sizeC) {
    for(int i=1; i<=sizeR; i++) {
        for(int j=1; j<=sizeC; j++) {
            std::cout<<matrix[i][j]<<' ';
        } std::cout<<'\n';
    }
}

void solve_ex2() {
    int n,m; std::cin>>m>>n;
    int matrix[100][100] = {0};
    read(matrix,m,n);
    for(int i=1; i<=m; i++) {
        int jmin, jmax, maxValue = -1, minValue = 10000;
        for(int j=1; j<=n; j++) {
            if(matrix[i][j]>maxValue) {
                jmax = j;
                maxValue = matrix[i][j];
            } else if(matrix[i][j]<minValue) {
                jmin = j;
                minValue = matrix[i][j];
            }
        }
        if(n!=jmin) std::swap(matrix[i][n], matrix[i][jmin]);
        if(1!=jmax) std::swap(matrix[i][1], matrix[i][jmax]);
    }
    display(matrix,m,n);
}

#include <fstream>
bool isPower(int number, int base) {
    while(number>1) {
        if(number%base!=0) return false;
        number/=base;
    }

    return true;
}

void solve_ex3() {
    int a; std::cin>>a;
    std::fstream fin("bac.in", std::ios::in);

    while(!fin.eof()) {
        int number, aux;
        fin>>number;
        aux=number;
        if(isPower(number,a)==true) {
            std::cout<<aux<<' ';
        }

    } fin.close();
}

int main() {
    solve_ex1();
    return 0;
}