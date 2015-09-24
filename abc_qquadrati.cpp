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

int n, pr[MAX_N];
vi sq;

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;

    for(int i = 0; i * i <= 33000; i++){
        sq.push_back(i*i);
        pr[i*i] = 1;
    }

    for(int i = 0; i < n; i++){
        int t, sol = 0; cin >> t;
        int sz = sq.size();
        for(int j = 0; j < sz; j++)
            for(int k = j; sq[j] <= t && k < sz; k++)
                for(int m = k; sq[j] + sq[k] <= t &&  m < sz; m++)
                    if(sq[j] + sq[k] + sq[m] <= t && t - (sq[j] + sq[k] + sq[m]) >= sq[m] && pr[t - (sq[j] + sq[k] + sq[m])])
                            sol ++;
        cout << sol << " ";
    }

    return 0;
}

