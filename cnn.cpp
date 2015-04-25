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
#define MAX_N 1000
 
int N,M, memo[2][MAX_N][MAX_N];
ii E[MAX_N];

int dp(int i,int j,int e){
    if(e == N)
        return 0;
    if(memo[i][j][e] != -1)
        return memo[i][j][e];
    int sol = 0;
    if(i==1){
        int posC = (e ? E[e-1].second : 0);
        sol = min(dp(1,j,e+1)+abs(posC-E[e].second), dp(0,posC,e+1)+abs(j-E[e].first));
    }
    else{
        int posR = (e ? E[e-1].first : 0);
        sol = min(dp(0,j,e+1)+abs(posR-E[e].first), dp(1,posR,e+1)+abs(j-E[e].second));
    }
    //printf("%d %d %d   %d\n",i,j,e,sol);
    return memo[i][j][e] = sol;
}

void print_dp(int i, int j, int e){
    if(e == N)
        return;
    if(i==1){
        int posC = (e ? E[e-1].second : 0);
        if(memo[i][j][e] == dp(1,j,e+1)+abs(posC-E[e].second)){
            printf("C\n");
            print_dp(1,j,e+1);
        }
        else if(memo[i][j][e] == dp(0,posC,e+1)+abs(j-E[e].first)){
            printf("R\n");
            print_dp(0,posC,e+1);
        }
    }
    else{
        int posR = (e ? E[e-1].first : 0);
        if(memo[i][j][e] == dp(0,j,e+1)+abs(posR-E[e].first)){
            printf("R\n");
            print_dp(0,j,e+1);
        }
        else if(memo[i][j][e] == dp(1,posR,e+1)+abs(j-E[e].second)){
            printf("C\n");
            print_dp(1,posR,e+1);
        }
    }
    
}

int main() {
    
    #ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        scanf("%d %d",&E[i].first,&E[i].second);
        E[i].first--;
        E[i].second--;
    }
    memset(memo, -1, sizeof memo);
    dp(0,0,0);
    print_dp(0,0,0);
    return 0;
}

//3 5 4 5 3 3 2 2

//7 6 4 2 5 2 6 2 4 3 4 4 4 5 4 6 



