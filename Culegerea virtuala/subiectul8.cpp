/**
 * @file subiectul8.cpp
 * @author Luca Codorean (luca.codorean@lapidej.ro)
 * @brief 
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 *  S1:
 *      1)      m=m-m/10*10
 *              1234 - 1245/10*10 = 1234 - 123*10 = 1234-1230 = 4       => R: b)
 * 
 *      2)      m[2].denumire[0]                                        => R: b)
 *              0 1 2 => a treilea element
 *              0     => primul caracter din denumire.
 *   
 *      ? 3)    1111                                                => R:     
 *              1110      
 *              1101 
 *              1011      
 *              0111     
 *              1100       
 *              1010
 *              1001
 *                          
 *      4)      Prin izolarea nodurilor 2 si 1 se renunta la 3 muchii.  => R c)
 *      5)      Numarul frunzelor este 4, deci daca frunzele sunt luate ca radacini, se obtin
 *              4 arbori pentru care numarul nodurilor terminale este 3 => R: a)
 * 
 *  S2:
 *      1)  Programul preia numerele naturale si stabileste care dintre ele este mai mare.
 *          Programul stabileste suma cifrelor numarului n pana cand ajunge la o forma irdeductibila
 *          Dupa stabilirea formei, verifica daca numarul a NU este multiplu de n.
 * 
 *          a) pentru n = 33, a = 30, b = 10
 *                  a = 10, b = 30
 *                  n = 3+3 = 6 
 *                  10%6 = 0 => nu intra in cat timp => 12<=30          => R: 1      
 * 
 *          b)  pt n = 99 => n = 9;
 *              55%9 != 0 
 *              56%9 != 0
 *              57%9 != 0
 *                  ... 
 *              63%9 == 0   => a = 63
 * 
 *              63<=b ? 1 : 0 =>  b = 55;                             => R: 55;
 * 
 *          c)  citeste n,a,b (numere naturale nenule)
 *              daca a>b atunci a<->b
 *              cat timp n>9 executa
 *                  s <- 0 
 *                  cat timp n>0 executa
 *                      s <- s+n%10
 *                      n <- [n/10]
 *                  n <- s
 *              
 *              daca a%n != 0 atunci
 *                    repeta
 *                          a <- a + 1
 *                    cat timp a%n != 0
 *              daca a<=b atunci
 *                  scrie 1
 *              altfel
 *                  scrie 0
 *          
 *          d)  #include <iostream>
 *              using namespace std;
 *              int main() {
 *                  int n,a,b; cin>>n>>a>>b;
 *                  if (a>b) swap(a,b);
 *                  while(n>9) {
 *                      int s = 0;
 *                      while(n>0) {
 *                          s += n%10;
 *                          n/=10;
 *                      }
 *                      n = s;
 *                  }
 * 
 *                  while (a%n!=0) a++;
 *                  cout<<(a<=b ? 1 : 0);
 *                  return 0;
 *              }
 * 
 *      2)  1 1 1 1 1     devine    5 5 5 5 5     
            2 2 2 2 2               2 4 4 4 2       
            3 3 3 3 3               3 3 3 3 3
            4 4 4 4 4               4 2 2 2 4 
            5 5 5 5 5               1 1 1 1 1

 *      3)  a) f(2,7,5) = ?

                a = 2, b = 7
                    => m = 4 
                     4 < 5  => f(5,6,5) = ?
                a = 5, b = 6
                    => m = 5
                     5 == 5  => 5 + 5 = 10; => f(2,7,5) = 10;

            b) c=? a. i f(4,9,c) = 10      
                4 = 2 + 2
                9 = 2 + 7
                c = 5

                a = 4, b = 9, c = 5
                    => m = 9 + 4 = 13 / 2 = 6;
                        c < m => f(4,5,5)
                a = 4, b = 5, c = 5
                    => m = 9/2 = 4
                        c > m => f(5,5,5)
                a = 5, b = 5, c = 5
                    => m = 5 = c => 5 + 5 = 10;         =>R: a) 10, b) c = 5;
 *  S3:
 *      1)  N/A
 *      2)  Folosim un algoritm care pune intr-un nou array toate vocalele gasite, dupa care prelucreaza
 *          acel array. Se verifica pentru fiecare caracter daca este egal cu un alt caracter din sir sau 
 *          daca nu este aranjat lexicografic fata de oricare alt caracter din sir.
 *      3)  Se parcurge fisierul cu numere o singura data. Pentru fiecare numar se determina daca are sau nu
 *          ultima cifra egala cu prima cifra, iar in caz afirmativ, se incrementeaza valoarea de aparitii.
 * 
 *          Programul este eficient deoarece foloseste doar 40 bytes, necesari stocarii aparitilor numerelor.
 *          In ceea ce priveste timpul de executare, programul este eficient deoarece parcruge numerele o
 *          singura data si face prelucrarea odata cu citirea. Timpul de executie creste exponential cu
 *          numarul de elemente din fisierul de intrare.
 * 
 */

#include <iostream>

int suma_x(int n, int a[100], int s) {
    int l=0, lMax = 0, curr_sum = 0;
    for(int i=1; i<=n; i++) {
        curr_sum += a[i];
        l++;
        if(curr_sum==s) {
            lMax = std::max(lMax, l);
            l = curr_sum = 0;
        }
    }

    return lMax;
}

#include <cstring>

void solve_ex2() {
    char text[250];
    std::cin.getline(text, 250);
    
    char *word = strtok(text, " ");
    while(word!=nullptr) {
        int l = 0;
        char vowels_in_word[250] = "";
        bool ok = true;
        for(int letter = 0; letter<strlen(word); letter++) {
            if(strchr("aeiou", word[letter])!=NULL) {     
                strcpy(vowels_in_word+(l++), strchr("aeiou", word[letter]));
            }
        } vowels_in_word[l++] = '\0';

        for(int i = 0; i<strlen(vowels_in_word) && ok == true; i++) {
            for(int j = i; j<=strlen(vowels_in_word); j++) {
                if(vowels_in_word[i]==vowels_in_word[j] || vowels_in_word[i]<vowels_in_word[j]) {
                    ok == false;
                    break;
                }
            }
        }

        if(ok==true) std::cout<<word<<' ';
        word = strtok(NULL, " ");
    }
    return;
}

void valid(int number, int &digit) {

    if(number<10) {
        digit = number;
        return;
    }

    int last_digit = number%10;
    number/=10;
    while (number>9) {
        number/=10;
    }

    int first_digit = number;

    if(last_digit == first_digit) {
        digit = last_digit;
    } else digit = -1;
}

#include <fstream>
#include <iomanip>

void solve_ex3() {
    std::fstream fin("bac.in", std::ios::in);
    std::fstream fout("bac.out", std::ios::out);

    int ap[10]={0};

    while(!fin.eof()) {
        int number, digit; 
        fin>>number;
        valid(number,digit);
        if(digit!=-1) ap[digit]++;
    } fin.close();

    for(int i=1; i<=9; i++) fout<<ap[i]<<' ';
    fout.close();
    return;
}

int main() {
    solve_ex3();
    return 0;
}