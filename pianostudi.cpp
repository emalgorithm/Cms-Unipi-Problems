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
#define MAX_N 4000005
#define MOD int(1e9)+7
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

int n, f[MAX_N], memo[MAX_N];
vector< pair< int, ii > > e;

bool cmp(const pair< int, ii> &a, const pair< int, ii > &b){
    return a.first < b.first;
}

int dp(int course){
    if(course == n)
        return 0;
    if(memo[course] != -1)
        return memo[course];
    int sol = 0;
    pair< int, ii > temp(make_pair(e[course].second.first, ii(0,0)));
    int nextCourse = upper_bound(e.begin(), e.end(), temp, cmp) - e.begin();
//    for(int i=course+1;i<n;i++)
//        if(e[i].first > e[course].second.first){
//            nextCourse = i;
//            break;
//        }

    sol = dp(nextCourse) + e[course].second.second;
    sol = max(sol, dp(course + 1));
    return memo[course] = sol;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n;
    e.resize(n);
    for(int i=0;i<n;i++)
        cin>>e[i].first>>e[i].second.first>>e[i].second.second;
    memset(memo, -1, sizeof memo);

    sort(e.begin(), e.end());
    cout<<dp(0);
    return 0;
}
