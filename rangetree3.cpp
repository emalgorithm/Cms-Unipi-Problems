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

#define INF 1000000005
#define MAX_N 100005
#define MOD int(1e9)+7
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

int n, m, a[MAX_N];

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	cin>>m;
	for(int i=0;i<m;i++){
		int q,t,t2;
		scanf("%d %d %d",&q,&t,&t2);
		if(q == 0)
			a[t-1] = t2;
		else{
			int sum = -INF, sumT = 0;
			for(int k=t-1;k<t2;k++){
				sumT += a[k];
				sum = max(sum, sumT);
				sumT = max(0,sumT);
		}
		printf("%d\n",sum);
		}
	}
	return 0;
}
