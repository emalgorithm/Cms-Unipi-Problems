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

#define MAX_N 1000000
#define INF 99999999

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

int N, c, b[MAX_N];
vi g[MAX_N];

void dfs(int n, int m){
	if(m < b[n])
		c++;
	m = min(m, b[n]);
	for(int i=0;i<g[n].size();i++)
		dfs(g[n][i],m);
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int t;
		scanf("%d %d",b+i,&t);
		if(t != -1)
			g[t].push_back(i);
	}
	dfs(0,INF);
	printf("%d",c);
	return 0;
}
