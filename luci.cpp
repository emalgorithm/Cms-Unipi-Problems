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

int n, m, k;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin>>n;
    int s = sqrt(n);
    cout<<n-s;
    return 0;
}

