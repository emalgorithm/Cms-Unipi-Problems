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

int n, sol, s, v[MAX_N];
vi g[MAX_N];


int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    cin>>n;
    for(long long i=1;i<=n;i++){
        long long p = i;
        for(long long j=2;j<40;j++){
            p *= i;
            if(p > n)
                break;
            if(p > sol)
                sol = p;
        }
    }
    cout<<sol;
    return 0;
}
