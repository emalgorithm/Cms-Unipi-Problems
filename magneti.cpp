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

int n, sol;
char s[MAX_N];

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n;
    int k=0;
    for(int i=0;i<n;i++){
        char t;
        cin>>t;
        if(i%4==1 || i%4==2)
            s[k++]=t;
    }
    for(int i=0;i<n/2;i+=2)
        if(s[i]!='+')
            sol++;
    int solT = 0;
    for(int i=0;i<n/2;i+=2)
        if(s[i]!='-')
            solT++;
    cout<<min(sol,solT);
    return 0;
}
