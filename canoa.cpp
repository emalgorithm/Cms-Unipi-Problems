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

int n, k;
vii v;

int main(){

#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    scanf("%d %d", &n, &k);

    for(int i = 0;i < n; i++){
        int f, p;
        scanf("%d %d", &f, &p);
        int value = f - (3 * p / 2);
        v.push_back(ii(value, i));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for(int i = 0; i < k; i++)
        printf("%d\n", v[i].second + 1);
    return 0;
}

