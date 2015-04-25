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

int N, k, sol = 99999999;
vi s;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d %d",&N,&k);
	for(int i=0;i<N;i++){
		int t; 
		scanf("%d",&t);
		s.push_back(t);
	}
	sort(s.begin(),s.end());
	for(int i=0;i<N-k+1;i++)
		sol = min(sol, s[i+k-1] - s[i]);
			
	printf("%d",sol);


	return 0;
}
