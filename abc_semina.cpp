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
#include <math.h>

#define INF 1000000005
#define MAX_N 1005
#define MAX_M 100005
#define MOD int(1e9)+7

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

void readInt(int &n){
    n = 0;
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
}   

int n, m, s[MAX_N][MAX_N];

int main(){
    #ifdef EVAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);

    readInt(n);

    for(int i = 0; i < n; i++){
        int x1, x2, y1, y2;
        readInt(x1); readInt(y1);
        readInt(x2); readInt(y2);
        x1 += 100; x2 += 100;
        y1 += 100; y2 += 100;
        for(int j = y2; j < y1; j++)
            for(int k = x1; k < x2; k++){
                s[j][k]++;
                m = max(m, s[j][k]);
            }
    }

    cout<<m;

    return 0;
}
