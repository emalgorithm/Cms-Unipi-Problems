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
#define MAX_N 505
 #define INF 99999999
int N,tot,memo[MAX_N][MAX_N],sum[MAX_N],v[MAX_N];
vi s;

int dp(int i, int j){
    //printf("%d %d\n",i,j);
    if(i == j)
        return memo[i][j] = 0;
    if(i == j - 1)
        return memo[i][j] = abs(v[i]+v[j]);
    if(memo[i][j] != -1)
        return memo[i][j];
    int sol = INF;
    for(int k=i;k<j;k++){
        int t = max(dp(i,k),dp(k+1,j));
        int sum1=sum[k]-(i == 0 ? 0 : sum[i-1]);
        int sum2= sum[j]-(k+1==0 ? 0 : sum[k]);
        t = max(t, abs(sum1+sum2));    
        //printf("%d %d %d\n",i,j,t);
        sol = min(sol, t);
    }
    return memo[i][j] = sol;
}
    

int main() {
    
    #ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    memset(memo,-1,sizeof memo);
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",v+i);
        sum[i] = v[i] + (i==0? 0 : sum[i-1]);
    }
   
    printf("%d",dp(0,N-1));
    
        cin>>N;
    return 0;
}

//3 5 4 5 3 3 2 2

//6 11 -4 52 -7 -2 -20

//5 4 7 -9 8 -10 
// 3 7 -1 -8


