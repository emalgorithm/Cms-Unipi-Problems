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

int n, v[6] = {1,2,3,4,5,6};

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin>>n;
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        if(c == 'X'){
            int f = v[0], s = v[1], t = v[4], q = v[5];
            v[0] = t; v[1] = f; v[4] = q; v[5] = s;
        }
        if(c == 'Y'){
            int f = v[0], s = v[2], t = v[3], q = v[5];
            v[0] = s; v[2] = q; v[3] = f; v[5] = t;
        }
        if(c == 'Z'){
            int f = v[2], s = v[1], t = v[4], q = v[3];
            v[2] = s; v[1] = q; v[4] = f; v[3] = t;
        }
        if(c == 'T')
            cout<<v[0]<<" ";
        if(c == 'F')
            cout<<v[1]<<" ";
        if(c == 'R')
            cout<<v[2]<<" ";
    }
    return 0;

}

