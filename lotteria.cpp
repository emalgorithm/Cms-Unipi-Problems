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

int n, m, memo[30][200005];

int dp(int i, int j){
	if(i == 0)
		return 1;
	if(i > j)
		return 0;
	if(memo[i][j] != -1)
		return memo[i][j];
	return memo[i][j] = (dp(i, j-1) + dp(i-1,j/2))%MOD;
}

int main(){
	#ifdef eval
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	memset(memo, -1, sizeof memo);
	cin>>n>>m;
	cout<<dp(n,m);
	return 0;
}
