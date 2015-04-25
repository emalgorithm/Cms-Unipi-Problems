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

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

long long n, sol = -1;

long long sum(long long j){
	long long r = 0;
	while(j != 0){
		r += j % 10;
		j /= 10;
	}
	return r;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	cin>>n;
	for(long long i=0;i<=162;i++){
		long long sq = sqrt(i*i+4*n);
		if(sq*sq != i*i+4*n)
			continue;
		long long x1 = (-i + sq)/2;
		long long s = sum(x1);
		if(s == i && (sol == -1 || x1 < sol))
			sol = x1;
	}
	cout<<sol;


	return 0;
}
