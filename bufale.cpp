#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

struct differenza{
    long int valore,indice;
};

long int cmp(differenza const &a,differenza const &b){
    return a.valore<b.valore;
}

long long solve(int N, int* M, int* P) {
    long int i,sum=0;
    differenza differenze[N];
    for(i=0;i<N;i++){
        differenze[i].valore=M[i]-P[i];
        differenze[i].indice=i;
    }
    nth_element(differenze,differenze+(N/2),differenze+N,cmp);
    for(i=0;i<N;i++){
        if(i<N/2)
            sum+=P[differenze[i].indice];
        else
            sum+=M[differenze[i].indice];
    }
    
    return sum;
}

