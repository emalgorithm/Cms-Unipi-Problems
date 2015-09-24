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
#define MAX_N 20005
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

int n, m, sol, used[MAX_N];
bool existSol = true;
vi g[MAX_N];

int dfs(int p){
    used[p] = 1;
    sol++;
    if(g[p].empty())
        existSol = false;
    for(int i = 0; i < g[p].size(); i++)
        if(used[g[p][i]] == 0)
            dfs(g[p][i]);
}

int main(){
    #ifdef EVAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);

    readInt(n); readInt(m);

    for(int i = 0; i < n; i++){
        int t;
        readInt(t);
        t--;
        used[t] = 1;
    }

    for(int i = 0; i < m; i++){
        int t, c;
        readInt(t); readInt(c);
        t--;
        for(int j = 0; j < c; j++){
            int t2;
            readInt(t2);
            t2--;
            g[t].push_back(t2);
        }
    }

    if(!used[0])
        dfs(0);
    if(existSol)
        printf("%d", sol);
    else
        printf("-1");

    return 0;
}
