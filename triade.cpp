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

#define MAX_N 1000005

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

int N, M, c, v[MAX_N], s;
vi a[MAX_N];
vii e;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d %d",&M, &N);
	for(int i=0;i<M;i++){
		int t, t2;
		scanf("%d %d", &t, &t2);
		t--; t2--;
		a[t].push_back(t2);
		a[t2].push_back(t);
		e.push_back(make_pair(t,t2));
	}
	for(int i=0;i<N;i++)
		sort(a[i].begin(),a[i].end());
	
/*	for(int i=0;i<M;i++){
		int n1 = e[i].first, n2 = e[i].second;
		if(a[n1].size() < a[n2].size()){
			for(int k=0;k<a[n1].size();k++)
				if(binary_search(a[n2].begin(), a[n2].end(), a[n1][k]))
					c++;
		}
		else{
			for(int k=0;k<a[n2].size();k++)
				if(binary_search(a[n1].begin(), a[n1].end(), a[n2][k]))
					c++;
		}
	}*/
	for(int i=0;i<N;i++)
		for(int j=0;j<a[i].size();j++){
			int node = a[i][j];
			if(a[i].size() > a[node].size()){
				for(int k=0;k<a[node].size();k++){
					int node2 = a[node][k];
					if(binary_search(a[i].begin(),a[i].end(),node2))
						c++;
				}
			}
			else{
				for(int k=0;k<a[i].size();k++)
					if(binary_search(a[node].begin(), a[node].end(), a[i][k]))
						c++;
			}
		}
	cout<<c/6;
	return 0;

}




