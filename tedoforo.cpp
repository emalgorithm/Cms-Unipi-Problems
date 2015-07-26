#include <math.h>
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

#define MAX_N 1005
#define INF 1000000005
#define MOD 1000000007

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

int n, m, d[MAX_N], sol;
vii g[MAX_N];

int main(){

#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++){
        int t, t2, dist;
        scanf("%d %d %d", &t, &t2, &dist);
        t--; t2--;
        g[t].push_back(ii(t2, dist));
        g[t2].push_back(ii(t, dist));
    }

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

    for(int i = 0; i < n; i++)
        if(d[i] <= (i + 1) * 10)
            sol++;

    printf("%d", sol);
    

    return 0;
}

