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
#define MAX_N 2005
#define MOD int(1e9)+7

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;  

int lower = 1, upper, sol;

int main(){
    #ifdef EVAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    
    cin >> upper;
    for(int i = 1; i <= upper; i++) {
        if(i % lower == 0 && upper % i == 0) {
            sol++;
            lower = i;
        }
    }
    cout<<sol;
    return 0;
}
