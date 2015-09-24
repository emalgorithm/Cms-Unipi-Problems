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

int n, sol, v[MAX_N];
vi d,s; 


int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    cin>>n;
    for(int i=0;i<2*n-1;i++){
        int t;
        cin>>t;
        d.push_back(t);
    }
    sort(d.begin(),d.end());
    for(int i=0;i<d.size()-1;i+=2)
        if(d[i] != d[i+1]){
            cout<<d[i];
            return 0;
        }
    cout<<d.back();
    return 0;
    for(int i=0;i<n;i++){
        int t,t2;
        cin>>t>>t2;
        if(t)
            s.push_back(t2);
        else
            d.push_back(t);
    }
    while(!d.empty() && !s.empty()){
        if(d.back() < s.back())
            d.pop_back();
        else
            s.pop_back();
    }
    cout<<max(s.size(),d.size());
    return 0;
}
