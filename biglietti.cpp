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

int N,M, A, B,sol;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d %d %d %d",&N,&M, &A, &B);
	if(M*A <= B)
		sol = N*A;
	else
		sol = min(N/M * B + (N%M)*A,( N/M+1)*B);
	cout<<sol;
	return 0;
}
