#include <stdio.h>
#include <vector>
#include <string.h>

#define MAX_N 100005

using namespace std;

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


int n, v[MAX_N], ind, maxV;
vii g[MAX_N];

int dfs(int p, int l){
    if(l > maxV){
        maxV = l;
        ind = p;
    }
    v[p] = 1;
    for(int i = 0; i < g[p].size(); i++){
        int x = g[p][i].first;
        int dist = g[p][i].second;
        if(v[x] == 0){
            dfs(x, l + dist);
        }
    }
}

int main(){
    #ifdef EVAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    readInt(n);

    for(int i = 0; i < n - 1; i++){
        int a, b, dist;
        readInt(a); readInt(b); readInt(dist);
        a--; b--;
        g[a].push_back(ii(b, dist));
        g[b].push_back(ii(a, dist));
    }
    
    dfs(0, 0);

    memset(v, 0, sizeof v);

    dfs(ind, 0);

    printf("%d", maxV);

    return 0;
}
