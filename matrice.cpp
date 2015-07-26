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

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

int n, m, s[1000005], mat[505][505], c[505], r[505];
int sol = 999999999;

int main(){
	#ifdef eval
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	s[0] = 1; s[1] = 1;
	for(int i=2;i<100005;i++)
		if(!s[i])
			for(int j=2;i*j<100005;j++)
				s[i*j] = 1;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&mat[i][j]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			int c = 0, ind = mat[i][j];
			while(s[ind]){
				ind++;
				c++;
			}
			mat[i][j] = c;
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			r[i] += mat[i][j];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			c[i] += mat[j][i];
	for(int i=0;i<n;i++)
		sol = min(sol, r[i]);
	for(int i=0;i<m;i++)
		sol = min(sol, c[i]);
	cout<<sol;
	return 0;
}
