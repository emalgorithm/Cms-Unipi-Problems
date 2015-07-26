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
#define MAX_N 200005
 
int n,e, v[MAX_N], p[MAX_N];
vi g[MAX_N], sol;
bool cond = true;

void dfs(int node){
    if(!cond)
        return;
    v[node] = 1;
    for(int i=0;i<g[node].size() && sol.empty();i++){
        int curr = g[node][i];
        if(v[curr] == 1 && curr != p[node]){
            //cout<<"ALready visited : "<<node<<" "<<curr<<endl;
            int t = node;
            sol.pb(t);
            do{
                t = p[t];
                sol.pb(t);
            }while(t!=curr);
            if(sol.size()>=3)
                cond = false;
            
            else
                sol.clear();
        }
        if(!v[curr]){
            //cout<<node<<" "<<curr<<endl;
            //cout<<"Not visited : "<<node<<" "<<curr<<endl;
            p[curr] = node;
            dfs(curr);
        }          
        
    }
    v[node] = 2;    
}

int main() {
    
    #ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    scanf("%d %d",&n,&e);
    for(int i=0;i<e;i++){
        int t,t2,c;
        scanf("%d %d %d",&t,&t2,&c); t--; t2--;
        if(c){
            g[t].pb(t2);
            g[t2].pb(t);
        }
    }
    for(int i=0;i<n;i++)
        if(v[i] == 0)
            dfs(i);
    /*for(int i=0;i<n;i++){
        cout<<i<<": ";
        for(int j=0;j<g[i].size();j++)
            cout<<g[i][j]<<" ";
        cout<<endl;
    }*/
    cout<<sol.size()<<endl;
    for(int i=0;i<sol.size();i++)
        printf("%d ",sol[i]+1);
    
    return 0;
}

//5 8 5 4 1 1 2 1 1 3 1 3 2 1 1 5 0 1 4 1 3 4 0 2 5 1