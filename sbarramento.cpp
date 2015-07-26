#include <cstdlib>
#include <iostream>
#include <utility>
#include <algorithm>
#include <assert.h>

using namespace std;

int readInt(){
    int n = 0;
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
    return n;
}   


int n, r, sol, firstFree = 0, m[505][505];

int main(){

#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	
    n = readInt(); r = readInt();
    r--;

    for(int i=0;i<n;i++){
        int t = readInt(), t2 = readInt();
        t--; t2--;
        m[t][t2] = 1;
        sol += abs(r - t);
    }
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(m[j][i])
                sol += abs(i - firstFree++);

    cout<<sol;

    return 0;
}

