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

int n, a[MAX_N];

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a, a+n);
    reverse(a, a+n);
    if(a[n-2] % 2)
        for(int i = n-3;i>=0;i--)
            if(a[i]%2==0){
                swap(a[i],a[n-2]);
                break;
            }
    sort(a, a+n-2);
    reverse(a, a+n-2);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
