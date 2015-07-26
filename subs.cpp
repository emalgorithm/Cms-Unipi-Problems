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
#include <bitset>
#include <string.h>
 
#define MAX_N 1000001
#define INF 99999999
#define N_CHAR 130
 
using namespace std;
 
typedef pair<int, int> ii ;
typedef vector< ii >   vii ;
typedef vector<int> vi ;

int N,sol;
char S[MAX_N];

int main() {
    
    #ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    scanf("%d",&N);
    scanf("%s",S);
    for(int i=1;i<N;i++){
        //cout<<S[i]<<" "<<S[sol]<<" "<<(S[i]>S[sol]);
        //cout<<S[sol]<<" "<<sol<<endl;
        if(S[i]>S[sol])
            sol = i;
        else if(S[i] == S[sol]){
            int k = i, j = sol;
            while(k<N && j<N && S[k]>=S[j]){
                if(S[k] > S[sol]){
                    sol = k;
                    break;
                }
                if(S[k] > S[j]){
                    sol = i;
                    break;
                }
                k++; j++;
            }
            i = k;
        }  
        //cout<<sol<<" ";
    }
    printf("%d",sol);
    
    return 0;
}

//4 1 2 2 4 4 3 3 2 4 1 3 1

//7 6 4 2 5 2 6 2 4 3 4 4 4 5 4 6 