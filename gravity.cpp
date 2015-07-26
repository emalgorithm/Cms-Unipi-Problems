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

int n, mi = INF, ma, sol = 2;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n;
    if(n == 1 || n == 2){
        cout<<n;
        return 0;
    }
    cin>>mi>>ma;

    for(int i=2;i<n;i++){
        int t;
        cin>>t;
        if((ma > mi && t < ma) || (mi > ma && t > ma))
            sol++, mi = ma, ma = t;
        else if(ma > mi && t > ma)
            ma = t;
        else if(mi > ma && t < ma)
            ma = t;
    }
    cout<<sol;

    return 0;
}
