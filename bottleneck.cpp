#include <vector>
#include <string>
#include <string.h>
#include <functional>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <assert.h>

using namespace std;

typedef vector< int > vi;
typedef pair< int, int > ii;
typedef vector< ii > vii;

#define MAX_N 1000005
#define INF 1e9

vii g[MAX_N];
int v[MAX_N];
int sol[MAX_N];
int d[MAX_N];
queue<int> q;

int Analizza(int N, int M, int W, int L, int arco_da[], int arco_a[], int capacita[], int R, int C) {
    for(int i=0;i<M;i++){
        g[arco_da[i] - 1].push_back(make_pair(arco_a[i] - 1,capacita[i]));
        g[arco_a[i] - 1].push_back(make_pair(arco_da[i] - 1,capacita[i]));
    }
    for(int i=0;i<N;i++)
        sol[i] = d[i] = INF;
    v[W-1] = 1;
    d[W-1] = 0;
    q.push(W-1);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(node == L - 1)
            break;
        for(int i=0;i<g[node].size();i++){
            int ve = g[node][i].first;
            if(d[ve] >= d[node] + 1){
                sol[ve] = min(sol[ve], sol[node]);
                sol[ve] = min(sol[ve], g[node][i].second);
                    //cout<<node+1<<" "<<g[node][i].first+1<<" "<<sol[g[node][i].first]<<endl;
                if(!v[ve]){
                    v[ve] = 1;
                    d[ve] = d[node] + 1;
                    q.push(ve);
                }
            }
        }
    }
    return sol[L-1];
}
/*
#include <stdio.h>
#include <assert.h>
#define MAXN 100000
#define MAXM 1000000

static FILE *fr, *fw;

static int N, M, W, L;
static int R, C;
static int arco_da[MAXM], arco_a[MAXM], capacita[MAXM];

int Analizza(int N, int M, int W, int L, int arco_da[], int arco_a[], int capacita[], int R, int C);

int main(){
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    int i;
    assert(4 == fscanf(fr, "%d%d%d%d", &N, &M, &W, &L));
    assert(2 == fscanf(fr, "%d%d", &R, &C));
    for (i=0; i<M; i++)
        assert(3 == fscanf(fr, "%d%d%d", arco_da+i, arco_a+i, capacita+i));

    fprintf(fw, "%d\n", Analizza(N, M, W, L, arco_da, arco_a, capacita, R, C));

    fclose(fr);
    fclose(fw);
    return 0;
}*/