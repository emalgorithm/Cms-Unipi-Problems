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
#define MAX_N 500005
#define MOD 1000000007

//FILE * in; FILE * out;
ifstream in; ofstream out;

int N, M, fenw[MAX_N];
int f[MAX_N], l[MAX_N], counter = 0;
vi g[MAX_N];
int p[MAX_N];

int dfs(int n){
    f[n] = counter++;
    for(int i=0;i<g[n].size();i++)
        dfs(g[n][i]);
    l[n] = counter;
}

int add(int x, int y){
    for(;x<=N;x += (x&(-x))) fenw[x] += y;
}
int query(int x){
    int sum=0;
    for(;x;x -= x&-x) sum += fenw[x];
    return sum;
}

int main() {
    
    #ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    scanf("%d %d %d",&N,&M,p);//cin>>N>>M>>p[0];
    for(int i=1;i<N;i++){
        int t;
        scanf("%d %d",p+i,&t);t--;//cin>>p[i]>>t; t--;
        g[t].push_back(i);        
    }
    dfs(0);
    
    for(int i=0;i<M;i++){
        char t;
        scanf(" %c",&t);//cin>>t;
        if(t=='p'){
            int q,q2; scanf("%d %d",&q,&q2);//cin>>q>>q2;
            add(f[q-1]+1+1,q2);
            add(l[q-1]+1,-q2);
            
        }
        if(t=='u'){
            int q; scanf("%d", &q);//cin>>q;
            printf("%d\n", query(f[q-1]+1)+p[q-1]);//cout<<query(f[q-1]+1)+p[q-1]<<endl;
        }
        
    }
    
    
    
   
    return 0;
}

//3 5 3 1 p 1 5 u 2 u 1