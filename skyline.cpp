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
#include <string.h>
 
#define MAX_N 1000000
#define INF 99999999
#define N_CHAR 130
 
using namespace std;
 
typedef pair<int, int> ii ;
typedef vector< ii >   vii ;
typedef vector<int> vi ;

int valuta(int N, int* H){
    ii cond[MAX_N];
    int maxim=0;
    for(int i=0;i<N;i++){
        maxim = max(maxim, H[i]);
        
        if(H[i] != maxim)
            cond[i].first = 1;
        else
            cond[i].first = 0;
    }
    
    maxim = 0;
    for(int i=N-1;i>=0;i--){
        maxim = max(maxim, H[i]);
        
        if(H[i] != maxim)
            cond[i].second = 1;
        else
            cond[i].second = 0;
    }
    
    int sol = 0;
    for(int i=1;i<N-1;i++)
        if(cond[i].first == 1 && cond[i].second == 1)
            sol++;
    return sol;
}

void progetta(int N, int K, int* H){
    H[0] = MAX_N;
    H[N-1] = MAX_N + 1;
    int x = 2, y = 1;
    for(int i=1;i<N-1;i++){
        if(K-- > 0)
            H[i] = MAX_N - y++;
        else
            H[i] = MAX_N + x++;            
    }
}

int N, K, H[100000],t;
/*int main() {
    cin>>t;
    if(t){
    cin>>N>>K;
   
    progetta(N,K,H);
    for(int i=0;i<N;i++)
        cout<<H[i]<<" ";
    }
    else{
        cin>>N;
        for(int i=0;i<N;i++)
            cin>>H[i];
       cout<<valuta(N,H);
    }
    return 0;
}*/

//4 1 2 2 4 4 3 3 2 4 1 3 1

//7 6 4 2 5 2 6 2 4 3 4 4 4 5 4 6 