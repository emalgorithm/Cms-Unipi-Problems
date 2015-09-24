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
 
#define MAX_N 100005
 
#define N_CHAR 130
 
using namespace std;
 
typedef pair<int, int> ii ;
typedef vector< ii >   vii ;
typedef vector<int> vi ;
 
int v[MAX_N], lin, circ, star;
vi g[MAX_N], temp;
vector< vi > cC;

void dfs(int n){
    v[n] = 1;
    temp.push_back(n);
    for(int i=0;i<g[n].size();i++)
        if(!v[g[n][i]])
            dfs(g[n][i]);
}

void Analizza(int N, int M, int* A, int* B, int* T) {
      for(int i=0;i<M;i++){
        int t = A[i], t2 = B[i];
        t--; t2--;
        g[t].push_back(t2);
        g[t2].push_back(t);
    }

    for(int i=0;i<N;i++)
        if(!v[i]){
            temp.clear();
            dfs(i);
            cC.push_back(temp);
        }

    for(int i=0;i<cC.size();i++){
        
        if(cC[i].size() > 1){  //Testo se è lineare
            int oneEdge = 0; bool cond = true;
            for(int j=0;j<cC[i].size();j++){
                if(g[cC[i][j]].size()>2)
                    cond = false;
                else
                    if(g[cC[i][j]].size() == 1)
                        oneEdge++;
            }
            if(oneEdge == 2 && cond == true)
                lin ++;
        }

        if(cC[i].size() > 2){  //testo se è circolare
            bool cond = true;
            for(int j=0;j<cC[i].size();j++)
                if(g[cC[i][j]].size()!=2)
                    cond = false;
            if(cond)
                circ++;
        }

        if(cC[i].size() > 3){  //testo se è a stella
            int moreThanOne = 0;
            for(int j=0;j<cC[i].size();j++)
                if(g[cC[i][j]].size()>1)
                    moreThanOne++;
            if(moreThanOne == 1)
                star++;
        }
    }

    T[0] = lin;
    T[1] = circ;
    T[2] = star;
}
