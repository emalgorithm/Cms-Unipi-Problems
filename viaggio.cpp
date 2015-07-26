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
#include <math.h>

#define MOD 1000000007
#define MAX_N 100005
#define INF 999999999
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

int n, m, d[MAX_N];
vii g[MAX_N];

int main(){
	#ifdef eval
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int t,t2,c;
		scanf("%d %d %d",&t, &t2,&c);
		t2--; t--;
		g[t].push_back(ii(t2,c));
		g[t2].push_back(ii(t,c));
	}
	for(int i=0;i<n;i++)
		d[i] = INF;
	d[0] = 0;
	priority_queue<ii, vii, greater<ii> > pq;
	pq.push(ii(0,0));
	while(!pq.empty()){
		int node = pq.top().second;
		int dist = pq.top().first;
		pq.pop();
		if(d[node] < dist)
			continue;
		for(int i=0;i<g[node].size();i++){
			int currN = g[node][i].first;
			int currD = g[node][i].second;
			if(d[currN] > currD + d[node]){
				d[currN] = currD + d[node];
				pq.push(ii(d[currN], currN));
			}
		}
	}
	cout<<d[n-1];
		
	return 0;
}
