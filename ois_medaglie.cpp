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

#define INF 1000000005
#define MAX_N 100005
#define MOD int(1e9)+7
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

int n, v[MAX_N], sum[MAX_N], memo[MAX_N];

int dp(int p){
    if(p==0)
        return memo[p] = v[0];
    if(p==1)
        return memo[p] = v[0]+v[1];
    if(p==2)
        return memo[p] = v[0]+v[1]+v[2];
    if(p==3)
        return memo[p] = v[1]+v[2]+v[3];
    if(memo[p] != 0)
        return memo[p];
    int m = max(v[p]+sum[p-1]-dp(p-1), v[p]+v[p-1]+sum[p-2]-dp(p-2));
    m = max(m, v[p]+v[p-1]+v[p-2]+sum[p-3]-dp(p-3));
    return memo[p] = m;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        if(t==0)
            v[i]=100;
        else if(t==1)
            v[i]=300;
        else if(t==2)
            v[i]=500;
        sum[i] = v[i] + (i > 0 ? sum[i-1] : 0);
    }
    cout<<dp(n-1);

    return 0;
}
