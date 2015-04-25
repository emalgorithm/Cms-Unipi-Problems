#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <queue>
#include <utility>
#include <functional>
#include <queue>
#include <map>
#include <set>
#include <assert.h>

#define INF 1000000005
#define MAX_N 10005
#define MAX_M 100005
#define MOD int(1e9)+7

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

void readInt(int &n){
    n = 0;
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
}   

int n, m, res, memo[MAX_M], to[MAX_M], vel[MAX_M];
vi g[MAX_N];

int dp(int edge){
    if(memo[edge] != 0)
        return memo[edge];
    int node = to[edge];
    int v = vel[edge];
    int sol = 1;
    for(int i = 0; i < g[node].size(); i++){
        int newEdge = g[node][i];
        int newV = vel[newEdge];
        if(newV > v)
            sol = max(sol, dp(newEdge) + 1);
    }
    return memo[edge] = sol;
}

int main(){
    #ifdef EVAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);

    readInt(n); readInt(m);

    for(int i = 0; i < m; i++){
        int t, t2, d;
        readInt(t); readInt(t2); readInt(d);
        to[i] = t2;
        vel[i] = d;
        g[t].push_back(i);
    }
    
    for(int i = 0; i < m; i++)
        res = max(res, dp(i));

    cout<<res;

    return 0;
}
