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

string s;
int h;
long long sol;

int main(){
#ifdef eval
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	cin>>s;
	int sz = s.size();
	for(int i=0;i<sz;i++){
		if(i < sz - 4){
			if(s.substr(i,5).compare("hello") == 0)
				h++;
			else if(s.substr(i,5).compare("world") == 0)
				sol += h;
		}
	}
	cout<<sol;

	return 0;
}
