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

int n;

int main(){
    #ifdef EVAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

   	scanf("%d\n", &n);
    
    int minim = 1, maxim = n;

    for(int i = 0; i < n - 1; i++){
        char c;
        scanf("%c", &c);
        if(c == '<')
            printf("%d ", minim++);
        else
            printf("%d ", maxim--);
    }

    printf("%d", minim);

    return 0;
}
