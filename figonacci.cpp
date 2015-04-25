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


using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

int N,M, f[1000000];

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d %d",&N,&M);
	f[0] = -1;
	f[1] = 0;
	int s = -1;
	for(int i=2;i<=N;i++){
		f[i] = f[i-1]*(i-1) - (s-f[i-1]);
		f[i] = (f[i]%M + M)%M;
		s += f[i];
	}

	cout<<f[N];


	return 0;
}
