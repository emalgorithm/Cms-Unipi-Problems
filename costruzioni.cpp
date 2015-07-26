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

int n, k, p[MAX_N], sol = INF;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    n = readInt(); k = readInt();
    for(int i = 0; i < n; i++)
        p[i] = readInt();
    
    int t = 0;
    for(int i = 0; i < k; i++)
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

