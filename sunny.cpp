#include <math.h>
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

#define MAX_N 1000005
#define INF 1000000005
#define MOD 1000000007

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

int n, m, S, E, sol, v[MAX_N];
vii g[MAX_N];

int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
        
    cin>>n>>m>>S>>E;
    S--;
    E--;
    for(int i=0;i<m;i++){
        int n1, n2, l;
        cin>>n1>>n2>>l;
        n1--; n2--;
        g[n1].push_back(ii(l, n2));
        g[n2].push_back(ii(l, n1));
    }
    
    for(int i=0;i<n;i++)
        sort(g[i].begin(),g[i].end());

    int nCurr = S;
    while(!v[nCurr] && nCurr != E){
        v[nCurr] = 1;
        nCurr = g[nCurr][0].second;
        sol++;
    }

    if(nCurr == E)
        cout<<sol;
    else
        cout<<-1;
    
    return 0;
}

