#include <algorithm>
#include <iostream>
#include <vector>

#define MAX_N 1000005
#define INF 1000000005
#define MOD 1000000007

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

int n, b[MAX_N];
vi g[MAX_N];

int dfs(int p){
    int sol = 0;
    for(int i=0;i<g[p].size();i++)
        sol += dfs(g[p][i]);
    return max(b[p], sol);
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>b[i]>>t;
        if(t > -1)
            g[t].push_back(i);
    }
    cout<<dfs(0);
    return 0;

}

