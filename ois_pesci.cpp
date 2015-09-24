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
    for(int i=0;i<n;i++){
        int t,t2;
        cin>>t>>t2;
        if(t)
            s.push_back(t2);
        else
            d.push_back(t2);

        while(!d.empty() && !s.empty()){
            if(d.back() < s.back())
                d.pop_back();
            else
                s.pop_back();
        }
        while(d.empty() && !s.empty()){
            s.pop_back();
            sol++;
        }
    }
    cout<<max(s.size(),d.size())+sol;
    return 0;
}
