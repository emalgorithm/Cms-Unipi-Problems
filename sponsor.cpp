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
#include <math.h>
#include <string.h>
#include <stdlib.h> 

using namespace std;

typedef pair<int, int> ii ;
typedef vector< ii >   vii ;
typedef vector<int> vi ;
typedef vector<vi> vvi; 
typedef pair< int, string > is;

#define pb push_back 
#define MAX_N 10000
#define INF 99999999

vector< int > spon[MAX_N];

int solve(int N, int M, int* Q, int** sponsors, int* A, int* B){
    for(int i=0;i<N;i++)
        for(int j=0;j<Q[i];j++)
            spon[sponsors[i][j]-1].push_back(i);

    for(int i=0;i<M-1;i++){       
        for(int j=i+1;j<M;j++){
            int count = 0;
            for(int k=0;k<(int)spon[i].size();k++)
                if(binary_search(spon[j].begin(),spon[j].end(),spon[i][k]))
                    count++;
            if(count != 0 && count != min((int)spon[i].size(), (int)spon[j].size())){
                *A = i+1;
                *B = j+1;
                return 0;
            }
        }
    }
    return 1;
}

/*int main() {
    
    #ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    cin>>N>>M;
    
    return 0;
}*/


