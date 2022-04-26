/**
 * @file varianta10.cpp
 * @author Luca Codorean (luca.codorean@lapidej.ro)
 * @brief 
 * @version 0.1
 * @date 2022-04-20
 * 
 * @copyright Copyright (c) 2022
 * 
 *  S1:
 *      1)                                          => R: d)
 *      2)  f(6359) =?                              => R: b)
 *          f(6359) 
 *              c = f(635) = 9
 *          f(635)
 *              c = f(63)
 *          f(63)
 *              c = f(6)
 *          f(6)
 *              c = f(0) = 0
 *          f(0) => 0 
 *      3)  22322   23223
 *          22323   23232
 *          22332   23322
 *          22333   23233                           => R: c)
 *      4)  Frunezele sunt 1,4,6,8                  => R: c)
 *      5)  Conexitatea presupune existenta unui lant intre
 *          oricare doua noduri din graf, deci putem renunta la 
 *          3 muchii: [3,2], [3,5] si [3,4]         => R: c)
 *  
 *  S2:
 *      1) Algoritmul gaseste oglinditul numarului, dupa care
 *          pentru fiecare cifra impara, aflata pe pozitie para,
 *          o adauga la un rezultat.
 * 
 *          a) pentru n = 23758
 *              ogl = 85732                         =>  R: 28
 *          b) n = abcde a.i n la final este 4;
 *              n = 40000
 *              r = 4
 *              r>0 (A) 
 *              r%2==0 (A) => n = 4
 *              r/=100 => r =  0 stop               => R: 40000 
 *          c) citeste n 
 *             r <- 0
 *             daca n>0 atunci
 *                  repeta
 *                      r <- r*10 + n%10;
 *                      n <- [n/10]
 *                  cat timp n>0
 *              daca r>0 atunci
 *                  repeta
 *                      daca r%2==0
 *                          n <- n*10 + r%10;       
 *                      r <- [r/100]
 *                  cat timp r>0
 *              scrie n
 * 
 *          d) #include <iostream>
 *             using namespace std;
 *             int main() {
 *                  int n; cin>>n;
 *                  int r = 0;
 *                  while(n>0) {
 *                      r = r*10 + n%10;
 *                      n/=10;
 *                  }
 *                  while(r>0) {
 *                      if(r%2==0) n = n *10 + r%10;
 *                      r/=100;
 *                  }
 *                  cout<<n;
 *                  return 0;
 *              }
 *      2) ?
 *      3) calcul
 *         c 
 *         ca
 *         cal     
 *         calc
 *         calcu   
 *         calcul
 *  
 *  S3:
 *      3) Problema se bazeaza pe principiul celor doua maxime. Este eficienta deoarece, din punct de vedere
 *         al memoriei, foloseste doar doua variabile de tip int, deci 8 bytes. In ceea ce priveste timpul,
 *         complexitatea creste in raport cu numarul de elemente din fisierul de intrare. Este eficient totusi,
 *         deoarece parcurge numerele o singura data si face prelucrarea acestora odata cu citirea.                 
 */       

#include <iostream>
#include <fstream>
#include <iomanip>

int suma(int v[100], int n) {
    int s = 0;
    for(int i=0; i<n; i++) {
        if((v[i]%10)%2==0 && (v[i]/10%10)%2==0) {
            s+=v[i];
        }
    }
    return s;
}

void solve_ex2() {
    int n; std::cin>>n;
    int a[31][31] = {0};

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            a[i][j] = (i%2==0 ? (j*j) + a[i-1][j] : i*j);
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            std::cout<<a[i][j]<<' ';
        } std::cout<<'\n';
    }
}

void solve_ex3() {
    std::fstream fin("bac.in", std::ios::in);

    int firstMax = -1, secondMax = -1;
    while(!fin.eof()) {
        int number;
        fin>>number;
        if((number%10)%3==0) {
            if(number>firstMax) {
                secondMax = firstMax;
                firstMax  = number;
            } else if(number>secondMax) {
                secondMax = number;                
            } 

        }
    } fin.close();

    if(secondMax > firstMax) std::swap(firstMax,secondMax);
    std::cout<<firstMax<<' '<<secondMax;
    return;
}
