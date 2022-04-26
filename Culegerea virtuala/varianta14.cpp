/**
 * @file varianta14.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-21
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 *  S1:
 *      1) x - y <= 3
 *         x, y naturale
 *          
 *         x <= 3 + y
 *          
 *          => x = y+1, y+2, y+3 
 *                                                              => R: c)
 *          
 *      2) f(325,1) = ?
 *          f(325,1) -> f(32,10) + 325
 *          f(32,10) -> f(3,100) + 320         
 *          f(3,100) -> f(0,1000) +300
 *                                ----- +
 *                                  945                         => R: b)
 * 
 *      3)  123 143         9_par_impar
 *          125 ...         distincte 
 *          127             => impar = 7; par - val max = 8
 *          129             9_par_7  => 987                    => R: c)
 * 
 * 
 *      4)  Doar nodul 3 se afla pe nivelul 2                  => R: a)
 *      5)  (1,2,4,5) este un subgraf care are suma gradelor 0 => R: c)
 *    
 *  S2:
 *      1)  Algoritmul construieste doua noi numere: 
 *              - unul cu cifrele impare
 *              - unul cu cifrele pare;
 * 
 *          Preia primele k cifre din numarul cu cifre pare
 *          si le adauga pe ultimele k cifre din numarul cu cifre
 *          impare;
 * 
 *          a)      n2 = 0  0    600   600      20600   20600 
 *                  n1 = 1  11    11   3011      3011   103011
 *                  p  = 10 100 1000   10000   100000   100000
 *      
 *                  p = 100
 * 
 *                  n2/100 = 206
 *                  n1%100 =  11        => 217
 *          
 *          b)      k = 2 -> cate numere a.i x = 0;
 * 
 * 
 *          c)  citeste n,k
 *              n1 <- 0; n2 <- 0; p <- 1
 *              daca n!=0 atunci
 *                  repeta
 *                     daca n mod 2 = 0 atunci n2 <- n2 + n mod 10*p
 *                     altfel n1 <- n1 + n mod 10*p
 *                     n <- [n/10]
 *                     p <- p*10
 *                  cat timp n!=0
 *              p <- 1
 *              pentru i<-1; k executa p <- p*10
 *              x <- [n2/p] + n1 mod p
 *              scrie x 
 *          d) Programul C++;
 * 
 *      2) s.B.x == s.A.x || (s.B.x == 0 && x.A.x == 0)
 *      3)  bool ok = false;
            int i = 0, j = 0;
            while(ok == false) {
                if(s[i]<t[j]) {
                ok = true;
                break;
                } else {
                    if(s[i]==t[j]) {
                        i++; j++;
                    }
                    if(t[j]<s[i]) {
                        ok = false;
                        break;
                    }
                }
            }
            std::cout<<(ok==true ? s : t);
 * 
 *  S3:
 *      1)  N/A
 *      2)  matrix[i][j] = (j%2==0 ? n-i+1 : i);
 *      3)  Folosim doua array-uri. Unul rezultat, in care vom pastra mereu
 *          aparitile numerelor < 10, dupa ce am incheiat o secventa, respectiv
 *          un altul in care pastram aparitile din secventa curenta.
 * 
 *          La final, parcurgem array-ul rezultat.
 */


#include <iostream>
#include <fstream>

void desc(int n, int v[], int& vf) {
    int l = 0;
    int p = 2, e = 0;
    while(n>1) {
        while(n%p!=0) p++;
        e = 0;
        while(n%p==0) {
            e++;
            n/=p;
        }
        vf++;
        v[++l] = p; v[++l] = e; 
    }
    
}

void display(int matrix[25][25], int size) {
    for(int i=1; i<=size; i++) {
        for(int j=1; j<=size; j++) {
            std::cout<<matrix[i][j]<<' ';
        } std::cout<<'\n';
    }
}

void solve_ex2() {
    int matrix[25][25] = {0};
    int n; std::cin>>n;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            matrix[i][j] = (j%2==0 ? n-i+1 : i);
        }
    }

    display(matrix, n);

}

void solve_ex3() {
    std::fstream fin("bac.in", std::ios::in);
    int ap[10] = {0}, result[10] = {0};
    while(!fin.eof()) {
        int number;
        fin>>number;
        if(number < 10) {
            ap[number]++;
        } else {
            bool ok = false;

            for(int i=0; i<10 && ok == false; i++) {
                if(ap[i]!=0) ok = true;
            }

            if(ok==true) {
                 for(int i=0; i<10; i++) {
                    result[i] = ap[i];
                    ap[i] = 0;
                }
            }
        }
    } fin.close();

    for(int i=0; i<10; i++) {
        while(result[i]>0) {
            std::cout<<i<<' ';
            result[i]--;
        }
    }

    return;
}

int main() {
    char s[31] = "ALIN", t[31] = "LUCA-ANDREI";
        bool ok = false;
        int i = 0, j = 0;
        while(ok == false) {
            if(s[i]<t[j]) {
               ok = true;
               break;
            } else {
                if(s[i]==t[j]) {
                    i++; j++;
                }
                if(t[j]<s[i]) {
                    ok = false;
                    break;
                }
            }
        }
  
        std::cout<<(ok==true ? s : t);
}