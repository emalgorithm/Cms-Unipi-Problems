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

int n;
vi normal, reversed;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &n);

    bool isValid = true;
    int digits = 0;

    if(n == 0){
        printf("%d",n);
        return 0;
    }
    
    while(n != 0){
        int r = n % 10;
        normal.push_back(r);
        if(r == 4 || r == 3 || r == 7)
            isValid = false;
        if(r == 6)
            r = 9;
        else if(r == 9)
            r = 6;
        reversed.push_back(r);
        n /= 10;
        digits ++;
    }

    if(reversed[0] == 0)
        isValid = false;

    reverse(normal.begin(), normal.end());

    int smaller = 0, pos = 0;
    while(pos < digits && normal[pos] == reversed[pos]){
        pos++;
    }

    if(normal[pos] > reversed[pos])
        smaller = 1;

    if(smaller == 0 || isValid == false){
        for(int i=0;i<digits;i++)
            printf("%d", normal[i]);
    }
    else{
        for(int i=0;i<digits;i++)
            printf("%d", reversed[i]);
    }


    return 0;
}

