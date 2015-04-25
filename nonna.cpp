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

int n, k, p[MAX_N], mi = INF, ma = INF, usablePos, memo[5005][10005];

void dp(int pos, int w){
    if(pos == usablePos + 1)
        return;
    if(memo[pos][w] != 0)
        return;
    if(w >= k){
        ma = min(ma, w);
        return;
    }
    memo[pos][w] = 1;
    dp(pos+1, w + p[pos]);
    dp(pos+1, w);
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    n = readInt(); k = readInt();
    int j = 0;
    for(int i=0;i<n;i++){
        int t = readInt();
        if(t >= k)
            mi = min(mi, t);
        else
            p[j++] = t;
    }
    usablePos = j;
    dp(0, 0);

    cout<<min(ma, mi);
    return 0;
}

