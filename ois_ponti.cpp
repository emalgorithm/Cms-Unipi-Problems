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

#define INF 1000000005
#define MAX_N 100005
#define MOD int(1e9)+7
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

int n, m, s, v[MAX_N];
vi g[MAX_N];

void dfs(int n){
    v[n] = 1;
    for(int i=0;i<g[n].size();i++)
        if(!v[g[n][i]])
            dfs(g[n][i]);
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int t,t2;
        scanf("%d %d",&t,&t2);
        g[t].push_back(t2);
        g[t2].push_back(t);
    }

    for(int i=0;i<n;i++)
        if(v[i] == 0){
            dfs(i);
            s++;
        }
    cout<<s-1;
    return 0;
}
