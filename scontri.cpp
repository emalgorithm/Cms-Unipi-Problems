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
#define MAX_N 500000
#define INF 99999999

int sx[MAX_N], memo[MAX_N];

int sum(int i, int j){
    int m = (i+j)/2;
    int s = (j - m) - (sx[j-1] - (m > 0 ? sx[m-1] : 0));
    int f = (sx[m-1] - (i > 0 ? sx[i-1] : 0));
    //cout<<i<<" "<<j<<" "<<f<<" "<<s<<" "<<s+f<<endl;
    return s + f;
}

int dp(int n, int N){
    if(n == N)
        return 0;
    if(memo[n] != -1)
        return memo[n];
    int sol = INF;
    for(int i=n+2;i<=N;i+=2)
        sol = min(sol, dp(i, N) + sum(n, i));
    return memo[n] = sol;
}

int Gira(int N, int *freccia){
    memset(memo, -1, sizeof memo);
    for(int i=0;i<N;i++){
        sx[i] = (i > 0 ? sx[i-1] : 0);
        if(freccia[i])
            sx[i]++;
    }
    return dp(0,N);
}


/*int main() {
    
    #ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int freccia[MAX_N], N;
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>freccia[i];
    cout<<Gira(N,freccia);
    cin>>N;
    
    return 0;
}*/

//5 1 2 1 1 1 4 2 1 2 3 2 5 4
//5 1 2 1 1 1 4 2 1 2 3 2 5 4
//6 11 -4 52 -7 -2 -20
//6 1 0 1 1 0 0
//5 4 7 -9 8 -10 
// 3 7 -1 -8


