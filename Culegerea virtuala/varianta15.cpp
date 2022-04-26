/**
 * @file varianta15.cpp
 * @author Luca Codorean 
 * @brief 
 * @version 0.1
 * @date 2022-04-26
 * 
 * @copyright Copyright (c) 2022
 * 
 *  S1: 
 *      1) nu apartine i (-20,20)U[35,150]
 *              x<= -20 || x >= 20 && x<35 || x>150
 *                                                  => R: d)
 *  `   2)  double m = (x.nota1+x.nota2)/2;
 *          if (m>=9) strcpy(x.calific, "FOARTE BINE");
 *          else if(m<9 && m>=8) strcpy(x.calific, "BINE");
 *          else if(m<=8) strcpy(x.calific, "SUFICIENT");
 *      3)  f(6,12) -> -6
 *          f(20,6) -> f(-14,19) + 3*20-2;
 *          f(-14,19) -> -33
 *          f(20,6) = - 33 + 60 - 2 = + 27 - 2 = 25
 * 
 *                       => R: -6 si 25
 *      4)  Descendentii directi ai lui 5 sunt: 2 si 4
 *          Nr frunze: 5
 *      5)  Nodurile 3,4,5 si au grad impar.    => R: d)
 * 
 * 
 *  S2:
 *      1) Daca numarul dat este format doar din cifre impare si
 *         daca oglinditul sau coincide cu numarul citit, nr1 creste, 
 *         iar daca este format doar din numere pare creste nr2
 *         se afiseaza suma dintre nr1 si nr2;
 *          a)
 *          n = 6 
 *          x = 171 => nr1 = 1;
 *          x = 22  => nr2 = 1
 *          x = 18  => nimic.
 *          x = 862 => nr2 = 2;
 *          x = 52  => nimic.
 *          x = 353 => nr1 = 2                      => R: 4
 *          nr1 + nr2 = 4
 * 
 *          b) 3, 123, 456, 789
 * 
 *          c) citeste n (numar natural nenul)
 *             nr1 <- 0; nr2 <- 0
 *             cat timp n>0 executa 
 *                  @setul de instructiuni
 *                  n <- n - 1
 *              scrie nr1+nr2
 * 
 *          d) Programul C++;
 * 
 *         2)   2,4,6,8
 *              Numerele trebuie sa fie distincte, deci 266 nu se genereaza.
 *              246
 *              248
 *              264
 *              268                                 => R: c)
 * 
 *         3)   pentru a ne referi la ultimul caracter
 *              folosim strlen(sir)-1              => R: d)
 *  S3:
 *      3) Citim numarul de referinta, dupa care primul numar din sir.
 *         Facem verificari pentru fiecare pereche de doua numere alaturate,
 *         mergand din aproape in aproape.
 * 
 *          Programul ese eficient deoarece face verificarile odata cu citirea
 *          Foloseste 4 variabile de tip integer, deci 8 bytes.
 */

#include <iostream>
#include <iomanip>

void p(int a[], int n, int& max, int &imax) {
    max = -1, imax = 0;
    for(int i = 0; i<n; i++) {
        if(a[i]>max) {
            max=a[i];
            imax = i;
        }
    }
}

void solve_ex1() {
    int n, a[50] = {0};
    std::cin>>n;

    for(int i=0; i<n; i++) {
        std::cin>>a[i];
    }

    int imax, max;
    p(a,n,max,imax);

    a[imax] = 1;
    double sum = 0;
    for(int i=0; i<n; i++) sum+=a[i];

    std::cout<<std::fixed<<std::setprecision(2)<<sum/n;
    return;
}

void solve_ex2() {
    int n, a[50][50] = {0};
    std::cin>>n;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            std::cin>>a[i][j];
        }
    }

    int cate = 0, sum = 0;

    for(int i=2; i<=n; i+=2) {
        for(int j=1; j<=n; j++) {
            if(a[i][j]>0 && i+j>n+1) {
                cate++;
                sum+=a[i][j];
            }
        }
    }

    if(cate==0) std::cout<<"NU EXISTA";
    else std::cout<<sum/cate;
    return;
}

#include <fstream>

void solve_ex3() {
    std::ifstream fin("bac.in");
    int prev_number, number, x, cate = 0;
    fin>>x>>prev_number;

    while(!fin.eof()) {
        fin>>number;

        if(number!=prev_number) {
            if(number<x && prev_number<x) {
                if(cate==5) {
                    cate = 0;
                    std::cout<<'\n';
                }
                std::cout<<'('<<prev_number<<','<<number<<") ";
                cate++;
            }
        }

        prev_number = number;
    } fin.close();
}

int main() {
    solve_ex3();
    return 0;
}