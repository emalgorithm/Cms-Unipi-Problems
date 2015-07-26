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

long long a, b;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	cin>>a>>b;
	long long t = sqrt(a);
	long long t2 = t*t;
	if(t2 < a)
		t++;
	long long e = sqrt(b);

	cout<<e-t+1;
	



	return 0;
}
