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
#include <assert.h>
#include <stdlib.h>
#include <time.h>

#define INF 1000000005
#define MAX_N 1000
#define MAX_M 10000
#define MOD int(1e9)+7

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

int n, m, v[MAX_N], d[MAX_N], p[MAX_N], sol = INF;
vii g[MAX_N];
int ran[MAX_N];


int main(){
    #ifdef EVAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);

    cin>>n>>m;

    for(int i = 0; i < m; i++){
        int t, t2, d;
        cin>>t>>t2>>d;
        t--; t2--;
        g[t].push_back({t2, d});
        g[t2].push_back({t, d});
    }

    srand(time(NULL));

    for(int i = 0; i < n; i++)
        random_shuffle(g[i].begin(), g[i].end());

    for(int i = 0; i < n; i++)
        ran[i] = i;
    
    random_shuffle(ran, ran + n);
    
    for(int i = 0; i < n; i++){
        int k = ran[i];
        priority_queue< ii, vii, greater< ii > > pq;
        for(int j = 0; j < n; j++)
            d[j] = INF;
        d[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            v[node] = 1;
            if(d[node] < dist)
                continue;
            if(d[node] > sol)
                break;
            for(int j = 0; j < g[node].size(); j++){
                int adjNode = g[node][j].first;
                int adjDist = g[node][j].second;
                if(v[adjNode] && p[node] != adjNode){
                    sol = min(sol, d[node] + d[adjNode] + adjDist);
                }
                
                if(d[adjNode] > d[node] + adjDist){
                    d[adjNode] = d[node] + adjDist;
                    p[adjNode] = node;
                    pq.push({d[adjNode], adjNode});
                }
            }
        }
    }

    cout<<sol;



    return 0;
}
