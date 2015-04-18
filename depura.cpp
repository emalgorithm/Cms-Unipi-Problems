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

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        int t;
        scanf("%d", &t);
        t--;
        used[t] = 1;
    }

    for(int i = 0; i < m; i++){
        int t, c;
        scanf("%d %d", &t, &c);
        t--;
        for(int j = 0; j < c; j++){
            int t2;
            scanf("%d", &t2);
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
