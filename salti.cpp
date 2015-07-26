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
#include <math.h>
#include <string.h>
#include <stdlib.h> 

using namespace std;

typedef pair<int, int> ii ;
typedef vector< ii >   vii ;
typedef vector<int> vi ;
typedef vector<vi> vvi; 
typedef pair< int, string > is;

#define pb push_back 
#define MAX_N 2000005
 
int n,counter;


int main() {
    
    #ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    scanf("%d",&n);
    
    for(int i=0;i<=31;i++)
        if(1 << i & n)
            counter++;
    
    printf("%d",counter);
    return 0;
}

//7 -1 2 -1 5 -2 3 -3 1 1 -1 -2 -1 -3 -4