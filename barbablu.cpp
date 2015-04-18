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

#define INF 1000000005
#define MAX_N 50
#define MOD int(1e9)+7

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

int n, m, c, k, a[MAX_N], d[MAX_N], mat[MAX_N][MAX_N];
vii g[MAX_N];

int main(){
    #ifdef EVAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);

    cin>>n>>m>>c>>k;
    c--;
    for(int i = 0; i < k; i++){
        int t; 
        cin>>t;
        t--;
        a[t] = 1;
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            mat[i][j] = INF;

    for(int i = 0; i < m; i++){
        int t, t2, d;
        cin>>t>>t2>>d;
        t--; t2--;
        if(d > 20)
            continue;
        mat[t][t2] = mat[t2][t] = d;
    }

    for(int i = 1; i < n; i++)
        if(!a[i]){
            for(int j = 0; j < n; j++)
                if(mat[i][j] != INF)
                    for(int k = 0; k < n; k++)
                        if(mat[i][k] != INF){
                            int dist = mat[i][j] + mat[i][k];
                            if(dist <= 20)
                                mat[j][k] = mat[k][j] = min(mat[j][k], dist);
                        }
            for(int j = 0; j < n; j++)
                mat[j][i] = mat[i][j] = INF;

        }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(mat[i][j] != INF)
                g[i].push_back(make_pair(j, mat[i][j]));
                
    int source = 0;
    int d[MAX_N]; memset(d, 0, sizeof d);
    priority_queue< ii, vii, greater<ii> > pq;

	for(int i = 0; i < n; i++)
		d[i] = INF;
	
    d[source] = 0;

    pq.push(make_pair(d[source], source));

    while(!pq.empty()){
        int node = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        if(d[node] < dist)
            continue;
        for(int i = 0; i < g[node].size(); i++){
            int adjNode = g[node][i].first;
            int adjDist = g[node][i].second;
            if(d[adjNode] > d[node] + adjDist){
                d[adjNode] = d[node] + adjDist;
                pq.push(make_pair(d[adjNode], adjNode));
            }
        }
    }

    if(d[c] != INF)
        cout<<d[c]<<endl;
    else
        cout<<"-1"<<endl;


    return 0;
}
