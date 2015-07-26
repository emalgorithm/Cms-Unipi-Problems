#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>

#define MAX_N 2005

int readInt(){
    int n = 0;
    int ch = getchar_unlocked();
    int sign = 1;
    while(ch < '0' || ch > '9'){
        if(ch == '-') 
            sign = -1; 
        ch = getchar_unlocked();
    }

    while(ch >= '0' && ch <= '9'){
            n = (n << 3) + (n << 1) + ch - '0';
            ch = getchar_unlocked();
    }
    n *= sign;
    return n;
}   

   
using namespace std;

int K, N, a, prezzo[MAX_N], valMax=0;

int main(){

#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    K = readInt(); N = readInt();
    for(int i = 0; i < N; i++)
        prezzo[i] = readInt();
    
    for(int i = 0; i <= K; i++) 
        prezzo[N+i] = prezzo[N-1];
    
       for(int i = 0; i < N - 1; i++)
           for(int j = 1; j <= K; j++) {
               a = prezzo[i] - prezzo[i+j];
                 if(a <= 0){
                    a *= (-1);
                   valMax = max(valMax, a);
                 }
            }
    cout<<valMax;
    return 0;
}
