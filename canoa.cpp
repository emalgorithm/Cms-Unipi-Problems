#include <math.h>
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

#define MAX_N 1000005
#define INF 1000000005
#define MOD 1000000007

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

int readInt(){
    int n = 0;
    int ch = getchar_unlocked();
    int sign = 1;
    while(ch < '0' || ch > '9'){
        if(ch == '-') 
            sign = -1; 
        ch = getchar_unlocked();
    }

    while(ch >= '0' && ch <= '9'){
            n = (n << 3) + (n << 1) + ch - '0';
            ch = getchar_unlocked();
    }
    n *= sign;
    return n;
}   

int n, k;
vii v;

bool cmp(const ii &a, const ii &b){
	return a.first > b.first;
}

int main(){

#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    n = readInt(); k = readInt();

    for(int i = 0;i < n; i++){
        int f = readInt(), p = readInt();
        int value = f - (3 * p / 2);
        v.push_back(ii(value, i));
    }
    nth_element(v.begin(), v.begin() + k - 1, v.end(), cmp);

    for(int i = 0; i < k; i++)
        printf("%d\n", v[i].second + 1);
    return 0;
}

