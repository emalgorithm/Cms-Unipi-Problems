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

int n;
string a, s;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n>>a;
    for(int i=0;i<n;i++){
        if(i < n - 3 && a.substr(i, 4) == "TuNZ"){
            if(!s.empty() && s.back() != ' ')
                s.push_back(' ');
            i += 3;
        }
        else if(i < n - 2 && a.substr(i, 3) == "PaH"){
            if(!s.empty() && s.back() != ' ')
                s.push_back(' ');
            i += 2;
        }
        else
            s.push_back(a[i]);
    }
    cout<<s;

    return 0;
}
