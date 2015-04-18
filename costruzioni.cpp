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

int n, k, p[MAX_N], sol = INF;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    int t = 0;
    for(int i=0;i<k;i++)
        t += p[i];
    sol = t;
    for(int i = k;i<n;i++){
        t += p[i];
        t -= p[i-k];
        sol = min(sol, t);
    }

    cout<<sol;
    return 0;
}

