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
#include <bitset>
 
#define MAX_N 1000005
#define INF 999999999
 
using namespace std;
 
typedef pair<int, int> ii ;
typedef vector< ii >   vii ;
typedef vector<int> vi ;
 
int n, m, v[MAX_N];
vii g[MAX_N];
ii sol[MAX_N];

void dfs(int node){
    v[node] = 1;
    if(node == 0 || g[node].size() == 0)
        return;
    for(int i=0;i<g[node].size();i++)
        if(!v[g[node][i].second])
            dfs(g[node][i].second);
    for(int i=0;i<g[node].size();i++){  
            int nodeCurr = g[node][i].second;
            int dist = g[node][i].first;

            int temp =  min(sol[nodeCurr].second, dist);
            temp = max(temp, sol[nodeCurr].first);
            sol[node].first = min(sol[node].first, temp);

            int temp2 = max(sol[nodeCurr].second, dist);
            sol[node].second = min(sol[node].second, temp2);
            
        }
}
 
int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
    
    in>>n>>m;

    for(int i=0;i<m;i++){
        int t, t2, d; in>>t>>t2>>d; t--; t2--;
        g[t2].push_back(ii(d,t));
    }
    for(int i=0;i<n;i++)
        sol[i].first = sol[i].second = INF;
    sol[0].first = sol[0].second = 0;    
    dfs(n-1);

    out<<sol[n-1].first;
    
    in.close(); out.close();
    return 0;
}
//6 7 1 2 1 1 3 8 2 3 5 3 4 3 4 6 9 4 5 7 5 6 2
//5 6 1 2 10 2 3 10 2 5 11 2 4 1 4 3 1 3 5 1