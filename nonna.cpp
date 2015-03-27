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

int n, k, p[MAX_N], mi = INF, ma = INF, memo[5005][10005];

void dp(int pos, int w){
    if(pos == n+1)
        return;
    if(memo[pos][w] != 0)
        return;
    if(w >= k){
        ma = min(ma, w);
        return;
    }
    memo[pos][w] = 1;
    dp(pos+1, w+p[pos]);
    dp(pos+1, w);
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin>>n>>k;
    int j = 0;
    for(int i=0;i<n;i++){
        int t; cin>>t;
        if(t >= k)
            mi = min(mi, t);
        else
            p[j++]=t;
    }
    dp(0, 0);

    cout<<min(ma, mi);
    return 0;
}

