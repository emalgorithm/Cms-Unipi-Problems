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

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

int a[MAX_N], n, m, sol[MAX_N];
set<int> s;

int main(){
	#ifdef eval
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	cin>>n>>m;
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	sol[n-1] = 1;
	s.insert(a[n-1]);
	for(int i=n-2;i>=0;i--){
		if(s.find(a[i]) == s.end()){
			sol[i] = sol[i+1] + 1;
			s.insert(a[i]);
		}
		else
			sol[i] = sol[i+1];
	}
	for(int i=0;i<m;i++){
		int t;
		scanf("%d",&t);
		printf("%d\n",sol[t-1]);
	}
		
	return 0;
}
