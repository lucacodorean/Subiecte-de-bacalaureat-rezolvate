/**
 * S1: 
 *      1) b)
 *              pentru x = 4 => 25 - 4*4 = 25 - 16 = 4 >= 0 
 *              pentru x = -3 => 25 - (-3)*(-3) = 25 - 9 = 16 >= 0
 *      2)  ex(25436)
 *              X = 25436       AFISARE \ APEL
 *                                6     \   ex(2553)
 *                                3     \   ex(255)
 *                                4     \   ex(25)
 *                                5     \   ex(2)
 *                                *                 => R: 6345*     a)
 *      3) A={1,2,3,4,5}, numere care nu conţin pe poziții alăturate cifre din mulţimea {1,5}.
 *             1212 1213 1214   
 *             1221 1222 1223
 *             1224 1225
 * 
 *              2ab5
 * 
 *              2125, 2135, 2145
 *              2225, 2235, 2245,
 *              2325, 2335, 2345,
 *              2425, 2435, 2445,
 *              2525, 2535, 2545    => R: c)
 *      4)  n = 5 => n(n-1)/2 = 5*4/2 = 10 => 2^10 => R: c)
 *      5)  
 *          graf neorientat conex și aciclic. ==> GRAF HAMILTONIAN SI EULERIAN
 * 
 *          Varianta a) Nu convine pentru ca este format din doua cicluri legate prin nodul 3;
 *          Varianta b) contine un ciclu intre nodurile 1,2,3 respectiv un altul, format din nodurile 4,5,6
 *          Varianta c) contine 3 componente conexe, deci nu convine;
 *                                                                                    => R: d)
 * 
 *  S2:
 * 
 *  1)
 *      a) n = 1092744
 *      Algoritmul preia numarul si pentru fiecare cifra para, adauga cifra imapra mai mare
 *      la un rezultat.
 *              => R: 1355 
 *      b) n = ? a.i z = 7 ; n in [10,99].
 *             z = 7 => una dintre cifrele lui n este 6, iar a doua cifra este impara;
 * 
 *          n = 6a => 61, 63, 65, 67, 69
 *          n = a6 => 16, 36, 56, 76, 96
 *      c) citeste n      
 *         z <- 0; p <- 1
 *         daca n>0 atunci
 *              executa 
 *                  c <- n % 10; n <- [n/10]
 *                  daca c%2=0 atunci
 *                      z <- z+p*(c+1); p<-p*10;
 *              cat timp n!=0;
 *         scrie z
 *      d) #include <iostream>
 *         using namespace std; 
 *         int main() {
 *              int n; cin>>n;
 *              int z = 0, p =1;
 *              while(n>0) {
 *                      int c = n%10; n/=10;
 *                      if(c%2==0) {
 *                          z = z + p*(c+1); p*=10;
 *                      }
 *              }
 *              cout<<z;
 *              return 0;
 *         }
 * 
 *  2)  struct punct    { float x,y;    } A,B;
 *      Doua puncte sunt situate la aceeasi distanta fata de origine daca modulul 
 *      acestora este egal.
 *           R: sqrt(A.x*A.x + A.y*A.y) == sqrt(B.x*B.x + B.y*B.y)
 *  3)  strcpy(s,"bac2723cunota37");        Sa se ajunga la: bac2021cunota10.
 *      for(i=0;i<strlen(s);i++)
 *          if(s[i]=='3')cout<<'1';
 *          else if(s[i]=='7') cout<<'0';
 *               else cout<<s[i];
**/

/*
    S3:
     1) Folosim doua functii aditionale pentru gasirea cifrelor in numere, respectiv pentru
        eliminare, cu scopul de a nu incarca subprogramul sub cu logica nespecifica
        acestuia.

     2) Se parcurge prima coloana, dupa care elementele de pe coloanele urmatoare se determina
     adunand 1 la elementul anterior de pe aceeasi linie.

     3) b) Eficienta algoritmului consta in faptul ca elemente din fisierul de intrare sunt
     parcurse o singura data, fapt ce garanteaza o complexitate liniara in ceea ce priveste
     timpul de executie. De asemenea, din punct de vedere al memoriei, algoritmul este eficient
     deoarece foloseste 4 variabile de tip int, deci in total 16 bytes.
*/

#include <iostream>

bool search(int key, int entry) {
    while(entry>0) {
        if(entry%10==key) return true;
        entry/=10;
    }

    return false;
}

void eliminate(int index, int arr[], int&n) {
    for(int j = index; j<n-1; j++) {
        arr[j] = arr[j+1];
    }
    n--;
}

void sub(int a, int b, int v[], int&n) {
    for(int i = n; i>=0; i--) {
        bool result = (search(a,v[i]) && !search(b,v[i]));
        if(result) {
            eliminate(i,v,n);
        }
    }
}

void display(int arr[25][25], int n, int m) {
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=m; j++) {
            std::cout<<arr[i][j]<<' ';
        } std::cout<<'\n';
    }
}

void solve_ex2() {
    int n,m, a[25][25] = {0}, index = 0;
    std::cin>>n>>m;

    for(int i = 1; i<=n; i++) {
        a[i][1] = ++index;
    }

    for(int i = 1; i<=n; i++) {
        for(int j = 2; j<=m; j++) {
            a[i][j] = a[i][j-1] + 1;
        }
    }

    display(a,n,m);
}

#include <fstream>

void solve_ex3() {
    int x, x_ant, l = 0, lMax = 0;

    std::ifstream fin("bac.in");
    fin>>x_ant;
    if(x_ant%2==0) l = 1;

    while(!fin.eof()) {
        fin>>x;
        if(x%2==0 && x_ant%2==0) {
            l++;
        } else {
            lMax = std::max(lMax, l);
            if(x%2==0 || x_ant%2==0) l = 1;
            else l = 0;
        }

        x_ant = x;
    } fin.close();

    std::cout<<lMax;
}

int main() {
    solve_ex3();
    return 0;
}