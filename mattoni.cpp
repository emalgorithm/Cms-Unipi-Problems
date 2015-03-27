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
#define MAX_N 1000005
#define INF 999999999
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

int ft[MAX_N], n, m;
vi sol;

void update(int p, int v){
	for(;p<=n;p+=(p&(-p)))
		ft[p]+=v;
}
int query(int p){
	int sum = 0;
	for(;p>0;p-=(p&(-p)))
		sum += ft[p];
	return sum;
}

int main(){
	#ifdef eval
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int t, t2;
		scanf("%d %d",&t,&t2);
		update(t,1);
		if(t2 < n)
			update(t2+1,-1);
	}
	for(int i=1;i<=n;i++)
		sol.push_back(query(i));
	sort(sol.begin(),sol.end());
	cout<<sol[n/2];
	return 0;
}
