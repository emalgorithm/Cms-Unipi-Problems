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

int n,t=1, n2;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n;
    n2 = n;
    while(t <= n)
        t *= 10;
    t /= 10;
    int p = 1;
    while(p <= n){
        p *= 10;
        int m = n2 % p;
        m /= (p/10);
        n += m*t;
        n2 -= m;
        t /= 10;
    }
    cout<<n;

    return 0;
}
