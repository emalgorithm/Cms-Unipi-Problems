#include <vector>
#include <string>
#include <string.h>
#include <functional>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <algorithm>

using namespace std;

typedef vector< int > vi;
typedef pair< int, int > ii;
typedef vector< ii > vii;

#define MAX_N 1000005
#define INF 9999999

vi divis[MAX_N],curr;
int prime[MAX_N];
bool cond = true;


void Accendi(int N, int acceso[], int pulsante[]) {
    for(int i=N;i>=1;i--){
        for(int j=2;j*i<=N;j++)
            if(pulsante[j*i])
                acceso[i] = (acceso[i] + 1)%2;
        if(acceso[i] == 0)
            pulsante[i] = (pulsante[i] + 1)%2;
    }
}





