/**
 * @file varianta11.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-20
 * 
 * @copyright Copyright (c) 2022
 * 
 *  S1:
 *      1) daca a = 6, b = 4
 *              a%2 == 0 
 *              b%2 == 0    => 0 == 0
 *         Daca a = 6, b = 5
 *              a%2 == 0
 *              b%2 == 1    0-1 = -1 != 0
 *          a = 5, b = 7
 *              1
 *              1           1-1 == 0        => R: b)
 *      2)     f(3) -> n=2 (afiseaza 2)
 *                i = 1 => f(1) (afiseaza 1) --> 0
 *                i = 2 => f(2) (afiseaza 2)
 *                              n = 1 (afiseaza 1)
 *                                  f(1) (afiseaza 1) --> 0
 *          
 *              0101122                     => R: a)
 *      3)  
 *            ((())) 1
 *            (()()) 2
 *            (())() 3
 *            ()(()) 4
 *            ()()() 5                      => R: a)
 *            
 *      4) Un graf este conex daca are un lant care leaga oricare doua noduri.
 *          10 noduri se pot lega cu n-1 muchii     
 *          Un graf complet cu 10 noduri are 45 de muchii. (conex)
 *          45-9 = 36 => graful nu este conex
 *          36 + 1 = 37                     => R: c)
 *      5)  Pe primul nivel 2 noduri => pe nivelul 2 7 noduri ramase din 10
 *                                          => R: b)
 * 
 * 
 *  S2:
 *      1) Algoritmul determina cel mai mare
 *         patrat perfect gasit in intervalul [a,b];
 * 
 *          a) 14, 20           => R: 16
 *             i     |      14   15  16  17  18  19  20 
 *             j     |      3    3    4   4   4   4   4
 *             p     |      0    0   16   16   16   16   16
 *          
 *         b) pt a = 30 -> b apartine {30,31,...35}
 *         c) citeste a,b (numere naturale)
 *            p <- 0
 *            pentru i<-a, b executa
 *                  daca rad(i)*rad(i)=i atunci p <- i
 *            scrie p 
 * 
 *         d) #include <iostream>
 *            using namespace std;
 *            int main() {
 *                  int a,b, p = 0; cin>>a>>b;
 *                  for(int i = a; i<=b; i++) {
 *                      int j = 1; 
 *                      while(j*j<i) j++;
 *                      if(j*j==i) p = i;
 *                  }
 *                  cout<<p;
 *                  return 0;
 *            }
 * 
 *      2) std::cout<<(x>=i.a && x<=i.b ? "DA" : "NU");
 *      3)
 * 
 *         s = 0;
 *          for (j = 0; j < n; j++) {
 *              min = a[j][0];
 *               for (i = 1; i < m; i++)
 *                  if (a[j][i] < min)
 *                       min = a[j][i];
 *               s = s + min;
 *           }
 *           cout << s;
 * 
 *  S3:
 * 
 *      1)  N/A
 *      2)  Folosim subprogramul valid pentru a determina daca un cuvant gasit este 
 *          bun pentru a fi modificat. 
 *          Determinam secventele de caractere care sunt cuvinte, dupa care facem modificarea.
 *      3)  Stocam numerele intr-un array dupa care parcurgem array-ul.
 */

#include <cmath>
#include <iostream>
int radical(int limit) {
   
    for(int number = limit; number>=1; number --) {
        if(std::sqrt(number)*std::sqrt(number)==number) {
            return std::sqrt(number);
        }
    }

    return 1;
}

void solve_ex1() {
    int x; std::cin>>x;

    bool found = (radical(x)*radical(x)==x ? true : false);
    while(!found) {
        if(radical(x)*radical(x)==x) {
            found = true;
        }
        else x++;
    }

    std::cout<<x;
    return;
}

#include <cstring>

bool valid(char a, char b) {
    return (a==b || a == toupper(b) || toupper(a) == b);
}

void solve_ex2() {
    char text[256]; std::cin.getline(text,256);
    int stop = 0, start = 0;
    for(int i = 0; i<strlen(text); i++) {
        if(text[i]!=' ' && text[i] != '.' && text[i] != ',') {
            stop=i;
        } else {

            while(!isalpha(text[stop])) stop--;

            if(valid(text[start+1], text[stop])==true) {
                for(int j=start; j<=stop; j++) {
                    text[j] = toupper(text[j]);
                }
            }

            start = i;
        }
    }   

    std::cout<<text;
}

#include <fstream>

int how_many(int arr[], int size, int first, int last, int sum) {

    int result = 0;
    for(int i=first+1; i<=last; i++) {
        if(arr[first]+arr[i]<=sum) {
            result++;
        } else break;
    }
    return result;
}

void solve_ex3() {
    std::ifstream fin("bac.in");
    long long n,sum,cate = 0;
    fin>>n>>sum;

    int result[n+1] = {0};

    for(int i=1,number; i<=n; i++) {
        fin>>number;
        result[i] = number;
    } fin.close();

    int capat = n, i = 1;
    while(i<=n) {
        cate += how_many(result, n, capat--, i++,sum);
    }

    std::cout<<cate<<' ';
}

int main() {
    solve_ex3();
    return 0;
}