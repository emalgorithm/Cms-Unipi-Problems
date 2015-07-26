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

int n, s[MAX_N], a[MAX_N], sol;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin>>n;
    for(int i=0;i<n;i++)
        cin>>s[i];

    int l = 1;
    for(int i=0;i<n;i++){
        if(i+s[i] >= n){
            sol = a[i]+1;
            break;
        }
        for(int j=l;j<=i+s[i];j++)
            a[j] = a[i]+1;
        l = max(l, i+s[i]+1);
    }

    cout<<sol;

    return 0;
}

