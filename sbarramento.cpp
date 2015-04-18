#include <cstdlib>
#include <iostream>
#include <utility>
#include <algorithm>
#include <assert.h>

#define PP pair<int,int>

using namespace std;

int n, r, sol, firstFree = 0, m[505][505];

int main(){
    freopen("input.txt", "r", stdin);
	
    cin>>n>>r;
    r--;

    for(int i=0;i<n;i++){
        int t, t2;
        cin>>t>>t2;
        t--; t2--;
        m[t][t2] = 1;
        sol += abs(r - t);
    }
	freopen("output.txt", "w", stdout);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(m[j][i])
                sol += abs(i - firstFree++);

    cout<<sol;

    return 0;
}

