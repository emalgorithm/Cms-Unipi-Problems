#include <stdio.h>
#include <vector>

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

class FenwickTree {

private:
    vi ft;

    int LSOne(int x) {
        return (x & (-x));
    }

public:
    FenwickTree(int n) {
        ft.assign(n + 1, 0);
    }

    int rsq(int x) {
        int sum = 0;
        for(int i = x; i > 0; i -= LSOne(i)){
            sum += ft[i];
        }
        return sum;
    }

    void adjust(int pos, int value) {
        for(int i = pos; i < ft.size(); i += LSOne(i)){
            ft[i] += value;
        }
    }

};


int n;
long long sol;

int main(){
    #ifdef EVAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    readInt(n);

    FenwickTree ft(int(1e7));

    for(int i = 0; i < n; i++){
        int t;
        readInt(t);
        t = int(1e7) - t;
        sol += ft.rsq(t);
        ft.adjust(t, 1);
    }

    printf("%lld ", sol);

    return 0;
}
