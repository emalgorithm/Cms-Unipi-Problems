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

int n;
char s[100000][30];

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	cin>>n;

	for(int i=0;i<n;i++)
		scanf("%s",&s[i][0]);
	int sz = strlen(s[0]);
	for(int i=0;i<sz;i++)
		for(int j=0;j<n;j++)
			if(s[0][i] != s[j][i]){
				cout<<i;
				return 0;
			}
	cout<<sz;

	return 0;
}
