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

int N, M, A, B;
vi sol, st;
vii g[MAX_N];

void ric(int n){
    int ind = -1;
    for(int i=0;i<g[n].size();i++)
        if(g[n][i].second){
            ind = i;
            break;
        }
    if(ind == -1){;
        sol.pb(n);
        if(st.empty())
            return;
        int nodeCurr = st.back();
        st.pop_back();
        ric(nodeCurr);
    }
    else{
        st.pb(n);        
        int node = g[n][ind].first;
        g[n][ind].second = 0;
        for(int j=0;j<g[node].size();j++)
            if(g[node][j].first == n){
                g[node][j].second = 0;
                break;
            }
        ric(node);
    }
} 

int main() {
    //in = fopen("input.txt","r"); out = fopen("output.txt","w");
    in.open("input.txt"); out.open("output.txt");
    
    //fscanf(in, "%d %d %d %d" , &N, &M, &A, &B);
    in>>N>>M>>A>>B; A--; B--;
    for(int i=0;i<M;i++){
        int t,t2;
        //fscanf(in, "%d %d", &t, &t2);
        in>>t>>t2; t--; t2--;
        g[t].pb(ii(t2,1));
        g[t2].pb(ii(t,1));
    }
    
    ric(A);
    for(int i=sol.size()-1;i>0;i--)
           out<<sol[i]+1<<" "<<sol[i-1]+1<<endl;

    in.close(); out.close();
    //fclose(in); fclose(out);
    return 0;
}

//5 8 1 5 1 4 2 3 5 4 2 1 2 4 3 4 1 5 5 2

//7 7 1 7 1 2 2 5 2 3 3 4 2 4 5 6 6 7
