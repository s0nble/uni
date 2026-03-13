#include <iostream>
using namespace std;
//A) in problem 1-7 GCD using Eculidean Algorithm
int gdcEuclidean(int a, int b) {
    while(b!=0){
        int r = a % b;
        a=b;
        b=r;
    }
    return a;
}


int gcdStein(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;

    int shift;

    for (shift = 0; ((a | b) & 1) == 0; ++shift) {
        a >>= 1;
        b >>= 1;
    }

    while ((a & 1) == 0)
        a >>= 1;

    do {
        while ((b & 1) == 0)
            b >>= 1;

        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }

        b = b - a;

    } while (b != 0);

    return a << shift;
}

int Phi(int x){
    int count = 0;
    
    for(int i=1; i<x; i++){
        if (gdcEuclidean(i, x) == 1)
        count++;
    }
    return count;
}



int main() {
    int a, b;
    /* testing for A)*/
    cout << "Enter two positive numbers";
    cin >> a >> b;
    cout << "GCD (Eculid's Algorithm) = " << gdcEuclidean(a, b) << endl;
    


    /* testing for B) */
    cout << "Enter two positive numbers: ";
    cin >> a >> b;

    cout << "GCD (Stein Algorithm) = " << gcdStein(a, b) << endl;
    

    int x;
    /* testing for C) */
    cout << "Enter a number (>=100): ";
    cin >> x;
    
    if (x < 100){
    cout << "Number must be equal to or larger than 100";
    }
    else{
    cout << "Euler Totient phi(" << x << ") = " << Phi(x) << endl;
    }
    
    












    return 0;
}