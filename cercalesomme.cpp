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
#define MAX_N 10
#define MOD int(1e9)+7

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

int n, sum, c[MAX_N], p[MAX_N];;

void ric(int pos){
    if(pos >= n - 1 || p[pos] >= n)
        return;
    int firstZP = n;
    for(int i = 0; i < n; i++)
        if(p[i] == 0){
            p[i] = n;
            firstZP = i;
            break;
        }

    int tot = 0, posCur = 0, sTemp = 0, ind = 0;
    for(int i = 0; i < firstZP + 1; i++){
        while(posCur < p[i]){
            sTemp *= 10;
            sTemp += c[posCur];
            posCur++;
        }
        tot += sTemp;
        sTemp = 0;
    }
    if(tot == sum){
            for(int i = 0; i < firstZP; i++)
                cout<<p[i]<<" ";
            cout<<endl;
    }
    p[firstZP] = 0;
    
    p[pos]++;
    ric(pos);
    p[pos]--;

    p[pos + 1] = p[pos] + 1;
    ric(pos + 1);
    p[pos + 1] = 0;
}

int main(){
    #ifdef EVAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);

    cin>>n;

    for(int i = 0; i < n; i++)
        cin>>c[i];
    cin>>sum;
    ric(0);
    return 0;
}
