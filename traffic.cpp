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

using namespace std;

typedef pair<int, int> ii ;
typedef vector< ii >   vii ;
typedef vector<int> vi ;
typedef vector<vi> vvi; 

#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 

#define INF 999999999
#define MAX_N 1000010
#define MOD 1000000007

//FILE * in; FILE * out;
ifstream in; ofstream out;

long long int N, v[MAX_N],p[MAX_N], tot, sol = INF;
vii g[MAX_N];

int dfs(int n){
    long long int sum = 0;
    v[n] = 1;
    for(int i=0;i<g[n].size();i++)
        if(!v[g[n][i].first]){
            long long int temp = dfs(g[n][i].first);
            sum += temp;
            g[n][i].second = temp;
        }            
    return sum + p[n];
}

void dfs2(int n){
    v[n] = 1;
    for(int i=0;i<g[n].size();i++)
        if(!g[n][i].second){
            long long int sum = 0;
            int node = g[n][i].first;
            for(int j=0;j<g[node].size();j++)
                if(g[node][j].first != n)
                    sum += g[node][j].second;
            g[n][i].second = sum + p[node];
        }  
    
    for(int i=0;i<g[n].size();i++)
        if(!v[g[n][i].first]){
            dfs2(g[n][i].first);
        }            
}

int main() {
    //in = fopen("input.txt","r"); out = fopen("output.txt","w");
    in.open("input.txt"); out.open("output.txt");
    
    //fscanf(in, "%d %d %d %d" , &N, &M, &A, &B);
    in>>N;
    for(int i=0;i<N;i++)
        in>>p[i];
    for(int i=0;i<N-1;i++){
        int t,t2; in>>t>>t2; 
        g[t].pb(ii(t2,0));
        g[t2].pb(ii(t,0));
    }
 
    int t = dfs(0);
    for(int i=0;i<N;i++) v[i] = 0;
    dfs2(0);
    
    //for(int i=0;i<N;i++)
      //  for(int j=0;j<g[i].size();j++)
        //    cout<<i<<" "<<g[i][j].first<<" "<<g[i][j].second<<" ";
    
    for(int i=0;i<N;i++){
        int temp = 0;
        for(int j=0;j<g[i].size();j++)
            temp = max(temp, g[i][j].second);
        if(temp < sol)
            sol = temp;
    }
    out<<sol;

    in.close(); out.close();
    //fclose(in); fclose(out);
    return 0;
}

//11 10 10 10 10 10 10 10 10 10 10 10 0 1 0 2 2 3 2 4 4 5 5 6 5 7 5 8 4 9 9 10 

//5 10 10 10 10 10 0 1 1 2 2 3 3 4
