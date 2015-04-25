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
#define MAX_N 200005
int ContaOperazioni(int N,int K, int* secchi){
    int ecc = 0, dif = 0;
    for(int i=0;i<N;i++){
        if(secchi[i] - K < 0)
            dif += K - secchi[i];
        else
            ecc += secchi[i] - K;
    }
    return max(dif, ecc);
}

/*int main() {
    int N,K,secchi[100000];
    cin>>N>>K;
    for(int i=0;i<N;i++)
        cin>>secchi[i];
    cout<<ContaOperazioni(N,K,secchi);
    
    return 0;
}*/

//2 7 10 2 14 1 13 2 3 9 1 16 2 1 23 18 1 4 3