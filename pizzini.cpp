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

#define INF 1000000005
#define MAX_N 300
#define MOD int(1e9)+7

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

int n, a[MAX_N], l[MAX_N][MAX_N];
string s[MAX_N];

int main(){
    #ifdef EVAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>s[i];
        for(int j = 0; j < s[i].length(); j++)
            l[i][s[i][j]]++;
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            bool cond = true;
            for(int k = '0'; k <= '9'; k++)
                if(l[i][k] != l[j][k])
                    cond = false;
            if(cond)
                a[i]++;
        }

    for(int i = 0; i < n; i++)
        cout<<s[i][a[i] - 1];


    return 0;
}
