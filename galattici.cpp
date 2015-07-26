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
#define MAX_N 1000
#define MOD int(1e9)+7

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

int m, s, n, q = 1, mat[MAX_N][MAX_N];
char p[MAX_N];

int main(){
    #ifdef EVAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);

    scanf("%d %d %d", &m, &s, &n);

    for(int i = 0; i < n; i++)
        scanf(" %c", p + i);

    for(int i = 0; i < m; i++){
        int t, t2;
        char c;
        scanf("%d %d %c", &t, &t2, &c);
        mat[t][c] = t2;
    }
    for(int i = 0; i < n; i++)
        q = mat[q][p[i]];

    printf("%d", q);

    return 0;
}
