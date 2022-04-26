#include <iostream>
#include <fstream>
#define MAX 1005
using namespace std;

void ex3(int n, int k, int arr[])
{
    for (int i = n; i < 2 * n; i++) {
        arr[i] = arr[i - n];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = arr[i + k];
    }

    for (int i = 0; i < n; i++) cout << arr[i] << ' ';
}

int nrdiv(int number) {
    int auxd = 2, result = 0;
    if (number % auxd == 0) result++;

    while (number % auxd == 0) {
        number /= auxd;
    }

    auxd = 3;
    while (number > 1) {
        if (number % auxd == 0)
            result++;
        while (number % auxd == 0) {
            number /= auxd;
        }
        if (auxd * auxd < number) {
            auxd += 2;
        } else {
            auxd = number;
        }
    }
    return result;
}

void printSolution(int arr[], int size)
{

    int first = 0, last = 0, stop = 0;
    bool firstFound = false;
    bool lastFound = false;

    for (int i = 0; i <=size && firstFound == false; i++){
        if (nrdiv(arr[i]) % 2 == 0) {
            first = arr[i];
            firstFound = true;
            stop = i;
        }
    }

    for (int i = size - 1; i > stop && lastFound == false; i--) {
        if (nrdiv(arr[i]) % 2 == 0) {
            last = arr[i];
            lastFound = true;
        }
    }

    cout << first << ' ' << last;
}


int main()
{

    ifstream fin("A.txt");
    int n, v[100];
    fin >> n;
    for(int i=1; i<=n; i++) fin>>v[i];
    fin.close();
    printSolution(v,n);
    return 0;
}

