/**
 * @file subiectul5.cpp
 * @author Luca Codorean (luca.codorean@lapidej.ro)
 * @brief 
 * @version 0.1
 * @date 2022-04-18
 * 
 * @copyright Copyright (c) 2022
 * 
 *  S1:
 * 
 *      1)  prima cifră a numărului n este egală cu ultima. n = abc; => n%10 = c; n/100 = a
 *          n % 10 == n/100                                                         => R: b)
 *      2)  Punctul 3D q sa aiba toate campurile initializate pe 0.                 => R: q.z = q.p.x = q.p.y = 0;
 *      3)  n cifre aflate în ordine strict crescătoare şi având prima cifră cel puțin egală cu c
 *          Pentru n = 5 si c = 3 => nr = abcde
 *      
 *              34567   34578   34678   34789               
 *              34568   34579   34679     ...
 *              34569   34589   34689     ...                                       => R: 34789
 *                  
 *      4)  Eliminam (1,3), (6,2), (6,3), (6,4) si toate gradele devin 2.           => R: d)
 *      5)  Nodul 3 nu este frunza in arbore.                                       => R: a)   
 *      
 *  S2:
 * 
 *      1)  Algoritmul preia numerele din intervalul [a,b] si le numara pe cele care sunt
 *          formate doar din cifre pare.
 * 
 *         a) pentru [201,208] se vor numara 202, 204, 206, 208                     => R: 4
 *         b) [818,b] b = ? a.i nr = 7, b = maxim.
 *              i | 820, 822, 824, 826, 828, ...   840, 842, 843, 844
 *              nr|  1    2    3    4    5          6    7    7    8                => R: 843
 *         c)   citete a,b (numere naturale, a<=b)
 *              nr <- 0
 *              cat timp a<=b executa 
 *                  d <- 1
 *                  aux <- a
 *                  cat timp aux != 0 executa
 *                      c <- aux%10
 *                      daca c%2 = 1 atunci
 *                          d<-0
 *                      aux <- [aux/10]
 *                  daca d = 1 atunci nr <- nr + 1
 *                  a <- a + 1
 *              scrie nr
 *         d)   #include <iostream>
 *              using namespace std;
 *              int main() {
 *                  int a,b,nr=0; cin>>a>>b;
 *                  for(int i=a; i<=b; i++) {
 *                      int d = 1, aux = i;
 *                      while (aux!=0) {
 *                          int c = aux%10;
 *                          if(c%2==1) d=0;
 *                          aux/=10;
 *                      }
 * 
 *                      if(d==1) nr++;
 *                  }
 *                  return 0;
 *              }
 * 
 *      2)  primul strcpy       -> s = examene
 *          strcat              -> s = exameneame
 *          al doilea strcpy    -> s = eneame                                      => R: 6
 * 
 *      3)  f(100100,1) =?                                                          => R: 4
 *          f(100100,1) = 1 + f(10010,1)=   4
 *          f(10010,1)  = 1 + f(1001,1) =   3
 *          f(1001,1)   = f(100,1)      =   2 
 *          f(100,1)    = 1 + f(10,1)   =   2
 *          f(10,1)     = 1 + f(1,1)    =   1
 *          f(1,1)      = 0
 * 
 *  S3:
 * 
 *      1)  Cel mai mare divizor propriu se obtine impartind numarul in cauza la cel mai mic 
 *          divizor propriu al acestuia.
 *      2)  Pentru a nu incarca logica subprogramului, am scris trei functii care indeplinesc 
 *          citirea, scrierea, respectiv eliminarea elementelor in cauza, subprogramul final avand
 *          rolul de a uni cele trei functii.
 *      3)  Ce este special la solutia prezentata este ca pentru a determina cel mai mic numar,
 *          trebuie sa cautam prima cifra ce apare si sa o afisam, dupa care sa facem afisarea 
 *          propriu-zisa, deoarece, un numar intreg nu poate sa inceapa cu cifra 0.
 * 
 *          Complexitatea este proportionala cu numarul de elemente din fisierul de intrare.
 *          In ceea ce memoria, algoritmul proiectat este eficient deoarece foloseste doar 40 bytes.
 */

void divp(int a, int&b, int &c) {
    b = c = 1;

    for(int divisor = 2; divisor*divisor<=a; divisor++) {
        if(a%divisor==0) {
            b = divisor;
            break;
        }
    }

    c = a/b;
}

#include <iostream>

void read(int arr[50][50], int size) {
    for(int i = 1; i<=size; i++) {
        for(int j = 1; j<=size; j++) {
            std::cin>>arr[i][j];
        }
    }
}

void display(int arr[50][50], int size) {
    for(int i=1; i<=size+1; i++) {
        for(int j =1; j<=size; j++) {
            std::cout<<arr[i][j]<<' ';
        } std::cout<<'\n';
    }
}

void clear_main_diagonal(int arr[50][50], int& size) {
    for(int i=1; i<=size; i++) {
        for(int j=1; j<=size; j++) {
            if(j>=i) {
                arr[i][j] = arr[i][j+1];
            }
        }
    }
    size--;
}

void solve_ex2() {
    int a[50][50] = {0}, n; std::cin>>n;
    read(a,n); 
    clear_main_diagonal(a,n);
    display(a,n);
}

#include <fstream>
#include <iomanip>

void solve_ex3() {
    std::fstream fin("bac.in",   std::ios::in);
    std::fstream fout("bac.out", std::ios::out);
    int ap[10] = {0};

    while(!fin.eof()) {
        int number;
        fin>>number;

        while(number>0) {
            ap[number%10]++;
            number/=10;
        }

    } fin.close();

    for(int digit = 1; digit<=9; digit++) {
        if(ap[digit]!=0) {
            fout<<digit;
            ap[digit]--;
            break;
        }
    }

    for(int digit = 0; digit<=9; digit++) {
        while(ap[digit]!=0) {
            fout<<digit;
            ap[digit]--;
        }
    } fout.close();

    return;
}

#include <iostream>

int main() {
    solve_ex3();
    return 0;
}