#include <stdio.h>
#include <algorithm>
#include <vector>

#define MAX_N 15005

using namespace std;

typedef vector<int> vi;

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

int n;
long long sol;
vi v;

int main(){
    #ifdef EVAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    readInt(n);

    for(int i = 0; i < n; i++){
        int t;
        readInt(t);
        v.push_back(t);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        int ind = n - 2;
        for(int j = n - 1; j >= 0 && v[j] > 2 * v[i]; j--){
            int left = v[j] - v[i] - 1;
            while(ind > 0 && v[ind] > left)
                ind--;
            int add = ind - i;
            sol += add;
        }
    }
    
    printf("%lld", sol);
    return 0;
}
