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

int n, g[MAX_N], ma, sol;
vi pos;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for(int i=0;i<n;i++){
        scanf("%d",g+i);
        ma = max(ma, g[i]);
    }

    for(int i=0;i<n;i++)
        if(g[i] == ma)
            pos.push_back(i);
    
    for(int i=0;i<pos.size();i++){
        int end = (i == pos.size() - 1) ? (n-1) : pos[i+1];
        int start = (i == 0) ? 0 : pos[i-1];
        int solTemp = end - start + 1;
        sol = max(sol, solTemp);
    }

    printf("%d", sol);
    
    return 0;
}

