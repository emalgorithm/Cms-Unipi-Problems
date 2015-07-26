#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <utility>
#include <stdio.h>
#include <queue>
#include <fstream>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <bitset>

using namespace std;

int solve(int N, int K, int* S) {

    int sol=0,tZ=0,zL=0,zR=0,tL=0,tR=0,pR=N,pL=-1;

    while(pR>0 && tR+S[pR-1]<=K){
        if(S[pR-1]==0)
            zR++;
        tR+=S[--pR];
    }
    
    if(pR==0)
        sol=zR;
    
    else
        while(pR<=N){
            while(pL<N-1 && tR+tL+S[pL+1]<=K){
                if(S[pL+1]==0)
                    zL++;
                tL+=S[++pL];
            }
            if(zR+zL>sol)
                sol=zR+zL;
            if(pR!=N){
                if(S[pR]==0)
                    zR--;
                tR-=S[pR++]; 
            }
            else 
                pR++;                 
        }

    return sol;
}



//11 9 1 0 2 8 0 5 1 6 0 0 3










