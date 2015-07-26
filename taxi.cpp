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

int n, sol, c[MAX_N];

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>c[i];
    int curr = sol = c[0];
    for(int i=1;i<n;i++){
        curr = min(curr+1, c[i]);
        sol += curr;
    }
    cout<<sol;
    return 0;
}
