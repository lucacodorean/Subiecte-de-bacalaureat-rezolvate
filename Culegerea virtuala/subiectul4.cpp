/**
 * @file subiectul4.cpp
 * @author Luca Codorean (luca.codorean@lapidej.ro)
 * @brief 
 * @version 0.1
 * @date 2022-04-18
 * 
 * @copyright Copyright (c) 2022
 * 
 *  S1: 
 *      1) x∈[1,5] ∪ [7,9]                                              => R: d)
 *      2) e.data_nasterii.an == 2020                                   => R: b)
 *      3) n = 4 cifre, s = 25 => a+b+c+d = 25 unde n = abcd
 *         
 *          1789        2689        3589
 *          1798        2698
 *          1879        28..
 *          1897        28..
 *          1978        29..
 *          1987        29..
 *             6           6        1   | 6 + 6 + 1 = 13  =>  3589      => R: c)
 * 
 *      4) Un graf complet cu 10 moduri are 10*9/2 = 45 muchii.
 *         45 - 32 = 13     =>  Suficient, insa nu maxim.
 *         45 - 36 = 9      =>  Doua noduri nu sunt legate direct, insa exista un lant care sa le lege.
 *         45 - 40 = 5      =>  insuficient pentru a lega 10 noduri. 
 *         45 - 9 = 36      =>  Raspuns corect, insa  m este prea mic.  => R: c)
 * 
 *      5) Toate nodurile au grad par nenul.                            => R: a)
 * 
 *  S2:
 * 
 *      1) Algoritmul preia numerele din intervalul [a,b] si numara cate dintre acestea sunt
 *      prime.
 * 
 *      a) a = 7, b = 13
 *         i |  7   8   9   10    11    12     13
 *         d |  0   4   3   5     0     6      0
 *         nr|  1   1   1   1     2     2      3        => R: 3
 * 
 *      b)  b =? daca a = 10 a.i nr = 4;
 *          
 *           i |   10  11  12  13  14  15  16  17  18  19 
 *           nr|    0   1   1   2   2   2   2   3   3   4   
 *      
 *           de la 10 la 19 -> 4 numere prime
 *                    la 22 -> 4 numere prime
 *                    la 23 -> 5 numere prime           => R: 22
 *           
 *      c)  citeste a,b (numere naturale nenule a<=b) 
 *          nr <- 0
 *          pentru i <- a, b executa
 *              d <- 0; j<-2
 *              cat timp j <= [i/2] executa
 *                  daca i % j = 0 atunci
 *                      d <- j
 *                     
 *                   j<-j+1
 *              daca d = 0 atunci nr <- nr + 1
 * 
 *          scrie nr
 * 
 * 
 *      d) #include <iostream>
 *         using namespace std;
 *         int main() {
 *             int a,b,nr = 0; cin>>a>>b;
 *             for(int i = a; i<=b; i++) {
 *                  int d = 0;
 *                  for(int j = 2; j<=i/2; j++) {
 *                      if(i%j==0) d = j;
 *                  }
 * 
 *                  if(d==0) nr++;
 *              }
 *              cout<<nr;
 *              return 0;
 *          }
 * 
 *      2)  std::cout<<(strstr(t,s) != nullptr ? "DA" : "NU");
 *      3)  f(24,2) = ?
 *              p = 2, n = 24;
 *              f(24,2) ->  2 + f(12,3) = 5
 *              f(12,3) ->  3 + f(6,4)  = 3 
 *              f(6,4)  ->  0   (pentru ca 4 > 6/2; 4 > 3 (true))       => R: 5
 * 
 *  S3:
 *      1)  N/A
 *      2)  Parcurgem coloanele in functie de paritatea liniei.
 *      3)  Folosim un vector de aparitii in care salvam numarul de aparitii a fiecarei cifre
 *          in numerele citite, dupa care parcurgem descrescator vectorul si afisam cifra de
 *          cate ori apare in vectorul de aparitii.
 * 
 *          Algoritmul are o complexitate ce creste proportional cu numarul de numere din fisierul
 *          de intrare, numere pe care le parcurge o singura data, dupa care parcruge cifrele de la
 *          9 la 0.
 *          
 *          In ceea ce priveste memoria, algoritmul foloseste 10*sizeof(int) = 40 bytes, ceea ce 
 *          ii asigura eficienta.
 */       
#include <iostream>

void cifre(int a, int& b) {
    int index = 0, p = 1;
    b = 0;
    while(a>0) {
        if(index%2!=0) {
            b = a%10*p + b;
            p*=10;
        }
        index++;
        a/=10;
    }
}

void solve_ex2() {
    int n, a[50][50] = {0}, value = 1;
    std::cin>>n;

    for(int i=1; i<=n; i++) {
        if(i%2==0) {
            for(int j=n; j>=1; j--) {
                a[i][j] = (value++);
            }
        } else {
            for(int j=1; j<=n; j++) {
                a[i][j] = (value++);
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            std::cout<<a[i][j]<<' ';
        } std::cout<<'\n';
    }
}

#include <iomanip>
#include <fstream>

void solve_ex3() {
    std::fstream fin("bac.in",      std::ios::in);
    std::fstream fout("bac.out",    std::ios::out);
    int ap[10] = {0};

    while(!fin.eof()) {
        int number;
        fin>>number;
        if(number < 10) ap[number]++;
        else {
            while(number>0) {
                ap[number%10]++;
                number/=10;
            }
        }
    } fin.close();

    for(int digit = 9; digit>=0; digit--) {
        while(ap[digit]>0) {
            fout<<digit; 
            ap[digit]--;
        }
    } fout.close();
}

int main() {
    solve_ex3();
    return 0;
}