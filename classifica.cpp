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
#define MAX_N 20005
#define MOD int(1e9)+7

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

int n, p[MAX_N], sol, ind;

int main(){
    #ifdef EVAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);

    scanf("%d", &n);
    
    for(int i = 0; i < n*(n-1)/2; i++){
        int t1, t2, s1, s2;
        scanf("%d %d %d %d", &t1, &t2, &s1, &s2);
        if(s1 > s2)
            p[t1] += 3;
        if(s2 > s1)
            p[t2] += 3;
        if(s1 == s2){
            p[t1]++;
            p[t2]++;
        }
    }

    for(int i = 0; i <= n; i++){
        if(p[i] > sol){
            sol = p[i];
            ind = i;
        }
    }

    printf("%d %d", ind, sol);

    return 0;
}
