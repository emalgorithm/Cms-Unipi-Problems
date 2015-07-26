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
#include <assert.h>

#define INF 1000000005
#define MAX_N 105
#define MOD int(1e9)+7

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

int n, memo[400][MAX_N];
ii m[MAX_N];

int dp(int day, int pos){
    if(pos == n)
        return 0;
    if(memo[day][pos] != -1)
        return memo[day][pos];
    int sol = -1;
    if(day + m[pos].second <= m[pos].first + 1)
        sol = dp(day + m[pos].second, pos + 1) + 1;
    sol = max(sol, dp(day, pos + 1));
    return memo[day][pos] = sol;
}

int main(){
    #ifdef EVAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);

    cin>>n;

    for(int i = 0; i < n; i++)
        cin>>m[i].second>>m[i].first;

    memset(memo, -1, sizeof memo);

    sort(m, m + n);

    cout<<dp(1, 0)<<endl;


    return 0;
}
