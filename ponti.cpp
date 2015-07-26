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

#define MAX_N 20000005

using namespace std;

typedef pair<int, int> ii ;
typedef vector< ii >   vii ;
typedef vector<int> vi ;

int n,m,v[10005],c;
vi G[10005];

int dfs(int k){
    v[k]=1;
    for(int i=0;i<G[k].size();i++)
        if(!v[G[k][i]])
            dfs(G[k][i]);
}

int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
    
    in>>n>>m;
    
    for(int i=0;i<m;i++){
        int t,t2;
        in>>t>>t2;
        G[t].push_back(t2);
        G[t2].push_back(t);
    }
    for(int i=0;i<n;i++)
        if(!v[i]){
            dfs(i);
            c++;
        }
    
    out<<c-1;
 
    in.close(); out.close(); 
    return 0;
}


//11 9 1 0 2 8 0 5 1 6 0 0 3










