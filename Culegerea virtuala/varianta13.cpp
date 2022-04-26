#include <iostream>
#include <fstream>
using namespace std;

/**
 *  S1:
 *      1)  x = 8, y = 6
 *          a) 3*8 - 4*6 = 24 - 24 == 0 => 1
 *          b) (8+6)/2 > 8%6 +1
 *             7 > 3                    => 1
 *          c) !(8%2+2 ==6)
 *             2 == 6 -> !0 -> 1        => 1
 *          d) 8-6+3 != 0
 *             2 + 3 != 0
 *             5 != 0                   => 1
 *      2) e.camp si e.camp[..]                   => R: c)
 *      3) Caracterele care nu sunt vocale        => R: b)
 *      4) a,e,i,o,u
 *         aaa => uuu
 *         aae => se modifica mereu a treia pozitie.
 *                              uu_
 *         uuu -> ultima;
 *         uuo -> penultima;
 *         uui -> antepenultima;                    => R: b) 
 *      5) Eliminand muchia [1,2] il izoloam pe 1 de restul componentei.
 *         Eliminand muchia [3,7] izolam cele doua noduri unul fata de
 *         celalalt.
 * 
 *          In urma eliminarilor rezulta 3 noi C.P.
 *          3 + 2 = 5                                => R: b)
 *  S2:
 *      1) Algoritmul determina un numar format din cifrele maxime 
 *         PARE ale fiecarui numar din seria de numere citite.
 * 
 *          a) 4042 -> 2404                         => R: 2404
 *          b) n = 4 a.i 286
 *                                                  => R: 211 83 1117 610
 *         c)   citeste n (numar natrual)
 *              p <- 0
 *              cat timp n>0 executa 
 *                  y <- -1
 *                  citeste x
 *                  cat timp x!=0 executa
 *                      daca y<x%10 si x%=0 atunci
 *                          y <- x%10
 *                      x <- [x/10]
 *                  daca y!=-1 atunci p <- p*10 + y
 *                  n <- n-1
 *              scrie p
 *          d) Programul C++;
 *      2)  Graful are 3 componente conexe aciclice, deci 3 subgrafuri
 *          care respecta cerinta.
 *      3)  E(175) = ?
 *                      INAINTE DE AR | AR | DUPA AR
 *                             5        17     5
 *                             7        1      7
 *                             1        0      1
 * 
 *              =>  571175                        => R: 571175
 * 
 * 
 *  S3:
 *      1) Folosim subprogramul swap_column pentru a muta coloanele. Mutam coloane pana cand k ajunge sa fie n;
 *      2) Programul este eficient din punct de vedere al timpului de executare deoarece parcurge numerele din fisier
 *         o singura data si face validarea datelor odata cu citirea. Timpul de executie creste exponential cu numarul
 *         de numere din fisierul de intrare. Pentru datele valide se creste valoarea de aparitii din array-ul specific.
 * 
 *         Din punct de vedere al memoriei, se foloseste un array de aparitii, de tip integer, pentru 100 de numere, deci 400 de bytes,
 *         pe care, ulterior finalizarii citirii datelor, il afisam, pentru elementele diferite de 0.
*/

void swap_column(int matrix[100][100], int k, int n) {
    for(int i=1; i<=n; i++) {
        swap(matrix[i][k],matrix[i][k+1]);
    }
}

void read(int matrix[100][100], int size) {
    for(int i=1; i<size; i++) {
        for(int j=1; j<=size; j++) {
            cin>>matrix[i][j];
        }
    }
}

void display(int matrix[100][100], int size) {
    for(int i=1; i<=size; i++) {
        for(int j=1; j<=size; j++) {
            cout<<matrix[i][j]<<' ';
        } cout<<'\n';
    }
}

void solve_ex1() {
    int matrix[100][100] = {0};
    int n,k; cin>>n>>k;

    read(matrix,n);
    do {
        swap_column(matrix,k,n);
        k++;
    } while(k<=n);

    n--;
    display(matrix,n);
}

void numar(int number, int &result) {
    result = number%10;
    number/=10;
    while(number>9) {
        number/=10;
    }
    result = number*10 + result;
}

void solve_ex2() {
    int ap[100] = {0};

    ifstream fin("bac.in");
    
    while(!fin.eof()) {
        int number, result;
        fin>>number;
        if(number>=10 && number<=100) {
            numar(number, result);
            if(number==result) {
                ap[number]++;
            }
        }
    } fin.close();

    for(int number=10; number<=99; number++) {
        if(ap[number]!=0) cout<<number<<' '<<ap[number]<<endl;
    }
}

int main() {
    int x = 8, y = 6;
    cout<<(x - y + 3 != 0);
    return 0;
}