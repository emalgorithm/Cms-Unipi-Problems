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

int n, k, v[MAX_N], st[MAX_N];

void build(int p, int L, int R){
    if(L == R){
        st[p] = L;
        return;
    }
    build(2*p, L, (L+R)/2);
    build(2*p+1, (L+R)/2+1, R);
    st[p] = (v[st[2*p]] <= v[st[2*p+1]]) ? st[2*p] : st[2*p+1];
}

int query(int p, int L, int R, int i, int j){
    if(L > j || R < i)
        return INF;
    if(L >= i && R <= j)
        return st[p];
    int r1 = query(2*p, L, (L+R)/2, i, j);
    int r2 = query(2*p+1, (L+R)/2+1, R, i, j);
    if(r1 == INF)
        return r2;
    if(r2 == INF)
        return r1;
    return (v[r1] <= v[r2] ? r1 : r2);
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>v[i];

    build(1,0,n-1);

    int p = 0;
    while(k > 0 && p < n){
        int posMin = query(1,0,n-1,p,min(n-1,p+k));
        for(int i=p;i<posMin;i++)
            v[i] = -1;
        k -= posMin-p;
        p = posMin + 1;
    }

    for(int i=n-1;k>0 && i>=0;i--)
        if(v[i] != -1){
            v[i] = -1;
            k--;
        }

    for(int i=0;i<n;i++)
        if(v[i] != -1)
            cout<<v[i]<<" ";
    return 0;
}
