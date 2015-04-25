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

int N,M,K, c;
vi d;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d %d %d",&N,&M,&K);
	if(N==0 || M==0 || K==0){
		cout<<1;
		return 0;
	}
	for(int i=0;i<N;i++){
		int t;
		scanf("%d",&t);
		d.push_back(t);
	}
	d.push_back(K);
	int curr = 0;
	vi::iterator it = d.begin();
	while(it != d.end()){
		it = upper_bound(d.begin(),d.end(),curr+M);
		if(it == d.end())
			break;
		it--;
		curr = *it;
		c++;
	}
	cout<<c;
	return 0;

}
