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
#define MAX_N 4000005
#define MOD int(1e9)+7
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

int n, m, f[MAX_N];
vi g[MAX_N];

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int t,t2;
        cin>>t>>t2;
        g[t].push_back(t2);
        g[t2].push_back(t);
        f[t]++; f[t2]++;
    }
    bool cond = true;
    while(cond){
        cond = false;
        for(int i=0;i<n;i++)
            if(f[i] < 2 && f[i] != -1){
                for(int j=0;j<g[i].size();j++)
                    if(f[g[i][j]] != -1)
                        f[g[i][j]]--;
                f[i] = -1;
                cond = true;
            }
    }
    
    int sol = 0;
    for(int k=0;k<n;k++)
        if(f[k] != -1)
            sol ++;
    cout<<sol;
    return 0;
}
