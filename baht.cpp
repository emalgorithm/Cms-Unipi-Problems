#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <utility>
#include <stdio.h>
#include <queue>
#include <fstream>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <bitset>
#include <string.h>
 
#define MAX_N 10005
 
#define N_CHAR 130
 
using namespace std;
 
typedef pair<int, int> ii ;
typedef vector< ii >   vii ;
typedef vector<int> vi ;
 
int t, n, coins[MAX_N];
 
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    scanf("%d",&t);
    
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",coins+i);
        sort(coins,coins+n);
        int curr = 0, sol = 1;
        for(int i=0;i<n;i++){
            if(coins[i] <= curr + 1)
                curr += coins[i];
            else
                break;
        }  
        printf("%d\n",curr + 1);
    }

    return 0;
}

// 2 7 10 2 14 1 13 2 3 9 1 16 2 1 23 18 1 4 3


















