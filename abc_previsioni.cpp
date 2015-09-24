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
#include <math.h>

#define INF 1000000005
#define MAX_N 100005
#define MAX_M 100005
#define MOD int(1e9)+7

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

void readInt(int &n){
    n = 0;
    int ch = getchar_unlocked();
    int sign = 1;
    while(ch < '0' || ch > '9'){
        if(ch == '-') 
            sign = -1; 
        ch = getchar_unlocked();
    }

    while(ch >= '0' && ch <= '9'){
            n = (n << 3) + (n << 1) + ch - '0';
            ch = getchar_unlocked();
    }
    n *= sign;
}   

long long n;
vector<int> previsioni;

void solve(long long day){
    if(day == 1)
        cout<<"P";
    else if(day == 2 || day == 3)
        cout<<"S";
    else{
        vi::iterator value = lower_bound(previsioni.begin(), previsioni.end(), day);
        int pos = value - previsioni.begin();
        long long prec = previsioni[pos-1];
        if(day == prec + 1)
            cout<<"P";
        else if(day >= prec+2 && day <= prec+pos+3)
            cout<<"S";
        else 
            solve(day-(previsioni[pos]-previsioni[pos-1]));
    }
}

int main(){
    #ifdef EVAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    long long x = 3, t = 1;
    while(x <= 2*(int)(1e9)){
        previsioni.push_back(x);
        x = 2*x+3+t++;
    }

    cin>>n;

    solve(n);

    return 0;
}
