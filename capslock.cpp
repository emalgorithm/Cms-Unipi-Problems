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

int n;
string s;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	cin.ignore();
	getline(cin,s);
	for(int i=0;i<s.length();i++){
		if(s[i] >= 65 && s[i] <= 90)
			s[i] += 32;
		else if(s[i] >= 97 && s[i] <= 122)
			s[i] -= 32;
	}
	cout<<s;

	return 0;
}
