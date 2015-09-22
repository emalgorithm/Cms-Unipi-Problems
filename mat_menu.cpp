/* 
 * File:   main.cpp
 * Author: ema
 *
 * Created on September 21, 2015, 4:41 PM
 */

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
#define MAX_N 5005
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

int n, budget, dishes[MAX_N], dp[MAX_N][MAX_N], sol = INF;

void solve(int budgetLeft, int pos) {
    if(budgetLeft < 0 || pos == n + 1) {
        return;
    }
    if(dp[budgetLeft][pos] != 0) {
        return;
    }
    if(budgetLeft < sol) {
        sol = budgetLeft;
    }
    //cout<<"solve: "<<budgetLeft<<" "<<pos<<endl;
    dp[budgetLeft][pos] = 1;
    int currCost = dishes[pos];
    solve(budgetLeft - currCost, pos + 1);
    solve(budgetLeft, pos + 1);
}

void print(int budgetLeft, int pos) {
    //cout<<"print: "<<budgetLeft<<" "<<pos<<endl;
    for(int i = pos - 1; i >= 0; i--) {
        int currCost = dishes[i];
        if(budgetLeft + currCost < MAX_N) {
            if(dp[budgetLeft + currCost][i] == 1) {
                cout<<currCost<<endl;
                print(budgetLeft + currCost, i);
                return;
            }
        }
    }
}

int main(){
    #ifdef EVAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    
    cin >> n >> budget;
    
    for(int i = 0; i < n; i++) {
        cin >> dishes[i];
    }
    solve(budget, 0);
    print(sol, n);

    return 0;
}
