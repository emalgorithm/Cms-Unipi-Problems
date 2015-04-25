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
#include <string.h>
 
#define MAX_N 50000
#define INF 99999999
#define N_CHAR 130
 
using namespace std;
 
typedef pair<int, int> ii ;
typedef vector< ii >   vii ;
typedef vector<int> vi ;

int N, maxInd, counter;
int win[MAX_N], p[MAX_N], v[MAX_N];
vi g[MAX_N];
vi sol;
bool cond = true;

void dfs(int n){
    v[n]=1;
    if(!cond)
        return;
    counter++;
    
    if(counter == N){
        int t = n;
        sol.push_back(t);
        while(t != p[t]){
            t = p[t];
            sol.push_back(t);
        }
        cond = false;
    }
    
    for(int i=0;i<g[n].size() && cond;i++){
        if(!v[g[n][i]]){
            //g[n][i].second = 0;
            p[g[n][i]] = n;
            dfs(g[n][i]);
        }
    }
    
    counter--;
    v[n]=0;
}

int main() {
    
    #ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    scanf("%d",&N);
    for(int i=0;i<N*(N-1)/2;i++){
        int t,t2; scanf("%d %d",&t,&t2);
        t--;t2--;
        win[t]++;
        g[t].push_back(t2);
    }
    
    int maxim = 0;
    for(int i=0;i<N;i++){
        if(win[i] >= maxim){
            maxInd = i;
            maxim = win[i];
        }
    }
    for(int i=0;i<N;i++)
        p[i] = i;

    dfs(maxInd);
    printf("%d\n",N-1);
    reverse(sol.begin(),sol.end());
    for(int i=0;i<sol.size()-1;i++)
        printf("%d %d\n",sol[i]+1,sol[i+1]+1);
    return 0;
}

//4 1 2 2 4 4 3 3 2 4 1 3 1

//7 6 4 2 5 2 6 2 4 3 4 4 4 5 4 6 